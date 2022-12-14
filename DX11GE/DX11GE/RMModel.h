//=============================================================
//	## RMModel ## (�ε�� �𵨸� ���� ������ �����Ѵ�.)
//=============================================================
#pragma once
#include "ResourceManager.h"
class SkinModel;

class RMModel : public ResourceManager < SkinModel*, RMModel >
{
public:
	RMModel() {};
	~RMModel() {};

	//�� �ε�
	SkinModel* loadResource(wstring fileName, void* param= nullptr);

	//�� ����
	void releaseResource(typename SkinModel*data);
};
