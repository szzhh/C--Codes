// Tool.cpp: implementation of the Tool class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Tool.h"

#include <fstream>
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Tool::Tool()
{

}

Tool::~Tool()
{

}


void Tool::writeRs(char *data)  // �����������浽�ļ�
{
	// ��дģʽ���ļ�
	ofstream outfile;
	outfile.open("output.txt", ios::app);
	// ���ļ�д���û����������
	outfile << data << endl;
    // �رմ򿪵��ļ�
	outfile.close();
}
void Tool::writeLog(char *log)  // ������־ 
{
	// ��дģʽ���ļ�
	ofstream outfile;
	outfile.open("log.txt", ios::app);
	// ���ļ�д���û����������
	outfile << log << endl;
    // �رմ򿪵��ļ�
	outfile.close();
}

