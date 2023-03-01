// LLF.h: interface for the LLF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LLF_H__56A2F2BB_4CEE_41D9_A0C5_9C2EF3626580__INCLUDED_)
#define AFX_LLF_H__56A2F2BB_4CEE_41D9_A0C5_9C2EF3626580__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Global.h"
#include "Tool.h"

#include <string>
using namespace std;

class LLF  
{
public:
	LLF();
	virtual ~LLF();
	doLLF();

private:
	//llf�ĵ����ýṹ
	typedef struct
	{
		string name;			//��
		int WCET;		//ִ��ʱ��
		int period;	//����ʱ�䣬Ĭ��Ϊִ������������
		int deadline;			//��ֹʱ��
		int cycle;				//Ŀǰִ�е�����
		int status; 			//��¼��ǰ�����ִ��״̬��δִ����Ϊ0���ڽ�ֹǰִ��������Ϊ1
		int join;				//����ʱ��
	} task_t;

	Tool tool; //���������ļ��Ĺ���
	task_t init1();
	task_t init2();
	void init_task(task_t *t, string name, int WCET, int period, int deadline, int cycle, int status, int join);
	void init_tasks(task_t t[], string name[], int WCET[], int period[], int deadline[], int cycle[], int status[], int join[], int numTasks);
	void copy_tasks(task_t tasks_to_be_copied[], task_t place_to_copy[], int numTasks);
	void update_task(task_t *t, int WCET, int period, int deadline, int cycle, int join);
	void print_task(task_t t);
	void print_tasks(task_t t[], int numTasks);
	void set_schedule(string schedule[], string name, int index);
	int llf(task_t ori_t[], task_t t[], int numTasks,int time);
	void sim_schedule(task_t t[], int numTasks, string schedule[], int schedule_length);
	void print_schedule(string schedule[], task_t t[], int length);
	void init_task(task_t *t, string name, int WCET, int period, int deadline, int cycle);
	void init_tasks(task_t t[], string name[], int WCET[], int period[], int deadline[], int cycle[], int numTasks);
	void copy_tasks2(task_t tasks_to_be_copied[], task_t place_to_copy[], int numTasks);
	int llf2(task_t t[], int numTasks);
	void set_schedule(string schedule[], task_t t[], int index, int time) ;
	void sim_schedule2(task_t t[], int numTasks, string schedule[], int schedule_length);

};

#endif // !defined(AFX_LLF_H__56A2F2BB_4CEE_41D9_A0C5_9C2EF3626580__INCLUDED_)
