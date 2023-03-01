// RR.cpp: implementation of the RR class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RR.h"
#include "Global.h"
#include "Tool.h"

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<memory.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
//���������ȷ���ʹ��ʱ��Ƭ��ת

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RR::RR()
{

}

RR::~RR()
{

}


void RR::doRR(job jobs[], int num)
{
	Tool tool;
	tool.writeRs("--------------------------------------------------------------------------RR---");



	double sum1=0; //�ܵĵȴ�ʱ��
	double sum2=0; //�ܵ���תʱ��
	double sum3=0; //�ܵĴ�Ȩ��תʱ��

	vector<job> jobList;     //jobList����
	int time_unit = 10;//ʱ��Ƭ����
	for(int i=1;i<=num;i++)
	{
		jobList.push_back(jobs[i]);
	}

	queue<job>Ready;     //��������
	sort(jobList.begin(),jobList.end(),cmp);
	int begin =(*jobList.begin()).reach_time;
	Ready.push(*jobList.begin());
	jobList.erase(jobList.begin());
	char s[2048]="";
	char s1[1024]="";
    while(!jobList.empty()||!Ready.empty()){
	      while(!jobList.empty()&&begin>=(*jobList.begin()).reach_time){ 	//������ҵ��������������
			 	Ready.push(*jobList.begin());
        	    jobList.erase(jobList.begin());
		   }
		if(Ready.front().finish_time + time_unit < Ready.front().need_time){ 	//ʱ��Ƭ����û������,�����β

			sprintf(s1,"%d ����ҵִ���� %d\n",Ready.front().number,time_unit);
			strcat(s,s1);

			Ready.front().finish_time += time_unit;
			begin += time_unit;
			while(!jobList.empty()&&begin>=(*jobList.begin()).reach_time){ 	//������ҵ��������������
			 	Ready.push(*jobList.begin());
        	    jobList.erase(jobList.begin());
		    }

			Ready.push(Ready.front());
			Ready.pop();
		}
		else{ //��ҵ������
			if(Ready.front().need_time - Ready.front().finish_time<time_unit){
				time_unit-=Ready.front().need_time - Ready.front().finish_time;
			}
			else{
				time_unit=10;
			}

			sprintf(s1,"%d ����ҵִ���� %d\n",Ready.front().number,time_unit);
			strcat(s,s1);

			begin += time_unit;
			Ready.front().finish_time = begin;
			Ready.front().wait_time = Ready.front().finish_time-Ready.front().reach_time-Ready.front().need_time;
			Ready.front().tr_time = Ready.front().finish_time - Ready.front().reach_time;
			Ready.front().wtr_time = (double)Ready.front().tr_time / Ready.front().need_time;
			sum1+=Ready.front().wait_time;
			sum2+=Ready.front().tr_time;
			sum3+=Ready.front().wtr_time;

            sprintf(s1, "ִ�������ҵ�� %d ����ҵ���ȴ�ʱ���� %d ,��תʱ���� %d ,��Ȩ��תʱ���� %.2f\n",Ready.front().number,Ready.front().wait_time
			,Ready.front().tr_time,Ready.front().wtr_time);
			strcat(s,s1);

			//�Ӿ����������Ƴ���ҵ
			Ready.pop();

			if(Ready.empty()&&!jobList.empty()){
				sort(jobList.begin(),jobList.end(),cmp);

				sprintf(s1,"�ҵ���ǰ�������ҵ��: %d\n",(*jobList.begin()).number);
				strcat(s,s1);

				begin = (*jobList.begin()).reach_time;

			}
			if(time_unit<10){
				time_unit=10;
			}
		}
	}
		strcat(s, "--------������ҵ�������------\n");
	    sprintf(s1,"ƽ���ȴ�ʱ��: %.2f ƽ����תʱ��: %.2f ƽ����Ȩ��תʱ��: %.2f\n\n\n",sum1/num,sum2/num,sum3/num);
	    strcat(s,s1);
	    tool.writeRs(s);
	    printf("�������,�����...\n\n");
}

bool RR::cmp(job a, job b)
{
	return a.reach_time<b.reach_time;
}

