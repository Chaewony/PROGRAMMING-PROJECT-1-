//==================================================================
//		## Shader ## (Shader ���� Ŭ����)
//==================================================================
#pragma once
#include <dxgi.h>
#include <d3dcommon.h>
#include <d3d11.h>
#include <directxmath.h>
#include <d3dcompiler.h>
using namespace DirectX;
#include <fstream>
#include <iostream>
#include <string>
#include <locale>
#include <cstdlib>
#include <vector>
#include <list>
#include <map>
#include <atlstr.h>
#include <atlconv.h>
using namespace std;
#include <wrl.h>
using Microsoft::WRL::ComPtr;

using LAYOUT_INFO = pair<ComPtr<ID3D11InputLayout>, vector<D3D11_INPUT_ELEMENT_DESC>> ;

class Shader
{
public:
	Shader();
	~Shader();

	//���̴� �߰�
	bool InsertShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);
	//���� ����
	void VertexRender(ID3D11DeviceContext*, int, int);			
	//�ε��� ����
	void IndexRender(ID3D11DeviceContext*, int, int) ;			
	
	
	//���� ���̴��� ���� ���̾ƿ� ���� ������ ��ȯ
	vector<D3D11_INPUT_ELEMENT_DESC>& GetVertexLayoutDesc() { return _layoutList[_layoutIdx].second; }

private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR*, WCHAR*);		//���̴� �ʱ�ȭ
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR*);		//���̴� ���� ���

	//���̴��� ���� ���̾ƿ� ���� ����
	void BuildLayoutDesc(char* vsPath, vector<D3D11_INPUT_ELEMENT_DESC>& layoutDesc);

	//���̾ƿ� Ž��
	int FindLayout(vector<D3D11_INPUT_ELEMENT_DESC>& refLayoutDesc);
	
	//���̴� ����
	void RenderShader(ID3D11DeviceContext*);

private:
	ComPtr<ID3D11VertexShader>			_vertexShader;		//���� ���̴� 
	ComPtr<ID3D11PixelShader>			_pixelShader;		//�ȼ� ���̴�
	
	int									_layoutIdx;			//���̴� ���� �Է� ���̾ƿ� index


	//�ε�� ��� ���̴��� ���̾ƿ� ���� ����Ʈ
	//���� ��� ������ ��� ���̴��� �����Ѵ�.
	//���̴��� �����Ǵ��� ���̾ƿ� ������ ��� �����Ѵ�.
	static vector<LAYOUT_INFO>			_layoutList;	
};