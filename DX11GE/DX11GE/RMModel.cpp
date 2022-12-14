#include "pch.h"
#include "RMModel.h"
#include "SkinModel.h"
#include "./ModelLoader.h"

//���� �ε��Ѵ�.
SkinModel * RMModel::loadResource(wstring fileName, void * param)
{
	unsigned int flag = 0;

	//�Ķ���Ͱ� ���� �� �⺻ �÷���
	if (!param) {
		flag =  aiProcess_ConvertToLeftHanded | aiProcess_GenNormals | aiProcess_CalcTangentSpace;
	}
	else {
		flag =  *(unsigned int*)param;
	}
	

	//�𵨷ε�
	ModelLoader load;
	return load.LoadModel(fileName.c_str(), flag);
}

//�� ����
void RMModel::releaseResource(SkinModel * data)
{
	SAFE_RELEASE(data);
}
