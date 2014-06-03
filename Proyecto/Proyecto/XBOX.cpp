#include "stdafx.h"

XBOXcontroller::XBOXcontroller(int playerNumber){
	_controllerNum = playerNumber;
}

XINPUT_STATE XBOXcontroller:: getState(){
	ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));
	DWORD hue= XInputGetState(_controllerNum, &_controllerState);
	return _controllerState;
}

bool XBOXcontroller:: isConnected(){
	ZeroMemory(&_controllerState, sizeof(XINPUT_STATE));
	DWORD Result = XInputGetState(_controllerNum, &_controllerState);

	if(Result == ERROR_SUCCESS)
		return true;
	else
		return false;
	
}

void XBOXcontroller:: vibrate(int leftVal, int rightVal){
	XINPUT_VIBRATION Vibration;
	ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));
	Vibration.wLeftMotorSpeed = leftVal;
	Vibration.wRightMotorSpeed = rightVal;
	DWORD HUE=XInputSetState(_controllerNum, &Vibration);
}