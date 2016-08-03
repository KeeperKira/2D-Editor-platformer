#include "StdAfx.h"
#include "INPUT_DX.h"

INPUT_DX::INPUT_DX(void)
{
	Mouse.x=0;
	Mouse.y=0;
	Mouse.z=0;
	pInput=NULL;
	pKeyboard=NULL;
	pMouse=NULL;
}



HRESULT	INPUT_DX::CreateInput(HINSTANCE hInst)
{
		HRESULT hr;
		if(FAILED(hr = DirectInput8Create(hInst,DIRECTINPUT_VERSION,IID_IDirectInput8,(void**)&pInput,NULL))) //Создание обьекта Инпоут
			return hr;
		return S_OK;
}



HRESULT	INPUT_DX::CreateKeyboard(HWND hWnd)
{
	HRESULT hr;
	
	hr = pInput -> CreateDevice(GUID_SysKeyboard,&pKeyboard,NULL);
	if FAILED(hr)
	{

		return hr;
	}
	//Установка формата считываемых данных с девайса.
	hr = pKeyboard -> SetDataFormat(&c_dfDIKeyboard);
	if FAILED(hr)
	{
//		DeleteInput();
		return hr;
	}

	//Определение кооперативного уровня для данного девайса
	hr = pKeyboard -> SetCooperativeLevel(hWnd,DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	if FAILED(hr)
	{
		return hr;
	}

	return S_OK;


}



HRESULT	INPUT_DX::CreateMouse(HWND hWnd)
{
	HRESULT hr;

	hr= pInput -> CreateDevice(GUID_SysMouse,&pMouse,NULL);
	if FAILED(hr)
	{

		return hr;
	}


		//Установка формата считываемых данных с девайса.
	hr= pMouse -> SetDataFormat(&c_dfDIMouse);
	if FAILED(hr)
	{
//		DeleteInput();
		return hr;
	}

	hr=pMouse -> SetCooperativeLevel(hWnd,DISCL_FOREGROUND | DISCL_NONEXCLUSIVE );
	if FAILED(hr)
	{
//		DeleteInput();
		return hr;
	}
	return S_OK;
}


HRESULT	INPUT_DX::CreateJoystick(HWND hWnd)
{
	HRESULT hr;

	hr= pInput -> CreateDevice(GUID_Joystick,&pJoystick,NULL);
	if FAILED(hr)
	{

		return hr;
	}


		//Установка формата считываемых данных с девайса.
	hr= pJoystick -> SetDataFormat(&c_dfDIJoystick);
	if FAILED(hr)
	{
//		DeleteInput();
		return hr;
	}

	hr=pJoystick -> SetCooperativeLevel(hWnd,DISCL_FOREGROUND | DISCL_NONEXCLUSIVE );
	if FAILED(hr)
	{
//		DeleteInput();
		return hr;
	}
	return S_OK;
}





BOOL	INPUT_DX::MouseDown(char Mouskey)
{
//	pMouse -> Acquire();
//	if(FAILED(pMouse->GetDeviceState(sizeof(DIMOUSE),(LPVOID)&Mouse))) 
//		return FALSE;

	if (Mouskey>4)
		return FALSE;
	else if(Mouse.buttons[Mouskey]&0X80)
		return TRUE;
	return FALSE;

}



BOOL	INPUT_DX::MouseScroll(char Mouskey)
{
	if(Mouskey<0)
		if (Mouse.z<0)
		{
			return	TRUE;
		}

	if(Mouskey>0)
		if (Mouse.z>0)
		{
			return	TRUE;
		}
	return FALSE;
}




BOOL	INPUT_DX::KeyDown(unsigned char key)
{
	pKeyboard -> Acquire();
	pKeyboard -> GetDeviceState(sizeof(keyboard),(LPVOID)&keyboard);

	if(keyboard[key]&0x80)
		return TRUE;

	return FALSE;
}

BOOL	INPUT_DX::JoystickDown(unsigned char JoystickButton)
{
	pJoystick -> Acquire();
	pJoystick -> GetDeviceState(sizeof(Joystick),(LPVOID)&Joystick);

	if(Joystick.rgbButtons[JoystickButton]&0x80)
		return TRUE;

	return FALSE;
}

BOOL	INPUT_DX::JoystickPOV(POV Joy)
{
	pJoystick -> Acquire();
	pJoystick -> GetDeviceState(sizeof(Joystick),(LPVOID)&Joystick);

	if(Joystick.rgdwPOV[0] == Joy)
		return TRUE;

	return FALSE;
}


BOOL	INPUT_DX::Update(void)
{
	pMouse -> Acquire();
	if(FAILED(pMouse->GetDeviceState(sizeof(DIMOUSE),(LPVOID)&Mouse))) 
		return FALSE;
	return TRUE;

}


INPUT_DX::~INPUT_DX(void)
{
	if(pInput!=NULL)
	{
		if(pMouse!=NULL)
		{
			pMouse->Unacquire();
			pMouse->Release();
		}

		if(pKeyboard!=NULL)
		{
			pKeyboard->Unacquire();
			pKeyboard->Release();
		}

		pInput->Release();
	}
}


