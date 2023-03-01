// LLF.cpp: implementation of the LLF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LLF.h"
#include "Global.h"
#include "Tool.h"

#include <iostream>
#include <string>
#include <string.h>
#include"string"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define EXE_LEN 90  //����ִ������
/**
 *	1. ���㷨��Ҫ���ڿ���ռ���ȷ�ʽ�У���һ���������ɳڶȼ�Ϊ0ʱ��������������ռCPU���Ա�֤����ֹʱ���Ҫ���������

	2. ����ؼ�ʱ���ĸ��������ڵ��ɳڶȣ��������ڵ�ǰ���ڽ�ֹʱ��ǰ������������ڸý��̽����¸�����ǰ��������������ɳڶȡ�

	3. �����ֶ�������ɳڶ���ͬ��Ϊ��Сʱ�����ա�������δ���ȡ���ԭ����н��̵��ȡ�
 *
 */
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LLF::LLF()
{

}

LLF::~LLF()
{

}

//��ʼ����������ṹ�壬�ִ��ʱ��WCET����Ҫʱ��period����ֹʱ��deadline
void LLF::init_task(task_t *t, string name, int WCET, int period, int deadline, int cycle, int status, int join)
{
	t->name = name;
	t->WCET = WCET;
	t->period = period;
	t->deadline = deadline;
	t->cycle = cycle;
	t->status = status;
	t->join = join;
}

//��ʼ�������弯�ϣ��洢��������飩��������task������洢������task����Ŀ������ĳ���
void LLF::init_tasks(task_t t[], string name[], int WCET[], int period[], int deadline[], int cycle[], int status[], int join[], int numTasks)
{
    int i;
	for(i = 0; i < numTasks; i++)
	{
		init_task(&(t[i]),name[i], WCET[i],period[i],deadline[i], cycle[i] ,status[i], join[i]);
	}
}

//����task����һ��task�б��Ƶ���һ��task�б��У����������ô�����Ҫ����task��Ŀ
void LLF::copy_tasks(task_t tasks_to_be_copied[], task_t place_to_copy[], int numTasks)
{
    int i;
	for(i = 0; i < numTasks; i++)
	{
		place_to_copy[i].name = tasks_to_be_copied[i].name;
		place_to_copy[i].WCET = tasks_to_be_copied[i].WCET;
		place_to_copy[i].period = tasks_to_be_copied[i].period;
		place_to_copy[i].deadline = tasks_to_be_copied[i].deadline;
		place_to_copy[i].cycle = tasks_to_be_copied[i].cycle;
		place_to_copy[i].status = tasks_to_be_copied[i].status;
		place_to_copy[i].join = tasks_to_be_copied[i].join;
	}
}

void LLF::update_task(task_t *t, int WCET, int period, int deadline, int cycle, int join)
{
	t->WCET = WCET;
	t->period = period;
	t->deadline = deadline;
	t->cycle = cycle;
	t->join = join;
}

//��ӡtask
void LLF::print_task(task_t t)
{
    char c[1024];
	cout<<"task:"<<t.name;
	sprintf(c," exe time: %u period: %u deadline: %u \n", t.WCET, t.period, t.deadline);
	strcat(c,"task:");

	char ts[1024];
	sprintf(ts," exe time: %u period: %u deadline: %u \n", t.WCET, t.period, t.deadline);
	strcat(c,ts);
	tool.writeRs(c);
}

//��ӡtask�б�
void LLF::print_tasks(task_t t[], int numTasks)
{
    int i;
	for (i = 0; i < numTasks; ++i)
	{
		print_task(t[i]);
	}

}

void LLF::set_schedule(string schedule[], string name, int index)
{
	schedule[index] = name;
}

//LLF�㷨ʵ��
int LLF::llf(task_t ori_t[], task_t t[], int numTasks,int time)
{//��Ϊ�Ƕ�ÿ��ʱ�����жϣ��������ﴫ��ʱ�Դ��˵�ǰʱ�䣬WCET������ʱ����Ϊ����ʱ��+��ǰʱ��
	int least_index = 0;
	int least_laxity = 99999; //��ʼ������ɳڶȣ�����Ϊint���ֵ��
	int current_laxity; //��ǰ�ɳڶ�
	int i;
	int flag = 0;
	for (i = 0; i < numTasks; i++)
	{//�������е�task
		if(t[i].WCET<=0) {
			t[i].cycle++;
			t[i].WCET = ori_t[i].WCET;
			t[i].period = ori_t[i].period;
			t[i].deadline = ori_t[i].deadline*t[i].cycle;
			t[i].join = time;
			t[i].status = 1;
		}

		if(t[i].status == 0)//task��δִ����
		{
			current_laxity = t[i].deadline - t[i].WCET - time; //�����ɳڶ�=��ֹʱ��-ʣ����Ҫִ�е�ʱ��-��ǰʱ��
		} else { //�Ѿ�ִ����
			current_laxity = 99999;
			int temp = t[i].deadline - t[i].WCET - time;
			if (temp<=0 && t[i].WCET>0) { //���ɳڶȼ���Ϊ0��ͬʱ��δִ����ʱ����������
				//����0������ִ��y
				t[i].status = 0;
				current_laxity = temp;
			} else {
				flag ++;
			}
		}
			// cout<<time<<"ʱ"<<t[i].name<<t[i].cycle<<"���ɳڶ�="<<current_laxity<<" ";

		if(current_laxity < least_laxity)
		{//��������
			least_index = i;
			least_laxity = current_laxity;
		}
	}
	if(flag==numTasks) {
		//����������һ���׶ζ�δ�ı�temp״̬��
		int m = 999;
		int index = 0;
		for(i=0;i<numTasks;i++) {
			//Ѱ��ʱ���
			if(t[i].join < m) {
				m = t[i].join;
				index = i;
			}
		}
		// cout<<"�ؼ��ڵ㣬ѡ��->"<<t[index].name<<t[index].cycle;
		if(t[index].WCET<=0) { //ֱ�Ӹ��»���
			t[index].cycle++;
			t[index].WCET = ori_t[index].WCET;
			t[index].period = ori_t[index].period;
			t[index].deadline = ori_t[index].deadline*t[index].cycle;
			t[index].join = time;
		}
		t[index].status = 0;
		least_index = index;
	}
	// cout<<endl;
	return least_index;
}

void LLF::sim_schedule(task_t t[], int numTasks, string schedule[], int schedule_length)
{
    //����ԭ�����
	task_t placeholder_task[numTasks];
	copy_tasks(t, placeholder_task, numTasks);

	int current_task;//��ǰ��������

	int i;

	for(i = 0; i < schedule_length; i++)
	{//��ÿһ��ʱ������task
		schedule[i] = "None"; //����ʱ����ʼ��

		//������ǰʱ���Ӧ��llf���������
		int time = i; //ʱ��
		current_task = llf(t,placeholder_task, numTasks, time); //����llf�㷨���޸�#1

		//ִ������ɳڶȶ�Ӧ������ִ��һ��
		if (placeholder_task[current_task].WCET > 0)
			placeholder_task[current_task].WCET -= 1;

		//ʱ�������
		int j;
		for (j = 0; j < numTasks; j++)
		{//������������

			//���˽�ֹʱ���Ժ�
			if(placeholder_task[j].deadline <= i)   //���ﵱǰʱ��
			{//�������û��ִ����
				if(placeholder_task[j].WCET > 0)    //������Ȼû��ִ����
				{//����ʱ�������һ���ϴ��ֵռλ�������´αȽ�
					string loss = "cannot finish: " + placeholder_task[j].name + to_string(placeholder_task[j].cycle);
					set_schedule(schedule, loss, i);
				}
			}

			//ִ����֮��
			if(placeholder_task[j].status==1 && placeholder_task[j].WCET <= 0) {
				placeholder_task[j].cycle++;
				placeholder_task[j].WCET = t[j].WCET;
				placeholder_task[j].period = t[j].period;
				placeholder_task[j].deadline = t[j].deadline*placeholder_task[j].cycle;
				placeholder_task[j].join = i;
			}

		}
		string task_name = placeholder_task[current_task].name;
		string task_cycle = to_string(placeholder_task[current_task].cycle);
		task_name.append(task_cycle);
		set_schedule(schedule, task_name, i);
	}
}

void LLF::print_schedule(string schedule[], task_t t[], int length)
{//��ӡʱ���
	int i;
	char c[4096];
	for (i = 0; i < length; ++i)
	{//���������е�ִ�е�
		cout<<"time:"<<i<<", current_task:"<<schedule[i]<<endl;
	    strcat(c,"time:");
	    char *ci = new char;
        sprintf(ci,"%d",i);
	    strcat(c,ci);
	    strcat(c,",current_task:");
	    strcat(c,schedule[i].c_str());
	    strcat(c,"\n");
	}
	tool.writeRs(c);
}

/**************************2. **************************************/

void LLF::init_task(task_t *t, string name, int WCET, int period, int deadline, int cycle)
{
	t->name = name;
	t->WCET = WCET;
	t->period = period;
	t->deadline = deadline;
	t->cycle = cycle;
}

void LLF::init_tasks(task_t t[], string name[], int WCET[], int period[], int deadline[], int cycle[], int numTasks)
{
	int i;
	for(i = 0; i < numTasks; i++)
	{
		init_task(&(t[i]),name[i], WCET[i],period[i],deadline[i],cycle[i]);
	}
}

void LLF::copy_tasks2(task_t tasks_to_be_copied[], task_t place_to_copy[], int numTasks)
{
	int i;
	for(i = 0; i < numTasks; i++)
	{
		place_to_copy[i].name = tasks_to_be_copied[i].name;
		place_to_copy[i].WCET = tasks_to_be_copied[i].WCET;
		place_to_copy[i].period = tasks_to_be_copied[i].period;
		place_to_copy[i].deadline = tasks_to_be_copied[i].deadline;
		place_to_copy[i].cycle = tasks_to_be_copied[i].cycle;
	}
}

int LLF::llf2(task_t t[], int numTasks)
{
	int least_index = 0;
	int least_laxity = 99999;
	int current_laxity;
	int i;
	for (i = 0; i < numTasks; i++)
	{
		if(t[i].WCET > 0)
		{
			current_laxity = t[i].deadline - t[i].WCET;
		}

		if(current_laxity < least_laxity)
		{
			least_index = i;
			least_laxity = current_laxity;
		}
	}
	return least_index;
}

void LLF::set_schedule(string schedule[], task_t t[], int index, int time)
{
	string name =  t[index].name;
	name.append(to_string(t[index].cycle));
	schedule[time] = name;
}

void LLF::sim_schedule2(task_t t[], int numTasks, string schedule[], int schedule_length)
{
	task_t placeholder_task[numTasks];
	copy_tasks2(t, placeholder_task, numTasks);

	int current_task;
	int i;
	for(i = 0; i < schedule_length; i++)
	{
		schedule[i] = "None";

		current_task = llf2(placeholder_task, numTasks);

		placeholder_task[current_task].WCET -= 1;

		int j;
		for (j = 0; j < numTasks; j++)
		{
			placeholder_task[j].period -= 1;
			placeholder_task[j].deadline -= 1;

			if(placeholder_task[j].deadline <= 0)
			{
				if(placeholder_task[j].WCET > 0)
				{
					//���Ϸ�����
					string loss = "cannot finish: " + placeholder_task[j].name + to_string(placeholder_task[j].cycle);
					set_schedule(schedule, loss, i);
				}
			}

			if(placeholder_task[j].period <= 0)
			{
				placeholder_task[j].WCET = t[j].WCET;
				placeholder_task[j].period = t[j].period;
				placeholder_task[j].deadline = t[j].deadline;
				placeholder_task[j].cycle ++;
			}

		}

		//����
		set_schedule(schedule, placeholder_task, current_task, i);
	}
}
void LLF::tip(){
    char c[1024];
    cout<<"---------------LLF----------------\n";
    cout<<"(1)A��B������������ִ��;\n";
    cout<<"(2)A��B��C��D������������ִ��;\n";
    cout<<"����������ѡ��\n";
    strcat(c,"---------------LLF----------------\n");
    strcat(c,"(1)A��B������������ִ��;\n");
    strcat(c,"(2)A��B��C��D������������ִ��;\n");
    strcat(c,"����������ѡ��\n");
    tool.writeRs(c);

}
void LLF::doLLF()
{
	/**
	 * 1. �޼��ʱ�䣬��һ�������Ժ�ֱ�ӽ��루�����У�
	 * 2. �м��ʱ��period
	 */
    cout<<"tesk";
    tip();
	int choose;
	cin>>choose;
    int NUM_TASKS = 3;

	if(1==choose) {
		/**1. ��ʼ������**/
		//>>>>>>>>>>>>>>���ļ��ж�ȡ�������޸ĸ�ʽ<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
		NUM_TASKS = 2;								//�������
		string name[NUM_TASKS] = {"A","B"};			//task��ʶ��
		int WCET[NUM_TASKS] = {10,25};     //��������ִ����Ҫ��ʱ��
		int deadline[NUM_TASKS] = {20,50}; //�����һ�������ֹʱ��
		int period[NUM_TASKS] = {20,50};            //���徭���೤ʱ���Ժ��ֻ����µ��������
		int cycle[NUM_TASKS] = {1,1};				//��ʼֵ��Ϊ1��1
		int status[NUM_TASKS] = {0,0};				//��ʼֵ״̬Ϊ1��1
		int join[NUM_TASKS] = {0,0};				//����ʱ���Ϊ0��0
		//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		task_t tasks[NUM_TASKS];
		init_tasks(tasks, name, WCET, deadline, period, cycle, status, join, NUM_TASKS); //��ʼ�������

		print_tasks(tasks, NUM_TASKS);
		printf("\nexecution length: %u\n", EXE_LEN);
		char s[1024];
		sprintf(s,"\nexecution length: %u\n", EXE_LEN);
		tool.writeRs(s);

		/**2. �����ʱ�������㷨Ӧ��ִ�е�task**/
		string schedule[EXE_LEN];                             //ʱ�����У�ִ�г��ȵ�ÿһ����λ����ʱ�����У�
		sim_schedule(tasks, NUM_TASKS, schedule, EXE_LEN);
		/**3. ��ӡ������ʱ�����б��ȱʧֵ**/
		print_schedule(schedule, tasks, EXE_LEN);//��ӡ���հ��ŵ�ʱ���
	} else if (2==choose){
		//>>>>>>>>>>>>>���ļ��ж�ȡ�������޸����鳤��NUM_TASK���������ֵ
		NUM_TASKS = 4;										//�������
		string name[NUM_TASKS] = {"A","B","C","D"};			//���񳤶�
		int WCET[NUM_TASKS] = {1,2,4,6};			//����ִ��ʱ��
		int deadline[NUM_TASKS] = {6,8,12,24};		//�����ֹʱ��
		int period[NUM_TASKS] = {6,8,12,24};		//������ý����µ�����
		int cycle[NUM_TASKS] = {1,1,1,1};			//ִ������
		//�����ֵͳһ��ʼ��<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

		task_t tasks[NUM_TASKS];
		init_tasks(tasks, name, WCET, period, deadline, cycle, NUM_TASKS);

		print_tasks(tasks, NUM_TASKS);

		char s[1024];
		printf("task %u: idle\n", NUM_TASKS);
		printf("\nexecution length: %u\n", EXE_LEN);

        sprintf(s,"task %u: idle\n", NUM_TASKS);
        tool.writeRs(s);

		sprintf(s,"\nexecution length: %u\n", EXE_LEN);
		write(s);

		string schedule[EXE_LEN];
		sim_schedule2(tasks, NUM_TASKS, schedule, EXE_LEN);
		print_schedule(schedule, tasks, EXE_LEN);
	} else {
		cout<<"�������"<<endl;
	}
}
