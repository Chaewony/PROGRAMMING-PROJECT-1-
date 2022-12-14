#pragma once
#include "pch.h"
//==================================================================
//		## gameNode Interface ## 
//==================================================================
class GameNode
{
public:
	//Render View Info
	static PWindowRender _sceneInfo;

	
public:
	virtual HRESULT Init(void) { return S_OK; };
	virtual void Release(void) {};
	virtual void Update(void) {};
	virtual void Render(ID3D11DeviceContext* dc) {};

	GameNode() {}
	virtual ~GameNode() {}
};

