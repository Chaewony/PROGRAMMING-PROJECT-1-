#pragma once
#include "ModelLoader.h"
#include "SkinModel.h"

class Player
{
public:
	Player();
	~Player() {}
	//Camera Update
	void Update(float duration);
	SkinModel* skinModel;

	XMVECTOR GetLookAt() { return _lookAtVec; }

private:
	ModelLoader* modelLoader;
	

	//�̵�, ȸ�� �ӵ�
	float _speed, _mouseSpeed;

	//��ġ, ȸ�� ��
	XMFLOAT3	_position, _rotation;

	XMVECTOR _lookAtVec;		//direction

	//Set Function
	void SetPosition(float, float, float);
	void SetRotation(float, float, float);

	//Get Function
	XMVECTOR GetPosition();
	XMVECTOR GetRotation();
	XMFLOAT3 GetPositionF() { return _position; }

	void MouseInput();
	void KeyboardInput(float duration);

};

