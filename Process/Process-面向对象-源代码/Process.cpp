// Process.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Control.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	CControl control;

	control.welcome();  //ҳ�����3s���ң�����ȥ��
	control.run();
	return 0;
}

