#include "StdAfx.h"
#include "IMAGE.h"

LPD3DXSPRITE IMAGE::pSpr=NULL;
LPDIRECT3DDEVICE9 IMAGE::pDevice=NULL;

IMAGE::IMAGE(void)
{
	this->SoursBlend = D3DBLEND_SRCALPHA;
	this->DestBlend = D3DBLEND_INVSRCALPHA;

	Alpha	=	255;
	Red		=	255;
	Green	=	255;
	Blue	=	255;

	Go = 0;

	Size.x	=	1;
	Size.y	=	1;

	Pos.x = 0;
	Pos.y = 0;
	Pos.z = 0;

	Center.x =0;
	Center.y =0;
	Center.z =0;

	Position.x = 0;
	Position.y = 0;
	Position.z = 0;

	Rotation = 0;

	PointRotation.x =0;
	PointRotation.y =0;


	Rect.bottom = 0;
	Rect.left	= 0;
	Rect.right	= 0;
	Rect.top	= 0;

	Texture = NULL;
}

IMAGE::IMAGE(LPCWSTR filename)
{
	this->SoursBlend = D3DBLEND_SRCALPHA;
	this->DestBlend = D3DBLEND_INVSRCALPHA;

	Alpha	=	255;
	Red		=	255;
	Green	=	255;
	Blue	=	255;

	Go = 0;

	Size.x	=	1;
	Size.y	=	1;

	Pos.x = 0;
	Pos.y = 0;
	Pos.z = 0;

	Center.x =0;
	Center.y =0;
	Center.z =0;

	Position.x = 0;
	Position.y = 0;
	Position.z = 0;

	Rotation = 0;
	PointRotation*=0;

	Rect.bottom = 0;
	Rect.left	= 0;
	Rect.right	= 0;
	Rect.top	= 0;

	Texture = NULL;

	LoadImageFromFile(filename);
}

HRESULT IMAGE::LoadImageFromFile(LPCWSTR filename)
{
	if(Texture!=NULL)
	{
	//	Texture->Release();
		Texture = NULL;
	}

	HRESULT hr;
	D3DXIMAGE_INFO Info;
	ZeroMemory(&Info,sizeof(Info));
	ZeroMemory(&Texture,sizeof(Texture));

    if(FAILED(hr=D3DXGetImageInfoFromFile(filename, &Info)))
	{
		MessageBox(NULL,filename,L"Текстура не найдена", MB_OK);
		

		return hr; 
	}

	if(FAILED(hr=D3DXCreateTextureFromFileEx(pDevice, filename, D3DX_DEFAULT_NONPOW2,       
                        D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT, 0,
                        D3DFMT_UNKNOWN, D3DPOOL_DEFAULT,
                        D3DX_DEFAULT, D3DX_DEFAULT, 
						NULL, NULL, NULL, &Texture)))
	{
		MessageBox(NULL,filename,L"Не удалось загрузить текстуру", MB_OK);
	//	MessageBox(NULL,L"fg",L"df",MB_OK);
		return hr;
	}
	pDevice->SetTexture(0,Texture);

	Width=Info.Width;
	Height=Info.Height;

	Rect.right		= Width;
	Rect.bottom		= Height;

	return S_OK;
}
HRESULT IMAGE::LoadImageFromArhive(TCHAR *Arhivename,TCHAR *Filename)
{
	STARTUPINFO Start;
	memset(&Start, 0, sizeof(Start));
	Start.cb = sizeof(Start);

	Start.dwFlags = STARTF_USESHOWWINDOW;
	Start.wShowWindow = SW_HIDE;

	PROCESS_INFORMATION Proce;
	memset(&Proce, 0, sizeof(Proce));



	TCHAR Comand[115] = L"7z.exe e -y ";




	wcscat_s(Comand,Arhivename);
	wcscat_s(Comand,L" ");
	wcscat_s(Comand,Filename);

	TCHAR *ptr =wcsrchr(Filename,*L"/");

	if(ptr!= NULL)
	{
		ptr++;
	}
	else
	{
		ptr = Filename;
	}


	CreateProcess(NULL, Comand, NULL, NULL, FALSE, 0, NULL, NULL, &Start, &Proce);



	DWORD pro = WaitForSingleObject(Proce.hProcess,INFINITE);



	if(FAILED(LoadImageFromFile(ptr)))
		return FALSE;
	DeleteFile(ptr);
	return S_OK;
}


HRESULT IMAGE::CreateImage(int _Width, int _Height)
{
	HRESULT hr;

	ZeroMemory(&Texture,sizeof(Texture));

	
	if(FAILED(hr=D3DXCreateTexture(pDevice,_Width,_Height,0,D3DUSAGE_RENDERTARGET,D3DFMT_A8R8G8B8,D3DPOOL_DEFAULT,&Texture)))
	{
		return hr;
	}
	pDevice->SetTexture(0,Texture);
	this->Width		= _Width;
	this->Height	= _Height;

	Rect.right		= _Width;
	Rect.bottom		= _Height;

	return S_OK;
}

 BOOL IMAGE::Collide(IMAGE &Object2)
{
	float k = 0,n = 0;
	k	=(this->Position.x)-(Object2.Position.x);
	n	=(this->Position.y)-(Object2.Position.y);

	if(-k>this->Width*Size.x)
		return false;
	else
	{
		if(k > Object2.Width*Object2.Size.x)
			return false;
		else
		{
			if(-n > this->Height*Size.y)
				return false;
			else
			{
				if(n > Object2.Height*Object2.Size.y)
					return false;
			}
		}
	}
	return true;
}

bool	IMAGE::PointCollide(D3DXVECTOR2 _Point)
{
	float X = (float)_Point.x;
	float Y = (float)_Point.y;

	if (Rotation != 0)
	{

		X = (Position.x+PointRotation.x)+ (_Point.x-(Position.x+PointRotation.x))*cosf(Rotation)-(_Point.y-(Position.y+PointRotation.y))*sinf(Rotation);
		Y = (Position.y+PointRotation.y)+ (_Point.x-(Position.x+PointRotation.x))*sinf(Rotation)+(_Point.y-(Position.y+PointRotation.y))*cosf(Rotation);


	}

	if(X > Position.x)
		if(X < Position.x+Width*Size.x)
			if(Y > Position.y)
				if(Y < Position.y+Height*Size.y)
					return true;
	return false;
}

bool	IMAGE::PointCollide(POINT _Point)
{

	float X = (float)_Point.x;
	float Y = (float)_Point.y;

	if (Rotation != 0)
	{
		X = (Position.x+PointRotation.x)+ (_Point.x-(Position.x+PointRotation.x))*cosf(Rotation)-(_Point.y-(Position.y+PointRotation.y))*sinf(Rotation);
		Y = (Position.y+PointRotation.y)+ (_Point.x-(Position.x+PointRotation.x))*sinf(Rotation)+(_Point.y-(Position.y+PointRotation.y))*cosf(Rotation);
	}


	if(X > Position.x)
		if(X < Position.x+Width*Size.x)
			if(Y > Position.y)
				if(Y < Position.y+Height*Size.y)
					return true;
	return false;
}

void IMAGE::Draw()
 {


	 if(Texture!=NULL)
	 {
		D3DXMATRIX	mat;
		//mat*=0;

		D3DXVECTOR2	 pos(Position.x,Position.y);

		D3DXMatrixTransformation2D(&mat,&pos,Go,&Size,&(pos+PointRotation),Rotation,NULL);
		pSpr->SetTransform(&mat);

		D3DXVECTOR3	Posi;
	//	Posi.x=(float)((int)Position.x);
	//	Posi.y=(float)((int)Position.y);
	//	Posi.z=(float)((int)Position.z);

		pSpr->Begin(D3DXSPRITE_ALPHABLEND);

		pDevice->SetRenderState(D3DRS_SRCBLEND,  SoursBlend);
		pDevice->SetRenderState(D3DRS_DESTBLEND, DestBlend );

		pSpr->Draw(Texture,&Rect,&Center,&Position,D3DCOLOR_ARGB(Alpha,Red,Green,Blue));

		pSpr->End();

		//	pDevice->SetRenderState(D3DRS_SRCBLEND,  5);
		//	pDevice->SetRenderState(D3DRS_DESTBLEND, 6 );

		//	D3DXMatrixIdentity(&mat);
		//	pSpr->SetTransform(&mat);

	 }

		// pSpr->Draw(Texture,NULL,&Size,&PointRotation,Rotation,&this->Position,D3DCOLOR_ARGB(Alpha,Red,Green,Blue));
			
 }

void IMAGE::DrawMirror()
{
	if(Texture!=NULL)
	{
		D3DXVECTOR2	Size1;
//		Pos  = this->Position;
//		Pos.x +=Width*Size.x;
		Size1 = this->Size;
		Size1.x *=-1;

		D3DXMATRIX	mat;
		D3DXVECTOR2	 pos(Position.x+Width*Size.x,Position.y);

		D3DXMatrixTransformation2D(&mat,&pos,Go,&Size1,&(pos+PointRotation),Rotation,NULL);
		pSpr->SetTransform(&mat);

		D3DXVECTOR3	Posi;
		Posi.x=(int)Position.x+Width*Size.x;
		Posi.y=(float)(int)Position.y;
		Posi.z=(float)(int)Position.z;
		pSpr->Begin(D3DXSPRITE_ALPHABLEND);

		pDevice->SetRenderState(D3DRS_SRCBLEND,  SoursBlend);
		pDevice->SetRenderState(D3DRS_DESTBLEND, DestBlend );

		pSpr->Draw(Texture,&Rect,&Center,&Posi,D3DCOLOR_ARGB(Alpha,Red,Green,Blue));

		pSpr->End();

		pDevice->SetRenderState(D3DRS_SRCBLEND,  5);
		pDevice->SetRenderState(D3DRS_DESTBLEND, 6 );

	}
}

void IMAGE::DrawCenter()
 {
	 /*
	 D3DXVECTOR2 fo;

	 fo = this->Position;
	 fo.x-=this->Width/2;
	 fo.y-=this->Height/2;

	 if(Texture!=NULL)
	 {
	 }
//		 pSpr->Draw(Texture,NULL,NULL,&PointRotation,Rotation,&fo,D3DCOLOR_ARGB(Alpha,Red,Green,Blue));
	// return TRUE;
	*/
}

void	IMAGE::SetARGB(int Alpha,int Red,int Green,int Blue)
{
	this->Alpha =Alpha;

	this->Red	=Red;
	this->Green	=Green;
	this->Blue	=Blue;
}

void	IMAGE::SetSize(float	_SizeX,float _SizeY)
{
	this->Size.x	=_SizeX;
	this->Size.y	=_SizeY;
}

void	IMAGE::SetPointRotation(float	_x,float _y)
{
	this->PointRotation.x	=_x;
	this->PointRotation.y	=_y;
}

void	IMAGE::SetRotation(float	_Rotation)
{
	this->Rotation = _Rotation;
}

float	IMAGE::GetRotation()
{
	return Rotation;
}

D3DXVECTOR2	IMAGE::GetPointRotation()
{
	return PointRotation;
}

D3DXVECTOR2	IMAGE::GetSize()
{
	return Size;
}

RECT	IMAGE::GetRect()
{
	return this->Rect;
}


unsigned char	IMAGE::GetAlpha()
{
	return Alpha;
}
unsigned char	IMAGE::GetRed()
{
	return Red;
}
unsigned char	IMAGE::GetGreen()
{
	return Green;
}
unsigned char	IMAGE::GetBlue()
{
	return Blue;
}





void	IMAGE::SetDirect(DIRECTX &DirectX)
{
	pSpr	=DirectX.pSprite;
	pDevice	=DirectX.pDevice;
}

void IMAGE::SetPixel(int _x, int _y,PIXEL _Pixel)
 {
	 D3DLOCKED_RECT pRect;
	 this->Texture->LockRect(0,&pRect,0,0);
	 *(((PIXEL*)(pRect.pBits))+_x+_y*pRect.Pitch/4)=_Pixel;
	 this->Texture->UnlockRect(0);
 }

PIXEL IMAGE::GetPixel(int _x, int _y)
 {
	 PIXEL Pixel;
	 D3DLOCKED_RECT pRect;
	 this->Texture->LockRect(0,&pRect,0,0);

	 Pixel= *((PIXEL*)pRect.pBits+_x+_y*pRect.Pitch/4);
	 this->Texture->UnlockRect(0);
	 return Pixel;
 }

void	IMAGE::SetPosition(float	_PosX,float	_PosY)
{
	this->Position.x =_PosX;
	this->Position.y =_PosY;

//	this->SetPointRotation(_PosX,_PosY);

}

void	IMAGE::SetRect(RECT	&Rect)
{
	this->Rect = Rect;
}

void	IMAGE::SetRect(long top,long left,long right,long bottom)
{
	this->Rect.bottom = bottom;
	this->Rect.left   = left;
	this->Rect.right  = right;
	this->Rect.top	  = top;
}


void	IMAGE::SetPosition(D3DXVECTOR2 _Pos)
{
	this->Position.x = _Pos.x;
	this->Position.y = _Pos.y;
}

void	IMAGE::Move(D3DXVECTOR2 Offset)
{
	
	SetPosition(Position.x+Offset.x,Position.y+Offset.y);
}

void	IMAGE::SetPosition(POINT _Pos)
{
	this->Position.x = (float)_Pos.x;
	this->Position.y = (float)_Pos.y;
}


D3DXVECTOR3	IMAGE::GetPosition(void)
{
	return Position;
}





IMAGE::~IMAGE(void)
{
	if(Texture!=NULL)
		Texture	= NULL;
};




/************************Данные Боарда************************/
BOARD::BOARD(void)
{
	IMAGE::IMAGE();

	this->SoursBlend = D3DBLEND_SRCALPHA;
	this->DestBlend = D3DBLEND_INVSRCALPHA;
}


void BOARD::Draw(void)
{
	pDevice->SetRenderState(D3DRS_SRCBLEND,  SoursBlend);
    pDevice->SetRenderState(D3DRS_DESTBLEND, DestBlend );

	pDevice->SetTexture(0,this->Texture);

	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN,2,&VertexPoint,sizeof(VERTEX));
}


HRESULT	BOARD::LoadImageFromFile(LPCWSTR filename)
{
	IMAGE::LoadImageFromFile(filename);

	VertexPoint[0].color = VertexPoint[1].color = VertexPoint[2].color = VertexPoint[3].color = D3DCOLOR_ARGB(Alpha,Red,Green,Blue);	

	VertexPoint[0].x = VertexPoint[0].y = VertexPoint[0].z = 0;

	VertexPoint[1].x = (float)this->Width;
	VertexPoint[1].y = VertexPoint[1].z = 0;

	VertexPoint[2].x = (float)this->Width;
	VertexPoint[2].y = (float)this->Height;
	VertexPoint[2].z = 0;

	VertexPoint[3].y = (float)this->Height;
	VertexPoint[3].x = VertexPoint[3].z = 0;

	

	VertexPoint[0].tu = 0;
	VertexPoint[1].tu = 1;
	VertexPoint[2].tu = 1;
	VertexPoint[3].tu = 0;

	VertexPoint[0].ty = 0;
	VertexPoint[1].ty = 0;
	VertexPoint[2].ty = 1;
	VertexPoint[3].ty = 1;

	VertexPointSou[0] = VertexPoint[0];
	VertexPointSou[1] = VertexPoint[1];
	VertexPointSou[2] = VertexPoint[2];
	VertexPointSou[3] = VertexPoint[3];

	return S_OK;
}


void	BOARD::SetARGB(int Alpha,int Red,int Green,int Blue)
{
	IMAGE::SetARGB(Alpha,Red,Green,Blue);

	VertexPoint[0].color = D3DCOLOR_ARGB(Alpha,Red,Green,Blue);
	VertexPoint[1].color = D3DCOLOR_ARGB(Alpha,Red,Green,Blue);
	VertexPoint[2].color = D3DCOLOR_ARGB(Alpha,Red,Green,Blue);
	VertexPoint[3].color = D3DCOLOR_ARGB(Alpha,Red,Green,Blue);
}


void	BOARD::SetSize(float	_SizeX,float _SizeY)
{
	IMAGE::SetSize(_SizeX,_SizeY);



	VertexPoint[1].x = Position.x+(Width * _SizeX) ;

	VertexPoint[2].x = Position.x+(Width * _SizeX) ;
	VertexPoint[2].y = Position.y+(Height * _SizeY) ;

	VertexPoint[3].y = Position.y+(Height * _SizeY) ;
	

	VertexPointSou[1].x = Position.x+(Width * _SizeX) ;

	VertexPointSou[2].x = Position.x+(Width * _SizeX) ;
	VertexPointSou[2].y = Position.y+(Height * _SizeY) ;

	VertexPointSou[3].y = Position.y+(Height * _SizeY) ;
	
}


void	BOARD::SetBlend(int	Sours,int Dest)
{
	this->DestBlend = Dest;
	this->SoursBlend = Sours;
}


void	BOARD::SetPosition(D3DXVECTOR2 _Pos)
{
	float DegX,DegY;
	DegX =Position.x - _Pos.x;
	DegY =Position.y - _Pos.y;

	IMAGE::SetPosition(_Pos);

	

	VertexPoint[0].x -=DegX;
	VertexPoint[0].y -=DegY;

	VertexPoint[1].x -=DegX;
	VertexPoint[1].y -=DegY;

	VertexPoint[2].x -=DegX;
	VertexPoint[2].y -=DegY;

	VertexPoint[3].x -=DegX;
	VertexPoint[3].y -=DegY;

	VertexPointSou[0].x -=DegX;
	VertexPointSou[0].y -=DegY;

	VertexPointSou[1].x -=DegX;
	VertexPointSou[1].y -=DegY;

	VertexPointSou[2].x -=DegX;
	VertexPointSou[2].y -=DegY;

	VertexPointSou[3].x -=DegX;
	VertexPointSou[3].y -=DegY;


	this->PointRotation.x-=DegX;
	this->PointRotation.y-=DegY;
}



void	BOARD::SetPosition(float	_PosX,float	_PosY)
{
	float DegX,DegY;
	DegX =Position.x - _PosX;
	DegY =Position.y - _PosY;

	IMAGE::SetPosition(_PosX,_PosY);

	

	VertexPoint[0].x -=DegX;
	VertexPoint[0].y -=DegY;

	VertexPoint[1].x -=DegX;
	VertexPoint[1].y -=DegY;

	VertexPoint[2].x -=DegX;
	VertexPoint[2].y -=DegY;

	VertexPoint[3].x -=DegX;
	VertexPoint[3].y -=DegY;

	VertexPointSou[0].x -=DegX;
	VertexPointSou[0].y -=DegY;

	VertexPointSou[1].x -=DegX;
	VertexPointSou[1].y -=DegY;

	VertexPointSou[2].x -=DegX;
	VertexPointSou[2].y -=DegY;

	VertexPointSou[3].x -=DegX;
	VertexPointSou[3].y -=DegY;


	this->PointRotation.x-=DegX;
	this->PointRotation.y-=DegY;
}



void	BOARD::SetRotation(float	_Rotation)
{

	{
		this->Rotation = _Rotation;
		_Rotation *=-1; 


		for(int i = 0;i<4;i++)
		{
			VertexPointSou[i].x -= PointRotation.x;
			VertexPointSou[i].y -= PointRotation.y;


			VertexPoint[i].x = (  VertexPointSou[i].x*cosf(_Rotation) + VertexPointSou[i].y*sinf(_Rotation) );
			VertexPoint[i].y = ( -VertexPointSou[i].x*sinf(_Rotation) + VertexPointSou[i].y*cosf(_Rotation) );


			VertexPointSou[i].x += PointRotation.x;
			VertexPointSou[i].y += PointRotation.y;

			VertexPoint[i].x += PointRotation.x;
			VertexPoint[i].y += PointRotation.y;
		}
	}
}


float	BOARD::GetRotation(void)
{
	return Rotation ;
}



void	BOARD::SetPointRotation(float	_x,float _y)
{
	this->PointRotation.x = _x;
	this->PointRotation.y = _y;
	this->PointRotation.x+=this->Position.x;
	this->PointRotation.y+=this->Position.y;
}
