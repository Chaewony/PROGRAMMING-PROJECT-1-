#pragma once
#include <dinput.h>
#include <directxmath.h>
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")
using namespace DirectX;

#pragma once
#include "SingletonBase.h"
class InputManager : public SingletonBase <InputManager>
{
public:
	//Ű�Ŵ��� �ʱ�ȭ
	HRESULT Init();
	void release(void);
//	void DetectInput(double time);
	void DetectInput();
	
	float GetHorizontal() { return m_Horizontal; } //�¿��̵�
	float GetVertical() { return m_Vertical; } //�����̵�
	float GetShift() { return m_Shift; }

	float GetYaw() { return m_Yaw; }
	float GetPitch() { return m_Pitch; }

	InputManager() {}
	~InputManager() {}

private:
	bool InitDirectInput(HINSTANCE hInstance, HWND hwnd);
	LPDIRECTINPUT8 DirectInput;
	IDirectInputDevice8* DIKeyboard;
	IDirectInputDevice8* DIMouse;

	float m_Horizontal;
	float m_Vertical;
	float m_Shift;

	DIMOUSESTATE mouseLastState;

	float m_Yaw;
	float m_Pitch;
};

