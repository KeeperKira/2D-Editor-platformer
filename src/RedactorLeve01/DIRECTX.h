#pragma once
#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>


#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
//#pragma comment (lib, "dinput.lib")
#pragma comment (lib, "dInput8.lib")
#pragma comment (lib, "dxguid.lib")

class DIRECTX
{
public:
	LPDIRECT3D9			pDirect3d;
	LPDIRECT3DDEVICE9	pDevice;
	LPD3DXSPRITE		pSprite;

	D3DXMATRIX matrixView;
	D3DXMATRIX matrixProjection;

	int Width;
	int Height;
	D3DFORMAT Format;
	BOOL FullScreen;

	HINSTANCE hInst;
	HWND hWnd;
	
	LRESULT (CALLBACK* WndProc)(HWND, UINT, WPARAM, LPARAM);

	DIRECTX();
	void SetWndParam(int Width=1280,int Height=1024,BOOL FullScreen=FALSE,D3DFORMAT Format=D3DFMT_A8R8G8B8);
	void		CallBackWnd(LRESULT (CALLBACK *WndProc)(HWND, UINT, WPARAM, LPARAM));
	HRESULT		Create(HWND _hwnd);
	HRESULT		LookCreate(int Width,int Height);
//	BOOL		RegisterWindow(HINSTANCE hInstance,LPCWSTR NameApplication,int nCmdShow);
	~DIRECTX(void);
};

int			LoopFlip(void (*Flip)(void));


/*
void	Draw(void)
{

	Direct->pDevice->BeginScene();
	Direct->pDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,0), 1.0f, 0 );

	Fon->Draw();

	for(int i = 0;i<Enemys.size();i++)
	{
		Enemys[i]->Draw();
	}



	Player->Draw();

	Direct->pDevice->EndScene();
	Direct->pDevice->Present(0,0,hWnd,0);

}


*/