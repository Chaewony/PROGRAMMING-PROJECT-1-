#include "Player.h"

Player::Player()
{
	_position = XMFLOAT3(0.f, 0.f, 0.f);
	_rotation = XMFLOAT3(0.f, 0.f, 0.f);

	_speed = 10.f;
	_mouseSpeed = 10.f;

	modelLoader = new ModelLoader;
	skinModel = new SkinModel;

	skinModel = modelLoader->LoadModel(L"./data/character.fbx", aiProcess_Triangulate |
		aiProcess_ConvertToLeftHanded);
	modelLoader->LoadAnimation(L"./data/Idle_24.fbx", skinModel, aiProcess_Triangulate |
		aiProcess_ConvertToLeftHanded);
	modelLoader->LoadAnimation(L"./data/anim_joyfuljump.fbx", skinModel, aiProcess_Triangulate |
		aiProcess_ConvertToLeftHanded);
	modelLoader->LoadAnimation(L"./data/Running30.fbx", skinModel, aiProcess_Triangulate |
		aiProcess_ConvertToLeftHanded);
	modelLoader->LoadAnimation(L"./data/Walking30.fbx", skinModel, aiProcess_Triangulate |
		aiProcess_ConvertToLeftHanded);
	modelLoader->LoadAnimation(L"./data/01Attack.fbx", skinModel, aiProcess_Triangulate |
		aiProcess_ConvertToLeftHanded);

	skinModel->GetAnimation(5).SetRepeat(true);
	skinModel->LoadTexture(L"./data/character_d.dds");
	skinModel->SetNormalize(true);
}

void Player::SetPosition(float x, float y, float z)
{
	//player ��ü ��ġ
	_position.x = x;
	_position.y = y;
	_position.z = z;
	//player �޽� ��ġ
	skinModel->SetCenter(_position);
	return;
}

void Player::SetRotation(float x, float y, float z) 
{
	_rotation.x = x;
	_rotation.y = y;
	_rotation.z = z;

	skinModel->SetRotate(_rotation);

	return;
}

XMVECTOR Player::GetPosition()
{
	return XMLoadFloat3(&_position);
}

XMVECTOR Player::GetRotation()
{
	return XMLoadFloat3(&_rotation);
}

void Player::Update(float duration)
{
	float yaw, pitch, roll;
	XMFLOAT3 up, lookAt;
	XMMATRIX rotationMatrix;

	up = XMFLOAT3(0.f, 1.f, 0.f);
	lookAt = XMFLOAT3(0.f, 0.f, 1.f);

	pitch = _rotation.x * 0.0174532925f;
	yaw = _rotation.y * 0.0174532925f;
	roll = _rotation.z * 0.0174532925f;

	//ȸ�� ������ ī�޶� ȸ�� ��� ����
	rotationMatrix = XMMatrixRotationRollPitchYaw(pitch, yaw, roll);

	//ī�޶� up ����, LookAtVector ���� ȸ��
	XMVECTOR upVec = XMVector3TransformCoord(XMLoadFloat3(&up), rotationMatrix);
	XMVECTOR lookAtVec = XMVector3TransformCoord(XMLoadFloat3(&lookAt), rotationMatrix);
	_lookAtVec = lookAtVec;

	//LookAtVector�� �̵����Ϳ� ���� �� ����
	lookAtVec = XMLoadFloat3(&_position) + lookAtVec;
}

void Player::MouseInput()
{
	_rotation.x = INPUTMANAGER.GetPitch();
}

void Player::KeyboardInput(float duration)
{
	//��ġ����, ī�޶� ���⺤��, �� ����
	XMVECTOR posVec = XMLoadFloat3(&_position);
	XMVECTOR moveVec = XMVector3Normalize(_lookAtVec);
	XMVECTOR upVec = XMVectorSet(0.f, 1.f, 0.f, 0.f);

	if (INPUTMANAGER.GetVertical()==1.f) { //��
		posVec += (moveVec * duration * _speed);
	} 
	else if (INPUTMANAGER.GetVertical()==-1.f) { //��
		posVec -= (moveVec * duration * _speed);
	}

	if (INPUTMANAGER.GetHorizontal()==-1.f) { //��
		posVec -= XMVector3Cross(upVec, moveVec) * duration *  _speed;
	}
	else if (INPUTMANAGER.GetHorizontal() == 1.f) { //��
		posVec += XMVector3Cross(upVec, moveVec) * duration * _speed;
	}

	/*if (KEYMANAGER.IsStayKeyDown('Q')) {
		posVec -= (upVec * duration * _speed);
	}
	else if (KEYMANAGER.IsStayKeyDown('E')) {
		posVec += (upVec * duration * _speed);
	}*/

	//�̵��� ���� ��ġ ����
	XMStoreFloat3(&_position, posVec);
}
