#pragma once
#include "GameNode.h"
#include "DeviceManager.h"
#include "RMModel.h"
#include "ModelLoader.h"
#include "textclass.h"
#include "cpuclass.h"
#include "lightclass.h"
#include "lightshaderclass.h"
#include "modelclass.h"
#include "ParticleSystemClass.h"
#include "ParticleShaderClass.h"
#include "Skybox.h"

#include "refractionshaderclass.h"
#include "watershaderclass.h"
#include "rendertextureclass.h"
#include "FogShaderClass.h"
#include "Player.h"

class TestScene : public GameNode
{
private:
	ModelLoader* modelLoader;
	SkinModel* skinModel;
	TextClass* m_Text;
	CpuClass* m_Cpu;

	Player* player;

	Skybox* skybox;
	LightShaderClass* m_LightShader;
	LightClass* m_Light;
	LightClass* m_Light1, * m_Light2, * m_Light3, * m_Light4;
	ModelClass* myModel;
	ParticleShaderClass* m_ParticleShader;
	ParticleSystemClass* m_ParticleSystem;
	
	ModelClass* Island;
	ModelClass* BigTree;
	ModelClass* TreeHouse;
	ModelClass* MintTree;
	ModelClass* MintTree2;
	ModelClass* PurpleTree;
	ModelClass* FlowerTree;
	ModelClass* YellowTree;
	ModelClass* YellowTree2;
	ModelClass* BigYellowTree;
	ModelClass* RoundTree;
	ModelClass* RoundTree2;
	ModelClass* RoundTree3;
	ModelClass* Trees;
	ModelClass* PalmTree;
	ModelClass* PalmTree2;
	ModelClass* PalmTree3;
	ModelClass* PalmTree4;
	ModelClass* PalmTree5;
	ModelClass* PalmTree6;
	ModelClass* PalmTree7;
	ModelClass* PalmTree8;
	ModelClass* PalmTree9;
	ModelClass* Stone;
	ModelClass* Stone2;
	ModelClass* Stone3;
	ModelClass* Water;

	//another floating island for fog effect
	ModelClass* Top;
	ModelClass* Bottom;

	RenderTextureClass* m_RefractionTexture, * m_ReflectionTexture;
	RefractionShaderClass* m_RefractionShader;
	WaterShaderClass* m_WaterShader;
	bool RenderRefractionToTexture(ID3D11DeviceContext* dc);
	bool RenderReflectionToTexture(ID3D11DeviceContext* dc);
	float m_waterHeight, m_waterTranslation;

	FogShaderClass* m_FogShader;

public:
	HRESULT Init(void);
	void Update(void);
	void Render(ID3D11DeviceContext* dc);

	TestScene() {}
	~TestScene() {}
};

