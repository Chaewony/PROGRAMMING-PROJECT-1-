#include "pch.h"
#include "TestScene.h"



HRESULT TestScene::Init(void)
{
	ID3D11Device* device = DEVICEMANAGER.GetDevice();

	//light
	{
		m_LightShader = new LightShaderClass;
		m_LightShader->Initialize(device, _hWnd);

		m_Light = new LightClass;
		m_Light->SetAmbientColor(0.5f, 0.5f, 0.5f, 1.0f);
		m_Light->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
		m_Light->SetDirection(0.5f, -0.8f, 0.5f);
		m_Light->SetSpecularColor(1.0f, 1.0f, 1.0f, 1.0f);
		m_Light->SetSpecularPower(32.0f);

		// Create the first light object.
		m_Light1 = new LightClass;

		// Initialize the first light object.
		m_Light1->SetDiffuseColor(1.0f, 0.0f, 0.0f, 1.0f);
		m_Light1->SetPosition(-10.0f, 1.0f, -10.0f);

		// Create the second light object.
		m_Light2 = new LightClass;

		// Initialize the second light object.
		m_Light2->SetDiffuseColor(0.0f, 1.0f, 0.0f, 1.0f);
		m_Light2->SetPosition(10.0f, 1.0f, 3.0f);

		// Create the third light object.
		m_Light3 = new LightClass;

		// Initialize the third light object.
		m_Light3->SetDiffuseColor(0.0f, 0.0f, 1.0f, 1.0f);
		m_Light3->SetPosition(0.0f, 1.0f, 0.0f);

		// Create the fourth light object.
		m_Light4 = new LightClass;

		// Initialize the fourth light object.
		m_Light4->SetDiffuseColor(1.0f, 1.0f, 1.0f, 1.0f);
		m_Light4->SetPosition(3.0f, 1.0f, -3.0f);
	}
	
	//model - not animated
	{
		myModel = new ModelClass;
		myModel->Initialize(device, L"./data/test_ground4.obj", L"./data/ground_d.dds");

		Island = new ModelClass;
		Island->Initialize(device, L"./data/environment/island.obj", L"./data/environment/island_d.dds");

		BigTree = new ModelClass;
		BigTree->Initialize(device, L"./data/environment/bigtree.obj", L"./data/environment/bigtree_d.dds");

		TreeHouse = new ModelClass;
		TreeHouse->Initialize(device, L"./data/environment/treehouse.obj", L"./data/environment/treehouse_d.dds");

		MintTree = new ModelClass;
		MintTree->Initialize(device, L"./data/environment/minttree.obj", L"./data/environment/minttree_d.dds");
		MintTree2 = new ModelClass;
		MintTree2->Initialize(device, L"./data/environment/minttree2.obj", L"./data/environment/minttree_d.dds");

		PurpleTree = new ModelClass;
		PurpleTree->Initialize(device, L"./data/environment/purpletree.obj", L"./data/environment/purpletree_d.dds");

		FlowerTree = new ModelClass;
		FlowerTree->Initialize(device, L"./data/environment/flowertree.obj", L"./data/environment/flowertree_d.dds");

		YellowTree = new ModelClass;
		YellowTree->Initialize(device, L"./data/environment/yellowtree.obj", L"./data/environment/yellowtree_d.dds");
		YellowTree2 = new ModelClass;
		YellowTree2->Initialize(device, L"./data/environment/yellowtree2.obj", L"./data/environment/yellowtree_d.dds");
		BigYellowTree = new ModelClass;
		BigYellowTree->Initialize(device, L"./data/environment/bigyellowtree.obj", L"./data/environment/yellowtree_d.dds");

		RoundTree = new ModelClass;
		RoundTree->Initialize(device, L"./data/environment/roundtree.obj", L"./data/environment/roundtree_d.dds");
		RoundTree2 = new ModelClass;
		RoundTree2->Initialize(device, L"./data/environment/roundtree2.obj", L"./data/environment/roundtree_d.dds");
		RoundTree3 = new ModelClass;
		RoundTree3->Initialize(device, L"./data/environment/roundtree3.obj", L"./data/environment/roundtree_d.dds");

		Trees = new ModelClass;
		Trees->Initialize(device, L"./data/environment/trees.obj", L"./data/environment/trees_d.dds");

		PalmTree = new ModelClass;
		PalmTree->Initialize(device, L"./data/environment/palmtree.obj", L"./data/environment/palmtree_d.dds");
		PalmTree2 = new ModelClass;
		PalmTree2->Initialize(device, L"./data/environment/palmtree2.obj", L"./data/environment/palmtree_d.dds");
		PalmTree3 = new ModelClass;
		PalmTree3->Initialize(device, L"./data/environment/palmtree3.obj", L"./data/environment/palmtree_d.dds");
		PalmTree4 = new ModelClass;
		PalmTree4->Initialize(device, L"./data/environment/palmtree4.obj", L"./data/environment/palmtree_d.dds");
		PalmTree5 = new ModelClass;
		PalmTree5->Initialize(device, L"./data/environment/palmtree5.obj", L"./data/environment/palmtree_d.dds");
		PalmTree6 = new ModelClass;
		PalmTree6->Initialize(device, L"./data/environment/palmtree6.obj", L"./data/environment/palmtree_d.dds");
		PalmTree7 = new ModelClass;
		PalmTree7->Initialize(device, L"./data/environment/palmtree7.obj", L"./data/environment/palmtree_d.dds");
		PalmTree8 = new ModelClass;
		PalmTree8->Initialize(device, L"./data/environment/palmtree8.obj", L"./data/environment/palmtree_d.dds");
		PalmTree9 = new ModelClass;
		PalmTree9->Initialize(device, L"./data/environment/palmtree9.obj", L"./data/environment/palmtree_d.dds");

		Stone = new ModelClass;
		Stone->Initialize(device, L"./data/environment/stone.obj", L"./data/environment/yellowtree_d.dds");
		Stone2 = new ModelClass;
		Stone2->Initialize(device, L"./data/environment/stone2.obj", L"./data/environment/yellowtree_d.dds");
		Stone3 = new ModelClass;
		Stone3->Initialize(device, L"./data/environment/stone3.obj", L"./data/environment/yellowtree_d.dds");

		Water = new ModelClass;
		Water->Initialize(device, L"./data/waterwave.obj", L"./data/water_d.dds");
		m_RefractionTexture = new RenderTextureClass;
		m_RefractionTexture->Initialize(device, WINSIZEX, WINSIZEY);
		m_ReflectionTexture = new RenderTextureClass;
		m_ReflectionTexture->Initialize(device, WINSIZEX, WINSIZEY);
		m_WaterShader = new WaterShaderClass;
		m_WaterShader->Initialize(device, _hWnd);
		m_RefractionShader = new RefractionShaderClass;
		m_RefractionShader->Initialize(device, _hWnd);
		// Set the height of the water.
		m_waterHeight = 2.75f;
		// Initialize the position of the water.
		m_waterTranslation = 0.0f;

		m_OutlineShader = new OutlineShaderClass;
		if (!m_OutlineShader->Initialize(device, _hWnd))
		{
			MessageBox(_hWnd, L"Could not initialize the light shader object.", L"Error", MB_OK);
			return false;
		}
	}
	
	//model - another floating island for fog effect
	{
		Top = new ModelClass;
		Top->Initialize(device, L"./data/island/top.obj", L"./data/island/top_d.dds");
		Bottom = new ModelClass;
		Bottom->Initialize(device, L"./data/island/bottom.obj", L"./data/island/bottom_d.dds");

		m_FogShader = new FogShaderClass;
		// 안개 쉐이더 객체를 초기화 합니다.
		m_FogShader->Initialize(device, _hWnd);
	}

	//model - animated
	{
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
		modelLoader->LoadAnimation(L"./data/RunningBackward.fbx", skinModel, aiProcess_Triangulate |
			aiProcess_ConvertToLeftHanded);
		modelLoader->LoadAnimation(L"./data/LeftWalking.fbx", skinModel, aiProcess_Triangulate |
			aiProcess_ConvertToLeftHanded);
		modelLoader->LoadAnimation(L"./data/RightWalking.fbx", skinModel, aiProcess_Triangulate |
			aiProcess_ConvertToLeftHanded);

		skinModel->GetAnimation(5).SetRepeat(true);
		skinModel->LoadTexture(L"./data/character_d.dds");
		skinModel->SetNormalize(true);
		skinModel->SetSize(XMFLOAT3(5.f, 5.f, 5.f));

		player = new Player;
	//	XMFLOAT3 rotation(0, 60, 0);
	//	skinModel->SetRotate(rotation);
	}
	
//	_mainCam.SetPosition(0.0f, 1.0f, -10.0f);
//	_mainCam.SetRotation(0.0f, 180.0f, 0.0f);
	_sceneInfo->viewMatrix = _mainCam.Update(TIMEMANAGER.GetElapedTime());

	//text and cpu
	{
		m_Text = new TextClass;
		m_Text->Initialize(device, DEVICEMANAGER.GetDeviceContext(), _hWnd, WINSIZEX, WINSIZEY, _sceneInfo->viewMatrix);
		m_Cpu = new CpuClass;
		m_Cpu->Initialize();
	}

	//particle
	{
		// 파티클 셰이더 개체를 만듭니다.
		m_ParticleShader = new ParticleShaderClass;
		if (!m_ParticleShader)
		{
			return false;
		}

		// 파티클 셰이더 개체를 초기화합니다.
		if (!m_ParticleShader->Initialize(device, _hWnd))
		{
			MessageBox(_hWnd, L"Could not initialize the particle shader object.", L"Error", MB_OK);
			return false;
		}

		// 파티클 시스템 객체를 만듭니다.
		m_ParticleSystem = new ParticleSystemClass;
		if (!m_ParticleSystem)
		{
			return false;
		}

		// 파티클 시스템 객체를 초기화합니다.
		if (!m_ParticleSystem->Initialize(device, L"./data/star.dds"))
		{
			return false;
		}
	}

	//skybox
	{
		skybox = new Skybox;
		skybox->initialize(DEVICEMANAGER.GetDeviceContext(), device, _hWnd);
	}

	return S_OK;
}

void TestScene::Update(void)
{
	m_Cpu->Frame();
	m_Text->SetFPS(TIMEMANAGER.GetFrameRate(), DEVICEMANAGER.GetDeviceContext());
	m_Text->SetCPU(m_Cpu->GetCpuPercentage(), DEVICEMANAGER.GetDeviceContext());
	m_ParticleSystem->Frame(TIMEMANAGER.GetWorldTime(), DEVICEMANAGER.GetDeviceContext());
	// Update the position of the water to simulate motion.
	m_waterTranslation += 0.001f;
	if (m_waterTranslation > 1.0f)
	{
		m_waterTranslation -= 1.0f;
	}
	player->Update(TIMEMANAGER.GetElapedTime());
}

void TestScene::Render(ID3D11DeviceContext* dc)
{
	//플레이어를 카메라에 바인딩....한건데 솔직히 너무 별로라 바꿔야될듯
	/*XMFLOAT3 direction;
	XMStoreFloat3(&direction, _mainCam.GetPosition());
	direction.y -= 1;
	direction.z += 10;
	skinModel->SetCenter(direction);*/

	//	RM_SHADER.SetShaderParameters(dc, XMMatrixTranslation(0, 0, 1), _sceneInfo->orthoMatrix);
	XMFLOAT4 spotDiffuseColor[4];
	XMFLOAT4 lightPosition[4];

	// Create the diffuse color array from the four light colors.
	spotDiffuseColor[0] = m_Light1->GetDiffuseColor();
	spotDiffuseColor[1] = m_Light2->GetDiffuseColor();
	spotDiffuseColor[2] = m_Light3->GetDiffuseColor();
	spotDiffuseColor[3] = m_Light4->GetDiffuseColor();

	// Create the light position array from the four light positions.
	lightPosition[0] = m_Light1->GetPosition();
	lightPosition[1] = m_Light2->GetPosition();
	lightPosition[2] = m_Light3->GetPosition();
	lightPosition[3] = m_Light4->GetPosition();

	bool result = true;

	result = m_LightShader->Render(dc, skinModel->GetIndexCount(), _sceneInfo->worldMatrix, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix, skinModel->GetTexture(), m_Light->GetDirection(),
		m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(), spotDiffuseColor, lightPosition);

	if (!result)
	{
		return;
	}

//	RM_SHADER.SetShaderParameters(dc, _sceneInfo->viewMatrix, _sceneInfo->projectionMatrix);

	RM_SHADER.SetShaderParameters(dc, _sceneInfo->viewMatrix, _sceneInfo->projectionMatrix);
	skinModel->Render(dc);
	XMFLOAT3 mov(skinModel->GetCenter());
	if (INPUTMANAGER.GetVertical() == 1.f) { //상
		if (!skinModel->GetAnimation(5).isPlaying()) {
			skinModel->PlayAni(3);
			
			mov.x += XMVectorGetX(_mainCam.GetDirection()) * 0.3f;
			mov.y += 0;
			mov.z += XMVectorGetZ(_mainCam.GetDirection()) * 0.3f;
			skinModel->SetCenter(mov);
		}
			
	}
	else if (INPUTMANAGER.GetVertical() == -1.f) { //하
	//	skinModel->PlayAni(5);
		if (!skinModel->GetAnimation(5).isPlaying()) {
			skinModel->PlayAni(6);

			mov.x -= XMVectorGetX(_mainCam.GetDirection()) * 0.3f;
			mov.y += 0;
			mov.z -= XMVectorGetZ(_mainCam.GetDirection()) * 0.3f;
			skinModel->SetCenter(mov);
		}
	}
	else if (INPUTMANAGER.GetHorizontal() == -1.f) { //좌
		if (!skinModel->GetAnimation(5).isPlaying()) {
			skinModel->PlayAni(7);

			mov.x -= XMVectorGetZ(_mainCam.GetDirection()) * 0.3f;
			mov.y += 0;
			mov.z += XMVectorGetX(_mainCam.GetDirection()) * 0.3f;
			skinModel->SetCenter(mov);
		}
	}
	else if (INPUTMANAGER.GetHorizontal() == 1.f) { //우
		if (!skinModel->GetAnimation(5).isPlaying()) {
			skinModel->PlayAni(8);

			mov.x += XMVectorGetZ(_mainCam.GetDirection()) * 0.3f;
			mov.y += 0;
			mov.z -= XMVectorGetX(_mainCam.GetDirection()) * 0.3f;
			skinModel->SetCenter(mov);
		}
	}
	else if (INPUTMANAGER.GetShift() == 1.0f) {
		skinModel->PlayAni(5);
	}
	else {
		if(!skinModel->GetAnimation(5).isPlaying())
			skinModel->PlayAni(1);
	}
	//메시 회전
	XMFLOAT3 playerRotation;
	playerRotation.x = 0;
	playerRotation.y = 180 * 0.0174532925f + XMVectorGetY(_mainCam.GetRotation()) * 0.0174532925f;
	playerRotation.z = 0;
	skinModel->SetRotate(playerRotation);

	//카메라 플레이어에 바인딩
	_mainCam.SetPosition(mov.x - 13*sin(XMVectorGetY(_mainCam.GetRotation()) * 0.0174532925f), mov.y + 8, mov.z -13* cos(XMVectorGetY(_mainCam.GetRotation()) * 0.0174532925f)); //카메라 위치 공식 다시 생각하기
//	_mainCam.SetPosition(mov.x, mov.y + 3, mov.z); //카메라 위치 공식 다시 생각하기

//	player->skinModel->Render(dc);
	/*XMMATRIX world2;
	world2 = _sceneInfo->worldMatrix;
	world2 *= XMMatrixTranslation(0.0f, -1.0f, 0.0f);
	myModel->Render(dc);

	result = m_LightShader->Render(dc, myModel->GetIndexCount(),
		world2, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		myModel->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);*/

//	RenderRefractionToTexture(dc); //문제1 지직거림
//	DEVICEMANAGER.ChangeCullMode(D3D11_CULL_NONE);
//	RenderReflectionToTexture(dc); //문제2 스카이박스 뚫림
//	DEVICEMANAGER.ChangeCullMode(D3D11_CULL_BACK);
//정적 모델들
	//another floating island
	XMMATRIX world;
	static float rotation = 0.0f;
	// Update the rotation variable each frame.
	rotation += XM_PI * 0.0005f;
	if (rotation > 360.0f)
	{
		rotation -= 360.0f;
	}
	world = _sceneInfo->worldMatrix;
//	world *= XMMatrixTranslation(0.0f, -12.5f, 0.0f);
	Top->Render(dc);
	world = XMMatrixRotationY(rotation);
	float fogColor = 0.5f;
	float fogStart = 80.0f;
	float fogEnd = 180;
	m_FogShader->Render(dc, Top->GetIndexCount(), world, _sceneInfo->viewMatrix, _sceneInfo->projectionMatrix,
		Top->GetTexture(), fogStart, fogEnd);
	
	Bottom->Render(dc);
	m_FogShader->Render(dc, Bottom->GetIndexCount(), world, _sceneInfo->viewMatrix, _sceneInfo->projectionMatrix,
		Bottom->GetTexture(), fogStart, fogEnd);

	
	
	//Island
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);

	Island->Render(dc);

	result = m_LightShader->Render(dc, Island->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		Island->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, Island->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			Island->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}
	
	//BigTree
	world = _sceneInfo->worldMatrix;
//	world = XMMatrixRotationY(rotation);
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	BigTree->Render(dc);

	result = m_LightShader->Render(dc, BigTree->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		BigTree->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);


	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, BigTree->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			BigTree->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//TreeHouse
	world = _sceneInfo->worldMatrix;
	static float translation = 0.0f;
	static int dir = 1;
	translation += dir * 0.02f;
	if (translation >= 1.0f)
	{
		dir = -1;
	}
	else if (translation <= 0.0f) {
		dir = 1;
	}

	world *= XMMatrixTranslation(0.0f, -15.0f+ translation, 0.0f);
	TreeHouse->Render(dc);

	result = m_LightShader->Render(dc, TreeHouse->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		TreeHouse->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, TreeHouse->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			TreeHouse->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//MintTree
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	MintTree->Render(dc);

	result = m_LightShader->Render(dc, MintTree->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		MintTree->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, MintTree->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			MintTree->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//MintTree2
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	MintTree2->Render(dc);

	result = m_LightShader->Render(dc, MintTree2->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		MintTree2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, MintTree2->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			MintTree2->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//PurpleTree
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	PurpleTree->Render(dc);

	result = m_LightShader->Render(dc, PurpleTree->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		PurpleTree->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, PurpleTree->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			PurpleTree->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//FlowerTree
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	FlowerTree->Render(dc);

	result = m_LightShader->Render(dc, FlowerTree->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		FlowerTree->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, FlowerTree->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			FlowerTree->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//YellowTree
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	YellowTree->Render(dc);

	result = m_LightShader->Render(dc, YellowTree->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		YellowTree->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, YellowTree->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			YellowTree->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//YellowTree2
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	YellowTree2->Render(dc);

	result = m_LightShader->Render(dc, YellowTree2->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		YellowTree2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, YellowTree2->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			YellowTree2->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}


	//BigYellowTree
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	BigYellowTree->Render(dc);

	result = m_LightShader->Render(dc, BigYellowTree->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		BigYellowTree->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, BigYellowTree->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			BigYellowTree->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//RoundTree
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	RoundTree->Render(dc);

	result = m_LightShader->Render(dc, RoundTree->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		RoundTree->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, RoundTree->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			RoundTree->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//RoundTree2
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	RoundTree2->Render(dc);

	result = m_LightShader->Render(dc, RoundTree2->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		RoundTree2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, RoundTree2->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			RoundTree2->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//RoundTree3
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	RoundTree3->Render(dc);

	result = m_LightShader->Render(dc, RoundTree3->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		RoundTree3->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, RoundTree3->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			RoundTree3->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//Trees
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	Trees->Render(dc);

	result = m_LightShader->Render(dc, Trees->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		Trees->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, Trees->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			Trees->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//PalmTree
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	PalmTree->Render(dc);

	result = m_LightShader->Render(dc, PalmTree->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		PalmTree->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, PalmTree->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			PalmTree->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//PalmTree2
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	PalmTree2->Render(dc);

	result = m_LightShader->Render(dc, PalmTree2->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		PalmTree2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, PalmTree2->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			PalmTree2->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//PalmTree3
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	PalmTree3->Render(dc);

	result = m_LightShader->Render(dc, PalmTree3->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		PalmTree3->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, PalmTree3->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			PalmTree3->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//PalmTree4
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	PalmTree4->Render(dc);

	result = m_LightShader->Render(dc, PalmTree4->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		PalmTree4->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, PalmTree4->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			PalmTree4->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//PalmTree5
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	PalmTree5->Render(dc);

	result = m_LightShader->Render(dc, PalmTree5->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		PalmTree5->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, PalmTree5->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			PalmTree5->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//PalmTree6
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	PalmTree6->Render(dc);

	result = m_LightShader->Render(dc, PalmTree6->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		PalmTree6->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, PalmTree6->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			PalmTree6->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//PalmTree7
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	PalmTree7->Render(dc);

	result = m_LightShader->Render(dc, PalmTree7->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		PalmTree7->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, PalmTree7->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			PalmTree7->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//PalmTree8
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	PalmTree8->Render(dc);

	result = m_LightShader->Render(dc, PalmTree8->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		PalmTree8->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, PalmTree8->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			PalmTree8->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//PalmTree9
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	PalmTree9->Render(dc);

	result = m_LightShader->Render(dc, PalmTree9->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		PalmTree9->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, PalmTree9->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			PalmTree9->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//Stone
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	Stone->Render(dc);

	result = m_LightShader->Render(dc, Stone->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		Stone->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, Stone->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			Stone->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//Stone2
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	Stone2->Render(dc);

	result = m_LightShader->Render(dc, Stone2->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		Stone2->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, Stone2->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			Stone2->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	//Stone3
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -15.0f, 0.0f);
	Stone3->Render(dc);

	result = m_LightShader->Render(dc, Stone3->GetIndexCount(),
		world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix,
		Stone3->GetTexture(),
		m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower(),
		spotDiffuseColor, lightPosition);

	if (m_LightShader->GetPhong() ? false : true) {
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_BACK);
		result = m_OutlineShader->Render(dc, Stone3->GetIndexCount(),
			world, _sceneInfo->viewMatrix,
			_sceneInfo->projectionMatrix,
			Stone3->GetTexture(),
			m_Light->GetDirection(), m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
			_mainCam.GetPositionF(), m_Light->GetSpecularColor(), m_Light->GetSpecularPower());
		DEVICEMANAGER.ChangeCullMode(dc, D3D11_CULL_NONE);
	}

	if (INPUTMANAGER.GetShift() == 1.0f) {
		m_LightShader->SetPhong(m_LightShader->GetPhong() ? false : true);
	}

	//Water
	/*XMMATRIX reflectionMatrix;
	world = _sceneInfo->worldMatrix;
	world *= XMMatrixTranslation(0.0f, -12.5f, 0.0f);

	reflectionMatrix = _mainCam.GetReflectionViewMatrix();

	Water->Render(dc);

	m_WaterShader->Render(dc, Water->GetIndexCount(), world, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix, reflectionMatrix, m_ReflectionTexture->GetShaderResourceView(),
		m_RefractionTexture->GetShaderResourceView(), Water->GetTexture(),
		m_waterTranslation, 0.2f);*/

//
	DEVICEMANAGER.ChangeCullMode(D3D11_CULL_NONE);
	skybox->SetRenderState(DEVICEMANAGER.GetDevice());
	skybox->Render(dc, _sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix, _mainCam.GetPosition());
	DEVICEMANAGER.ChangeCullMode(D3D11_CULL_BACK);

	//블렌딩 설정...
	DEVICEMANAGER.TurnOnAlphaBlending(dc);
//	XMMATRIX world;
	XMFLOAT3 cameraPosition, modelPosition;
	XMMATRIX translateMatrix;
	cameraPosition.x = XMVectorGetX(_mainCam.GetPosition());
	cameraPosition.y = XMVectorGetY(_mainCam.GetPosition());
	cameraPosition.z = XMVectorGetZ(_mainCam.GetPosition());

	modelPosition.x = mov.x;
	modelPosition.y = mov.y;
	modelPosition.z = mov.z;

	double angle = atan2(modelPosition.x - cameraPosition.x, modelPosition.z - cameraPosition.z) * (180.0 / XM_PI);

	float rotation2 = (float)angle * 0.0174532925f;

	world = _sceneInfo->worldMatrix;
	world *= XMMatrixScaling(0.1f, 0.1f, 0.1f);
	world = XMMatrixRotationY(rotation2);
	translateMatrix = XMMatrixTranslation(modelPosition.x, modelPosition.y, modelPosition.z);

	world = XMMatrixMultiply(world, translateMatrix);

//	world = _sceneInfo->worldMatrix;
//	world *= XMMatrixTranslation(0.0f, 2.0f, 0.0f);
	m_ParticleSystem->Render(dc); //파티클을 빌보드 처리함
	m_ParticleShader->Render(dc, m_ParticleSystem->GetIndexCount(),world, 
		_sceneInfo->viewMatrix, _sceneInfo->projectionMatrix, m_ParticleSystem->GetTexture());
	DEVICEMANAGER.TurnOffAlphaBlending(dc);

	/*for (auto data : RM_MODEL.GetResource()) {
		data.second->Render(dc);
	}*/

	DEVICEMANAGER.TurnZBufferOff(dc);
	DEVICEMANAGER.TurnOnAlphaBlending(dc);
	m_Text->Render(dc, _sceneInfo->worldMatrix, _sceneInfo->orthoMatrix);
	DEVICEMANAGER.TurnOffAlphaBlending(dc);
	DEVICEMANAGER.TurnZBufferOn(dc);
}

bool TestScene::RenderRefractionToTexture(ID3D11DeviceContext* dc)
{
	XMFLOAT4 clipPlane;
	XMMATRIX world, view, projection;
	bool result;

	// Setup a clipping plane based on the height of the water to clip everything above it.
	clipPlane = XMFLOAT4(0.0f, -1.0f, 0.0f, m_waterHeight + 0.1f);

	// Set the render target to be the refraction render to texture.
	m_RefractionTexture->SetRenderTarget(dc, DEVICEMANAGER.GetDepthStencilView(_sceneInfo));

	// Clear the refraction render to texture.
//	m_RefractionTexture->ClearRenderTarget(dc, DEVICEMANAGER.GetDepthStencilView(_sceneInfo), 0.0f, 0.0f, 0.0f, 1.0f);

	// Get the world, view, and projection matrices from the camera and d3d objects.
	world = _sceneInfo->worldMatrix;
	view = _sceneInfo->viewMatrix;
	projection = _sceneInfo->projectionMatrix;

	// Translate to where the bath model will be rendered.
	world *= XMMatrixTranslation(0.0f, -12.5f, 0.0f);

	// Put the bath model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	Island->Render(dc);

	// Render the bath model using the light shader.
	result = m_RefractionShader->Render(dc, Island->GetIndexCount(), world, view,
		projection, Island->GetTexture(), m_Light->GetDirection(),
		m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(), clipPlane);
	if (!result)
	{
		return false;
	}

	// Reset the render target back to the original back buffer and not the render to texture anymore.
	DEVICEMANAGER.EndScene(_sceneInfo);
	return true;
}

bool TestScene::RenderReflectionToTexture(ID3D11DeviceContext* dc)
{
	XMMATRIX reflectionViewMatrix, world, projection, view;
	XMFLOAT4 spotDiffuseColor[4];
	XMFLOAT4 lightPosition[4];
	bool result;

	// Create the diffuse color array from the four light colors.
	spotDiffuseColor[0] = m_Light1->GetDiffuseColor();
	spotDiffuseColor[1] = m_Light2->GetDiffuseColor();
	spotDiffuseColor[2] = m_Light3->GetDiffuseColor();
	spotDiffuseColor[3] = m_Light4->GetDiffuseColor();

	// Create the light position array from the four light positions.
	lightPosition[0] = m_Light1->GetPosition();
	lightPosition[1] = m_Light2->GetPosition();
	lightPosition[2] = m_Light3->GetPosition();
	lightPosition[3] = m_Light4->GetPosition();

	// Set the render target to be the reflection render to texture.
	m_ReflectionTexture->SetRenderTarget(dc, DEVICEMANAGER.GetDepthStencilView(_sceneInfo));

	// Clear the reflection render to texture.
//	m_ReflectionTexture->ClearRenderTarget(dc, DEVICEMANAGER.GetDepthStencilView(_sceneInfo), 0.0f, 0.0f, 0.0f, 1.0f);

	// Use the camera to render the reflection and create a reflection view matrix.
	_mainCam.RenderReflection(m_waterHeight);

	// Get the camera reflection view matrix instead of the normal view matrix.
	reflectionViewMatrix = _mainCam.GetReflectionViewMatrix();

	// Put the wall model vertex and index buffers on the graphics pipeline to prepare them for drawing.
	DEVICEMANAGER.ChangeCullMode(D3D11_CULL_NONE);
	skybox->SetRenderState(DEVICEMANAGER.GetDevice());
	skybox->Render(dc,_sceneInfo->viewMatrix,
		_sceneInfo->projectionMatrix, _mainCam.GetPosition());
	DEVICEMANAGER.ChangeCullMode(D3D11_CULL_BACK);
	
	XMFLOAT3 pos;
	pos.x = XMVectorGetX(_mainCam.GetPosition());
	pos.y = XMVectorGetY(_mainCam.GetPosition());
	pos.z = XMVectorGetZ(_mainCam.GetPosition());

	world = _sceneInfo->worldMatrix;
	view = _sceneInfo->viewMatrix;
	projection = _sceneInfo->projectionMatrix;

	// Render the wall model using the light shader and the reflection view matrix.
	result = m_LightShader->Render(dc, skybox->GetIndexCount(), world, reflectionViewMatrix,
		projection, skybox->GetTexture(), m_Light->GetDirection(),
		m_Light->GetAmbientColor(), m_Light->GetDiffuseColor(),
		pos, m_Light->GetSpecularColor(), m_Light->GetSpecularPower(), spotDiffuseColor, lightPosition);
	if (!result)
	{
		return false;
	}

	// Reset the render target back to the original back buffer and not the render to texture anymore.
	DEVICEMANAGER.SetBackBufferRenderTarget(_sceneInfo, dc);

	return true;
}