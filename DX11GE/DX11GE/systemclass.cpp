////////////////////////////////////////////////////////////////////////////////
// Filename: systemclass.cpp
////////////////////////////////////////////////////////////////////////////////
#include "pch.h"
#include "systemclass.h"

SystemClass::SystemClass()
{
//	m_Input = 0;
//	m_Graphics = 0;
	m_Fps = 0;
	m_Cpu = 0;
	m_Timer = 0;
}


SystemClass::SystemClass(const SystemClass& other)
{
}


SystemClass::~SystemClass()
{
}


bool SystemClass::Initialize()
{
	int screenWidth, screenHeight;
	bool result;


	// Initialize the width and height of the screen to zero before sending the variables into the function.
	screenWidth = 0;
	screenHeight = 0;

	// Initialize the windows api.
	InitializeWindows(screenWidth, screenHeight);

	// Create the input object.  This object will be used to handle reading the keyboard input from the user.
	/*m_Input = new InputClass;
	if(!m_Input)
	{
		return false;
	}*/

	// Initialize the input object.
//	m_Input->Initialize();

	// Create the graphics object.  This object will handle rendering all the graphics for this application.
	/*m_Graphics = new GraphicsClass;
	if(!m_Graphics)
	{
		return false;
	}*/

	// Initialize the graphics object.
	/*result = m_Graphics->Initialize(screenWidth, screenHeight, m_hwnd);
	if(!result)
	{
		return false;
	}*/
	
	// Create the fps object.
	m_Fps = new FpsClass;
	if (!m_Fps)
	{
		return false;
	}

	// Initialize the fps object.
	m_Fps->Initialize();
	// Create the cpu object.
	m_Cpu = new CpuClass;
	if (!m_Cpu)
	{
		return false;
	}

	// Initialize the cpu object.
	m_Cpu->Initialize();
	// Create the timer object.
	m_Timer = new TimerClass;
	if (!m_Timer)
	{
		return false;
	}

	// Initialize the timer object.
	result = m_Timer->Initialize();
	if (!result)
	{
		MessageBox(m_hwnd, L"Could not initialize the Timer object.", L"Error", MB_OK);
		return false;
	}
	
	_hWnd = this->m_hwnd;
	_hInstance = this->m_hinstance;

	if (FAILED(InitManager()))
		return false;

	DEVICEMANAGER.SetDeferredContext(&_mainDC);

	//create mainGame Object
	_mg = make_unique<MainGame>();
	_mg->Init(_mainDC);

	//set camera State
	_mainCam.SetPosition(0.0f, 1.0f, -10.0f);

	return true;
}


void SystemClass::Shutdown()
{
	// Release the graphics object.
	/*if(m_Graphics)
	{
		m_Graphics->Shutdown();
		delete m_Graphics;
		m_Graphics = 0;
	}*/

	// Release the input object.
	/*if(m_Input)
	{
		delete m_Input;
		m_Input = 0;
	}*/

	// Release the timer object.
	if (m_Timer)
	{
		delete m_Timer;
		m_Timer = 0;
	}

	// Release the cpu object.
	if (m_Cpu)
	{
		m_Cpu->Shutdown();
		delete m_Cpu;
		m_Cpu = 0;
	}

	// Release the fps object.
	if (m_Fps)
	{
		delete m_Fps;
		m_Fps = 0;
	}

	SAFE_RELEASE(_mainDC);

	//Manager Release
	SCENEMANAGER.Release();
	RM_SHADER.ClearResource();
	RM_MODEL.ClearResource();
	RM_TEXTURE.ClearResource();

	// Shutdown the window.
	ShutdownWindows();
	
	return;
}


void SystemClass::Run()
{
	MSG msg;
	bool done, result;


	// Initialize the message structure.
	ZeroMemory(&msg, sizeof(MSG));
	
	// Loop until there is a quit message from the window or the user.
	done = false;
	while(!done)
	{
		// Handle the windows messages.
		if(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		// If windows signals to end the application then exit out.
		if(msg.message == WM_QUIT)
		{
			done = true;
		}
		else
		{
			// Otherwise do the frame processing.
			result = Frame();
			if(!result)
			{
				done = true;
			}
		}

	}

	return;
}


bool SystemClass::Frame()
{
	bool result;

	m_Timer->Frame();
	m_Fps->Frame();
	m_Cpu->Frame();
	INPUTMANAGER.DetectInput();

	float duration = TIMEMANAGER.GetElapedTime();
	_mainCam.KeyboardInput(duration);
	_mainCam.MouseInput();
	// Check if the user pressed escape and wants to exit the application.
	/*if(m_Input->IsKeyDown(VK_ESCAPE))
	{
		return false;
	}*/

	// Do the frame processing for the graphics object.
	/*result = m_Graphics->Frame(m_Fps->GetFps(), m_Cpu->GetCpuPercentage());
	if (!result)
	{
		return false;
	}*/
	if (!_mg) { return false; }
	_mg->Update();
	_mg->Render(_mainDC);

	return true;
}


LRESULT CALLBACK SystemClass::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch(umsg)
	{
		// Check if a key has been pressed on the keyboard.
		//case WM_KEYDOWN:
		//{
		//	// If a key is pressed send it to the input object so it can record that state.
		//	m_Input->KeyDown((unsigned int)wparam);
		//	return 0;
		//}

		//// Check if a key has been released on the keyboard.
		//case WM_KEYUP:
		//{
		//	// If a key is released then send it to the input object so it can unset the state for that key.
		//	m_Input->KeyUp((unsigned int)wparam);
		//	return 0;
		//}

		// Any other messages send to the default message handler as our application won't make use of them.
		default:
		{
			return DefWindowProc(hwnd, umsg, wparam, lparam);
		}
	}
}


void SystemClass::InitializeWindows(int& screenWidth, int& screenHeight)
{
	WNDCLASSEX wc;
	DEVMODE dmScreenSettings;
	int posX, posY;


	// Get an external pointer to this object.	
	ApplicationHandle = this;

	// Get the instance of this application.
	m_hinstance = GetModuleHandle(NULL);

	// Give the application a name.
	m_applicationName = L"Engine";

	// Setup the windows class with default settings.
	wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc   = WndProc;
	wc.cbClsExtra    = 0;
	wc.cbWndExtra    = 0;
	wc.hInstance     = m_hinstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm       = wc.hIcon;
	wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = m_applicationName;
	wc.cbSize        = sizeof(WNDCLASSEX);
	
	// Register the window class.
	RegisterClassEx(&wc);

	// Determine the resolution of the clients desktop screen.
	screenWidth  = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	// Setup the screen settings depending on whether it is running in full screen or in windowed mode.
	if(FULL_SCREEN)
	{
		// If full screen set the screen to maximum size of the users desktop and 32bit.
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize       = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth  = (unsigned long)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;			
		dmScreenSettings.dmFields     = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Change the display settings to full screen.
		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);

		// Set the position of the window to the top left corner.
		posX = posY = 0;
	}
	else
	{
		// If windowed then set it to 800x600 resolution.
		screenWidth  = WINSIZEX;
		screenHeight = WINSIZEY;

		// Place the window in the middle of the screen.
		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth)  / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}

	// Create the window with the screen settings and get the handle to it.
	m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName, 
						    WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
						    posX, posY, screenWidth, screenHeight, NULL, NULL, m_hinstance, NULL);

	// Bring the window up on the screen and set it as main focus.
	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);

	// Hide the mouse cursor.
	ShowCursor(false);

	return;
}


void SystemClass::ShutdownWindows()
{
	// Show the mouse cursor.
	ShowCursor(true);

	// Fix the display settings if leaving full screen mode.
	if(FULL_SCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	// Remove the window.
	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	// Remove the application instance.
	UnregisterClass(m_applicationName, m_hinstance);
	m_hinstance = NULL;

	// Release the pointer to this class.
	ApplicationHandle = NULL;

	return;
}

HRESULT SystemClass::InitManager()
{
	if (FAILED(DEVICEMANAGER.CreateDevice(WINSIZEX, WINSIZEY))) {
		MessageBox(m_hwnd,L"Failed Init Device!",L"�� ���α׷��� ����˴ϴ�", MB_ICONQUESTION|MB_OKCANCEL);
		return E_FAIL;
	}

	if (FAILED(INPUTMANAGER.Init())) {
		MessageBox(m_hwnd, L"Failed Init INPUTMANAGER!", L"�� ���α׷��� ����˴ϴ�", MB_ICONQUESTION | MB_OKCANCEL);
		return E_FAIL;
	}

	if (FAILED(TIMEMANAGER.Init())) {
		MessageBox(m_hwnd, L"Failed Init TIME_MANAGER!", L"�� ���α׷��� ����˴ϴ�", MB_ICONQUESTION | MB_OKCANCEL);
	}

	if (FAILED(SCENEMANAGER.Init())) {
		MessageBox(m_hwnd, L"Failed Init SCENE_MANAGER!", L"�� ���α׷��� ����˴ϴ�", MB_ICONQUESTION | MB_OKCANCEL);
		return E_FAIL;
	}

	ID3D11Device* device = DEVICEMANAGER.GetDevice();

	if (FAILED(RM_SHADER.Init(device))) {
		MessageBox(m_hwnd, L"Failed Init RM_SHADER!", L"�� ���α׷��� ����˴ϴ�", MB_ICONQUESTION | MB_OKCANCEL);
		return E_FAIL;
	}

	/*if (FAILED(FONTMANAGER.Init())) {
		AfxMessageBox(L"Failed Init FONT_MANAGER!");
		return E_FAIL;
	}*/

	return S_OK;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam)
{
	switch(umessage)
	{
		// Check if the window is being destroyed.
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}

		// Check if the window is being closed.
		case WM_CLOSE:
		{
			PostQuitMessage(0);		
			return 0;
		}

		// All other messages pass to the message handler in the system class.
		default:
		{
			return ApplicationHandle->MessageHandler(hwnd, umessage, wparam, lparam);
		}
	}
}