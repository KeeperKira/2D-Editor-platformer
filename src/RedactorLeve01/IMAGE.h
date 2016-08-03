#pragma once

#include <d3d9.h>
#include <d3dx9.h>

struct PIXEL
{
	unsigned	char 	Blue;
	unsigned	char	Green;
	unsigned	char	Red ;
	unsigned	char	Alpha ;
};

struct VERTEX
{
	float x,y,z;//,rhw;
	DWORD color;
	float tu,ty;

};

class IMAGE
{
public:

	float Go;
	IDirect3DTexture9			*Texture;

	D3DXVECTOR3		Position;
	D3DXVECTOR3		Pos;

	int Width,Height;
	int SoursBlend,DestBlend;

	static LPD3DXSPRITE			pSpr;
	static LPDIRECT3DDEVICE9	pDevice;

protected:



	D3DXVECTOR2		Size;
	D3DXVECTOR2		PointRotation;
	RECT			Rect;

	D3DXVECTOR3		Center;



	//Color
	unsigned char	Alpha;
	unsigned char	Red;
	unsigned char	Green;
	unsigned char	Blue;

	float	Rotation;


private:







public:
	IMAGE(void);
	IMAGE(LPCWSTR filename);

	static	void	SetDirect(DIRECTX &DirectX);
	

	HRESULT		LoadImageFromArhive(TCHAR *Arhivename,TCHAR *Filename);
	HRESULT		CreateImage(int _Width,int _Height);


	virtual	HRESULT		LoadImageFromFile(LPCWSTR filename);

	virtual void		Draw();
	void				DrawMirror();
	virtual void		DrawCenter();

	virtual void		SetPosition			(D3DXVECTOR2 _Pos);
	virtual void		SetPosition			(POINT _Pos);
	virtual void		SetPosition			(float	_PosX,float _PosY);
	D3DXVECTOR3			GetPosition			(void);

	void				Move(D3DXVECTOR2 Offset);
	void				Move(float OffsetX);
	void				Move(float OffsetX,float OffsetY);
	void				Move(POINT Offset);


	void				SetARGB(int Alpha=255,int Red=255,int Green=255,int Blue=255);
	virtual void		SetSize(float	_SizeX,float _SizeY);

	void				SetRect(long top,long left,long right,long bottom);
	void				SetRect(RECT	&Rect);

	virtual void		SetRotation		(float	_Rotation);
	virtual	void		SetPointRotation(float	_x,float _y);

	D3DXVECTOR2			GetPointRotation();
	float				GetRotation();
	RECT				GetRect();


	D3DXVECTOR2			GetSize();
	unsigned char		GetAlpha(void);
	unsigned char		GetRed(void);
	unsigned char		GetGreen(void);
	unsigned char		GetBlue(void);

	PIXEL		GetPixel(int x, int y);
	void		SetPixel(int x, int y, PIXEL _Pixel);

	bool		PointCollide(D3DXVECTOR2 Point);
	bool		PointCollide(POINT Point);
	BOOL		Collide(IMAGE &Object2);

	virtual ~IMAGE(void);

};





//*****************Определения БОАРДА***************//



class BOARD: public IMAGE

{
	
public:

	VERTEX VertexPoint[4];
	VERTEX VertexPointSou[4];
	BOARD(void);


	int SoursBlend,DestBlend;

	virtual	HRESULT		LoadImageFromFile(LPCWSTR filename);


	virtual void		SetARGB			(int Alpha=255,int Red=255,int Green=255,int Blue=255);
	virtual void		SetSize			(float	_SizeX,float _SizeY);

	void				SetBlend		(int Sours,int Dest);

	virtual void		SetPosition			(D3DXVECTOR2 _Pos);
	virtual void		SetPosition			(float	_PosX,float _PosY);
	virtual	void		SetPointRotation	(float	_x,float _y);



	void				SetRotation		(float	_Rotation);
	float				GetRotation		(void);

	virtual void		Draw(void);

};











	









		
		



