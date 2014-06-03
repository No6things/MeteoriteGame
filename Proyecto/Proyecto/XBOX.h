#ifndef _XBOX_CONTROLLER_H_
#define _XBOX_CONTROLLER_H_

#pragma once
class XBOXcontroller{
	private:
		//Atributtes:
		XINPUT_STATE _controllerState;
		int _controllerNum;

	public:
		//Constructor: 
		XBOXcontroller(int);

		//Methods:
		XINPUT_STATE getState();
		bool isConnected();
		void vibrate(int leftVal = 0, int rightVal = 0);
};

#endif