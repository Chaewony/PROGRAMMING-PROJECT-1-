//==================================================================
//		## Camera ## (Camera)
//==================================================================
#pragma once

class Camera
{
public:
	Camera();
	Camera(const Camera&);
	~Camera();

	//Set Function
	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	//Get Function
	XMVECTOR GetPosition();
	XMVECTOR GetRotation();
	XMFLOAT3 GetPositionF() { return _position; }
	XMVECTOR GetDirection() { return XMVector3Normalize(_lookAtVec); }

	//Camera Update
	XMMATRIX Update(float duration);

	//화면에서 카메라 방향 레이계산
	Ray ComputeRay(XMFLOAT2 screenPos, D3D11_VIEWPORT viewPort, XMMATRIX matProj);

	//Interrupt Event
//	void DeviceInput(float duration);
	void MouseInput();
	void KeyboardInput(float duration);

	void RenderReflection(float);
	XMMATRIX GetReflectionViewMatrix();

private:
	//이동, 회전 속도
	float _speed, _mouseSpeed;

	//위치, 회전 값
	XMFLOAT3	_position, _rotation;


	XMVECTOR _lookAtVec;		//direction
	XMMATRIX _viewMatrix;		//viewMat

	XMMATRIX m_reflectionViewMatrix;
};
