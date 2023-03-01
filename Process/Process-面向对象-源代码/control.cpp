// control.cpp: implementation of the Ccontrol class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Control.h"
#include "Global.h"
#include "Tool.h"
#include "FCFS.h"
#include "HPF.h"
#include "HRRF.h"
#include "LLF.h"
#include "RR.h"
#include "SJF.h"

#include <string>
#include<Windows.h>
#include <iostream>
#include <cstdio>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<queue>
#define getpch(type) (type*)malloc(sizeof(type))
#define inf 0x3f3f3f
#include <fstream>
#include<time.h> 

using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CControl::CControl()
{
	
}

CControl::~CControl()
{

}

void CControl::welcome()
{
	int all_block_num = 30;
	for (int i = 0; i<all_block_num; i++)
	{
		if (i<all_block_num-1)
		{
			printf("\r��ȡ��[%.2lf%%]:", i*100.0 / (all_block_num - 1));
		}
		else
		{
			printf("\r��ȡ���[%.2lf%%]:", i*100.0 / (all_block_num - 1));
		}
		int show_num = i * 20 / all_block_num;
		for (int j = 1; j <= show_num; j++)
		{
			cout << "��";
			Sleep(5);
		}
	}
	cout << endl;
}

void CControl::run()
{
	system("color 5f"); //�ı���ɫ

	initialJobs(); //��ʼ��Ϊ0
	num = readJobData(); //��ȡ�����ļ�,������ҵ��Ŀ
	
	getUserChoice();
}

//////////////////////////////////////////////////////////���±��ڲ�����

void CControl::getUserChoice()
{
        printf("\n��ѡ������һ�ֵ����㷨:\n");
		printf("(1)�����ȷ���FCFS\n");
		printf("(2)����ҵ����SJF\n");
		printf("(3)����Ӧ������HRRF\n");
		printf("(4)����Ȩ��������HPF\n");
		printf("(5)ʱ��Ƭ��תRR\n");
	//	printf("(6)����ɳڶ�LLF\n");
	//	printf("(7)���м��㷨BANK\n");
		printf("(9)�Զ�ִ��1-6�����㷨\n");
		printf("(0)�˳�\n");
		//ʵ����
		FCFS fcfs;
		SJF sjf;
		HRRF hrrf;
		HPF hpf;
		RR rr;
	//	LLF llf;
	//  BANK bank;
	enum process{ FCFS=1, SJF=2, HRRF=3, HPF=4, RR=5, LLF=6, ALL=9, EXIT=0 } choice;
	//�ж��û�ѡ��
	while(choice != 0){
		printf("������һ�����֣�");
		scanf("%d",&choice);
		switch (choice){
		case FCFS:fcfs.doFCFS(jobs,num);addLog("FCFS"); initialJobsAgain(); break;
		case SJF:sjf.doSJF(jobs,num);addLog("SJF");initialJobsAgain(); break;
		case HRRF:hrrf.doHRRF(jobs,num);addLog("HRRF");initialJobsAgain(); break;
		case HPF:hpf.doHPF(jobs,num);addLog("HPF");initialJobsAgain(); break;
		case RR:rr.doRR(jobs,num);addLog("RR");initialJobsAgain(); break;
	//	case LLF:fun_llf();break;
	//	case BANK:bank.doBank();addLog("BANK");break;
		case ALL:
			addLog("ALL Commend");
		    fcfs.doFCFS(jobs,num);
		    sjf.doSJF(jobs,num);
		    hrrf.doHRRF(jobs,num);
		    hpf.doHPF(jobs,num);
		    rr.doRR(jobs,num);
		    printf("ִ����ɣ����Զ�Ϊ��������ļ���~~~������(^v^)������~~~\n\n");
            system("start \"\" \"output.txt");
			system("start \"\" \"log.txt");
            break;
			
		case 0:printf("�˳�����\n");break;
		}
	}
}

void CControl::addLog(char *commend)
{
	time_t nowtime;
    struct tm* p;;
    time(&nowtime);
    p = localtime(&nowtime);

    char time[100] = "";
    sprintf(time, "%04d-%02d-%02d %02d:%02d:%02d", p->tm_year+1900, p->tm_mon+1, p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
	
	strcat(time, " �û�ִ���� ");
	strcat(time, commend);
	strcat(time, " ������\n\n");
	Tool tool;
	tool.writeLog(time);
}


void CControl::initialJobs()
{
    for(int i=0; i<MAX_NUM; i++)
		{
			jobs[i].excellent=0;
			jobs[i].need_time=0;
			jobs[i].number=0;
			jobs[i].privilege=0;
			jobs[i].reach_time=0;
			jobs[i].run_time=0;
			jobs[i].start_time=0;
			jobs[i].tr_time=0;
			jobs[i].visited=false;
			jobs[i].wait_time=0;
			jobs[i].wtr_time=0;
			jobs[i].finish_time=0;
			jobs[i].reached=false;
		}
}

int CControl::readJobData()
{
	int num =1;
    char buffer[150];
    string line;
    // �Զ�ģʽ���ļ�
    ifstream infile("job.txt");
    string title;
    getline(infile, title);
    while (infile.getline(buffer,120))//ÿһ��
    {
        char *p;
        const char *d = " ,\r\n";
        p = strtok(buffer,d);
        int n=0;//����
        char c;
        while(p) //ÿ���е�ÿһ��
        {
            n=n+1;
            if(n==1)
            {
                if(isdigit(p[0]))//������
                    sscanf(p,"%d",&jobs[num].number);
                else
                    sscanf(p,"%c%d",&c,&jobs[num].number);
            }

            if(n==2)
                jobs[num].reach_time=atoi(p);
            if(n==3)
                jobs[num].need_time=atoi(p);
            if(n==4)
                jobs[num].privilege=atoi(p);
            p=strtok(NULL,d);
        }
        num++;
    }
    num--;
    // �رմ򿪵��ļ�
    infile.close();
    printf("read data success!\n");
    printf("��ҵ������Ϊ: %d\n\n",num);
    cout<<title<<endl;
    for(int j=1; j<=num; j++)
    {
        printf("p%d\t%d\t\t%d\t\t%d\n",jobs[j].number,jobs[j].reach_time,jobs[j].need_time,jobs[j].privilege);
    }
    return num;
}

void CControl::initialJobsAgain()
{
    for(int i=1; i<=num; i++)
		{
			jobs[i].finish_time=0;
			jobs[i].excellent=0;
			jobs[i].tr_time=0;
			jobs[i].wtr_time=0;
			jobs[i].wait_time=0;
			jobs[i].visited=false;
		}
}


