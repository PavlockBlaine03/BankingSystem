#pragma once
#include <iostream>
using namespace std;

class Login
{
protected:
	string mUsername = "";
	string mPassword = "";
	bool mLoginStatus = false;

public:
	Login(string user, string pass) { mUsername = user; mPassword = pass; }

	bool isLogin(string user, string pass)
	{
		if (user == mUsername && pass == mPassword)
		{
			mLoginStatus = true;
			return mLoginStatus;
		}
		else if (user != mUsername && pass != mPassword)
		{
			cout << "Username or password is Incorrect.\n";
			return false;
		}
	}

};