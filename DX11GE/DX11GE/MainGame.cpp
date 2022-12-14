#include "pch.h"
#include "MainGame.h"
#include "TestScene.h"

PWindowRender GameNode::_sceneInfo = NULL;

//==================================================================
//		## �ʱ�ȭ ## Init(void)
//==================================================================
HRESULT MainGame::Init(ID3D11DeviceContext* dc)
{
	_sceneInfo = DEVICEMANAGER.InitRenderScreen(_hWnd, dc, WINSIZEX, WINSIZEY, 0.1f, 1000.f);
//	m_deviceContext = dc;
	InitScene();
	// Create the text object.
//	m_Text = new TextClass;
//	m_Text->Initialize(DEVICEMANAGER.GetDevice(), dc, _hWnd, WINSIZEX, WINSIZEY, _sceneInfo->viewMatrix);

	return S_OK;
}


//==================================================================
//		## Scene ���� ## InitScene(void)
//==================================================================
HRESULT MainGame::InitScene()
{
	//�� �߰� �� ����
	SCENEMANAGER.AddScene("test", new TestScene);
	SCENEMANAGER.ChangeScene("test");

	

	return S_OK;
}

//==================================================================
//		## ������Ʈ ## Update(void)
//==================================================================
void MainGame::Update(void)
{
	TIMEMANAGER.Update(0.0f);
	SCENEMANAGER.Update();

//	m_Text->SetFPS(fps, DEVICEMANAGER.GetDeviceContext());


	// Set the cpu usage.
//	m_Text->SetCPU(cpu, DEVICEMANAGER.GetDeviceContext());

	// Set the position of the camera.
//	m_Camera->SetPosition(0.0f, 0.0f, -10.0f);
	
//	UpdateMainGameFont();

	_sceneInfo->viewMatrix = _mainCam.Update(TIMEMANAGER.GetElapedTime());
}


//==================================================================
//		## ���� ## render(void)
//==================================================================
void MainGame::Render(ID3D11DeviceContext* dc)
{	
	//Set Main DC State
	DEVICEMANAGER.SetRasterState(dc);
	DEVICEMANAGER.SetSamplerState(dc);

	DEVICEMANAGER.BeginScene(_sceneInfo, dc, 0, 0, 0, 1);
	
	//���� �� �� ��� ����
	RM_SHADER.SetShaderParameters(dc, _sceneInfo->viewMatrix, _sceneInfo->projectionMatrix);
	SCENEMANAGER.Render(dc);

	//������� : ������ķ� ����
	RM_SHADER.SetShaderParameters(dc, XMMatrixTranslation(0, 0, 1), _sceneInfo->orthoMatrix);
//	m_Text->Render(dc, _sceneInfo->worldMatrix, _sceneInfo->orthoMatrix);

//	FONTMANAGER.Render(dc);
//	DEVICEMANAGER.TurnOnAlphaBlending(dc);
//	DEVICEMANAGER.TurnZBufferOff(dc);
//	m_Text->Render(dc, _sceneInfo->worldMatrix, _sceneInfo->orthoMatrix);
//	DEVICEMANAGER.TurnOffAlphaBlending(dc);
//	DEVICEMANAGER.TurnZBufferOn(dc);

	//command Excute
	DEVICEMANAGER.ExcuteCommand(dc);

	//SwapChain
	DEVICEMANAGER.EndScene(_sceneInfo);
}

//void MainGame::UpdateMainGameFont()
//{
//	TCHAR buff[255];
//	wsprintf(buff, L"������ ���� : %d", TIMEMANAGER.GetFrameRate());
//	FONTMANAGER.Print(buff, 30, 80, 20, XMFLOAT3(1, 1, 0));
//
//
//	if (DEVICEMANAGER.IsVSync()) {
//		FONTMANAGER.Print(L"��������ȭ(F3) : On", 30, 180);
//	}
//	else {
//		FONTMANAGER.Print(L"��������ȭ(F3) : Off", 30, 180);
//	}
//}

