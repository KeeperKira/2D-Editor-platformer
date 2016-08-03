
#include "stdafx.h"
#include "DIRECTX.h"

DIRECTX::DIRECTX()
{
	pDirect3d=NULL;
	this->WndProc =NULL;

	Width=1280;
	Height=720;
	Format=D3DFMT_A8R8G8B8;
	FullScreen=FALSE;

}

HRESULT DIRECTX::LookCreate(int Width,int Height)
{
	HRESULT hr;
// Матрица вида
	D3DXMatrixLookAtLH(
    &matrixView,
    &D3DXVECTOR3(0,0,0),
    &D3DXVECTOR3(0,0,1),
    &D3DXVECTOR3(0,1,0));

// Матрица проекции
	D3DXMatrixOrthoOffCenterLH(&matrixProjection, 0, (float)Width, (float)Height, 0, 0,200 );

// Установка матриц в качестве текущих
	if(FAILED(hr=pDevice->SetTransform(D3DTS_VIEW,&matrixView)))
		return	hr;
	if(FAILED(hr=pDevice->SetTransform(D3DTS_PROJECTION,&matrixProjection)))
		return	hr;

	pDevice->SetFVF(D3DFVF_XYZ | D3DFVF_TEX1 | D3DFVF_DIFFUSE);

	return	S_OK;

}



HRESULT DIRECTX::Create(HWND _hwnd)
{
	HRESULT							hr;
	D3DPRESENT_PARAMETERS			params;

	pDirect3d = Direct3DCreate9( D3D_SDK_VERSION );
	ZeroMemory( &params, sizeof(params) );


	params.BackBufferWidth	=Width;
	params.BackBufferHeight	=Height;
	params.BackBufferFormat =Format ;
	params.Windowed			=!(FullScreen);


	params.SwapEffect		=D3DSWAPEFFECT_DISCARD  ;
	params.FullScreen_RefreshRateInHz= D3DPRESENT_RATE_DEFAULT;
	params.PresentationInterval= D3DPRESENT_INTERVAL_DEFAULT;



	if (FAILED(hr=pDirect3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, _hwnd, 
											D3DCREATE_HARDWARE_VERTEXPROCESSING  ,
											&params,  &pDevice )))
		return hr;






	D3DXCreateSprite(pDevice, &pSprite);

	IMAGE::pSpr = pSprite;
	IMAGE::pDevice = pDevice;
	



float pointSize = 50; // Размер частиц в единицах пространства вида
    pDevice->SetRenderState(D3DRS_POINTSIZE_MAX, *((DWORD*)&pointSize));
    pDevice->SetRenderState(D3DRS_POINTSIZE, *((DWORD*)&pointSize));
    pDevice->SetRenderState(D3DRS_LIGHTING,FALSE);

    pDevice->SetRenderState(D3DRS_POINTSPRITEENABLE, TRUE ); //Включаем рисование спрайтов поверх точек
	pDevice->SetRenderState(D3DRS_POINTSCALEENABLE,TRUE);

    pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
    pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);//D3DBLEND_SRCALPHA//D3DBLEND_ZERO
    pDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA );//D3DBLEND_INVSRCALPHA //D3DBLEND_ONE//D3DBLEND_INVSRCCOLOR
	pDevice->SetRenderState(D3DRS_BLENDOPALPHA , TRUE);


    pDevice->SetTextureStageState( 0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	pDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE );
	pDevice->SetTextureStageState( 0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE );
	
    pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);




	return S_OK;
}

DIRECTX::~DIRECTX(void)
{
	if(pDevice!=NULL)
		pDevice->Release();
	if(pDirect3d!=NULL)
		pDirect3d->Release();
}
/*
int	LoopFlip( void (*Flip)(void))
{
	MSG msg;

	ZeroMemory(&msg,sizeof(msg));
	while (msg.message!=WM_QUIT)
	{
		if (PeekMessage(&msg,NULL,0,0,PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Flip();


		}
	}
	return (int)msg.wParam;


}
*/
/*
BOOL DIRECTX::RegisterWindow(HINSTANCE hInstance,LPCWSTR NameApplication, int nCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW ;
	if(WndProc!= NULL)
		wcex.lpfnWndProc	= WndProc;
	else
		return FALSE;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;// MAKEINTRESOURCE(IDC_DIRECT);
	wcex.lpszClassName	= NameApplication;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, IDI_APPLICATION);

	RegisterClassEx(&wcex);



   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   hWnd = CreateWindow(NameApplication, NameApplication, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, Width, Height, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

	if (FAILED(this->Create(hWnd)))
		return FALSE;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
*/
void	DIRECTX::CallBackWnd(LRESULT (CALLBACK *WndProc)(HWND, UINT, WPARAM, LPARAM))
{
	this->WndProc = WndProc;
}

void DIRECTX::SetWndParam(int Width,int Height,BOOL FullScreen,D3DFORMAT Format)
{

	this->Width= Width;
	this->Height= Height;
	this->FullScreen= FullScreen;
	this->Format= Format;

}
