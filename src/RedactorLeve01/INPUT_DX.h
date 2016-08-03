#pragma once

#include <dinput.h>

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dinput.lib")
#pragma comment(lib,"dxguid.lib")


typedef enum POV{
	UP			= 0,
	UPRIGHT		=	4500,
	RIGHT		=	9000,
	DOWNRIGHT	=	13500,
	DOWN		=	18000,
	DOWNLEFT	=	22500,
	LEFT		=	27000,
	UPLEFT		=	31500,
}POV;




class INPUT_DX
{
public:

	IDirectInput8					*pInput;

	IDirectInputDevice8				*pKeyboard;
	IDirectInputDevice8				*pMouse;
	IDirectInputDevice8				*pJoystick;

	char  keyboard [256];

	typedef struct DIJOYSTATE {
    LONG lX;
    LONG lY;
    LONG lZ;
    LONG lRx;
    LONG lRy;
    LONG lRz;
    LONG rglSlider[2];
    DWORD rgdwPOV[4];
    BYTE rgbButtons[32];
} DIJOYSTATE, *LPDIJOYSTATE;


	DIJOYSTATE	Joystick;

	typedef  struct 
	{
		long x,y,z;
		BYTE buttons[4];
	}DIMOUSE;

	DIMOUSE	Mouse;


	INPUT_DX(void);
	HRESULT CreateInput(HINSTANCE);
	HRESULT CreateKeyboard(HWND hWnd);
	HRESULT CreateMouse(HWND hWnd);
	HRESULT CreateJoystick(HWND hWnd);

	BOOL	JoystickDown(unsigned char JoystickButton);
	BOOL	JoystickPOV(POV Joy);
	BOOL	MouseDown(char Mouskey);
	BOOL	MouseScroll(char Mouskey);
	BOOL	KeyDown(unsigned char key);
	BOOL	Update(void);	


	~INPUT_DX(void);
};
