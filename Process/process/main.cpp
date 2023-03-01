#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "schedule.h"

FILE *ouput,*input;
volatile bool exiting;
extern applyQueue* queue;
extern HANDLE hSchedule;
extern CRITICAL_SECTION cs_ReadyList;

void help()
{
	printf("�������̣�\t\tcreate name time\t(create p0 3)\n");
	printf("�������̣�\t\tremove name\t(remove p0)\n");
	printf("�鿴��ǰϵͳ״̬��\tcurrent\n");
	printf("�˳�ϵͳ��\t\texit\n");
}

int main()
{
	queue->head=NULL;
	queue->tail=NULL;
	queue->applyNum=0;

	ouput=fopen("ouput.txt","w");
	init();

	char command[20]={0};
	char name[20]={0};
	int time;
	//��ʼ�������������
	EnterCriticalSection(&cs_ReadyList);
	input=fopen("input.txt","r");
	{
		for(int i=0;i<5;i++)
		{
			fscanf_s(input,"%s%d",name,&time);
			createProcess(name,time);
		}
	}
	fclose(input);
	LeaveCriticalSection(&cs_ReadyList);

	while(strcmp(command,"exit")!=0)
	{
		printf("COMMAND>");
		scanf_s("%s",command);
		if(strcmp(command,"exit")==0)
		{
			break;
		}
		else if(strcmp(command,"create")==0)
		{

			scanf_s("%s %d",name,&time);
			addApplyProcess(name,time);
		}
		else if(strcmp(command,"remove")==0)
		{

			scanf_s("%s",name);
			removeProcess(name);
		}
		else if(strcmp(command,"current")==0)
		{
			printCurrent();
		}
		else if(strcmp(command,"help")==0)
		{
			help();
		}
		else
		{
			printf("������������������\n");
		}

	}

	exiting=true;
	WaitForSingleObject(hSchedule,1000);
	CloseHandle(hSchedule);
	fclose(ouput);
	return 0;
}