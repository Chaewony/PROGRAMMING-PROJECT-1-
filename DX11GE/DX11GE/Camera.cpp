#include "pch.h"
#include "Camera.h"


Camera::Camera()
{
	_position = XMFLOAT3(0.f, 0.f, 0.f);
	_rotation = XMFLOAT3(0.f, 0.f, 0.f);

	_speed = 10.f;
	_mouseSpeed = 10.f;
}


Camera::Camera(const Camera& other)
{
}


Camera::~Camera()
{
}

//��ġ �� ����
void Camera::SetPosition(float x, float y, float z)
{
	
	_position.x = x;
	_position.y = y;
	_position.z = z;
	return;
}

//ȸ�� �� ����
void Camera::SetRotation(float x, float y, float z)
{
	_rotation.x = x;
	_rotation.y = y;
	_rotation.z = z;
	return;
}

//��ġ ��� ��ȯ
XMVECTOR Camera::GetPosition()
{
	return XMLoadFloat3(&_position);
}


//ȸ�� ��� ��ȯ
XMVECTOR Camera::GetRotation()
{
	return XMLoadFloat3(&_rotation);
}

//�� ��� ������Ʈ
XMMATRIX Camera::Update(float duration)
{
	float yaw, pitch, roll;
	XMFLOAT3 up,  lookAt;
	XMMATRIX rotationMatrix;

	up = XMFLOAT3(0.f, 1.f, 0.f);
	lookAt = XMFLOAT3(0.f, 0.f, 1.f);

	pitch = _rotation.x * 0.0174532925f;
	yaw   = _rotation.y * 0.0174532925f;
	roll  = _rotation.z * 0.0174532925f;

	//ȸ�� ������ ī�޶� ȸ�� ��� ����
	rotationMatrix = XMMatrixRotationRollPitchYaw(pitch, yaw, roll);

	//ī�޶� up ����, LookAtVector ���� ȸ��
	XMVECTOR upVec = XMVector3TransformCoord(XMLoadFloat3(&up), rotationMatrix);
	XMVECTOR lookAtVec = XMVector3TransformCoord(XMLoadFloat3(&lookAt), rotationMatrix);
	_lookAtVec = lookAtVec;

	//LookAtVector�� �̵����Ϳ� ���� �� ����
	lookAtVec = XMLoadFloat3(&_position) + lookAtVec;

	//�� ��� �����
	_viewMatrix = XMMatrixLookAtLH(XMLoadFloat3(&_position), lookAtVec, upVec);

	return _viewMatrix;
}


//���� ���� ���
Ray Camera::ComputeRay(XMFLOAT2 screenPos, D3D11_VIEWPORT viewPort, XMMATRIX matProj)
{
	//��ũ���� ��ġ ������ ���
	float factorX = screenPos.x / viewPort.Width;
	float factorY = (1.0f - (screenPos.y / viewPort.Height));

	//0 ~ 1 => -1 ~ 1
	factorX = factorX * 2.0f - 1.0f;
	factorY = factorY * 2.0f - 1.0f;


	//[1][][][]
	//[][1][][]
	//[][][1][]
	//[0][0][0][]
	//ȭ�� �����Ϸ��� ������


	XMFLOAT4X4 proj;
	XMStoreFloat4x4(&proj, matProj);
	XMFLOAT4 tmp;
	tmp.x = factorX / proj._11;
	tmp.y = factorY / proj._22;
	tmp.z = 1.0f;
	tmp.w = 0.0f;
	XMVECTOR rayDirection = XMLoadFloat4(&tmp);

	//ī�޶� ���� ���
	XMMATRIX invView = XMMatrixInverse(nullptr, _viewMatrix);

	//������ ������ ī�޶� ����������� ����Ѵ�
	rayDirection = XMVector4Transform(rayDirection, invView);

	//���⺤�� ����ȭ
	rayDirection = XMVector4Normalize(rayDirection);

	//Ray�� ����
	XMFLOAT3 direction;
	XMStoreFloat3(&direction, rayDirection);

	return Ray{_position, direction};
}



//�Է� �̺�Ʈ
//void Camera::DeviceInput(float duration)
//{
//	MouseInput(duration);
//	KeyboardInput(duration);
//}


//���콺
void Camera::MouseInput()
{
	_rotation.x = INPUTMANAGER.GetPitch();
	_rotation.y = INPUTMANAGER.GetYaw();
}


//Ű���带 �̿��� ī�޶� ��ġ ����
void Camera::KeyboardInput(float duration)
{
	//��ġ����, ī�޶� ���⺤��, �� ����
	XMVECTOR posVec = XMLoadFloat3(&_position);
	XMVECTOR moveVec = XMVector3Normalize(_lookAtVec);
	XMVECTOR upVec = XMVectorSet(0.f, 1.f, 0.f, 0.f);



	//if (INPUTMANAGER.GetVertical()==1.f) { //��
	//	posVec += (moveVec * duration * _speed);
	//} 
	//else if (INPUTMANAGER.GetVertical()==-1.f) { //��
	//	posVec -= (moveVec * duration * _speed);
	//}

	//if (INPUTMANAGER.GetHorizontal()==-1.f) { //��
	//	posVec -= XMVector3Cross(upVec, moveVec) * duration *  _speed;
	//}
	//else if (INPUTMANAGER.GetHorizontal() == 1.f) { //��
	//	posVec += XMVector3Cross(upVec, moveVec) * duration * _speed;
	//}

	/*if (KEYMANAGER.IsStayKeyDown('Q')) {
		posVec -= (upVec * duration * _speed);
	}
	else if (KEYMANAGER.IsStayKeyDown('E')) {
		posVec += (upVec * duration * _speed);
	}*/

	//�̵��� ���� ��ġ ����
	XMStoreFloat3(&_position, posVec);

}

void Camera::RenderReflection(float height)
{
	XMVECTOR up, position, lookAt;
	float radians;

	XMFLOAT3 fposition;
	fposition.x = _position.x;
	fposition.y = -_position.y + (height * 2.0f);
	fposition.z = _position.z;

	// Setup the vector that points upwards.
	up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);

	// Setup the position of the camera in the world.
	// For planar reflection invert the Y position of the camera.
	position = XMLoadFloat3(&fposition);

	// Calculate the rotation in radians.
	radians = _position.y * 0.0174532925f;

	// Setup where the camera is looking.
	XMFLOAT3 flookAt;
	flookAt.x = sinf(radians) + _position.x;;
	flookAt.y = fposition.y;
	flookAt.z = cosf(radians) + _position.z;
	lookAt = XMLoadFloat3(&flookAt);

	// Create the view matrix from the three vectors.
	m_reflectionViewMatrix = XMMatrixLookAtLH(position, lookAt, up);

	return;
}

XMMATRIX Camera::GetReflectionViewMatrix()
{
	return m_reflectionViewMatrix;
}
