// FCFS.cpp: implementation of the FCFS class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FCFS.h"
#include "Global.h"
#include "Tool.h"
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FCFS::FCFS()
{

}

FCFS::~FCFS()
{

}

void FCFS::doFCFS(job jobs[], int num)
{
	Tool tool;
	tool.writeRs("--------------------------------------------------------------------FCFS------");
	int i,j,temp;
	double sum1=0; //�ܵĵȴ�ʱ��
	double sum2=0; //�ܵ���תʱ��
	double sum3=0; //�ܵĴ�Ȩ��תʱ��
	for(i = 1;i <= num; i++){
		order[i] = jobs[i].reach_time;
		ready[i] = i;
	}
	//ð������
	for(i = 1; i <= num; i++){//���յ���ʱ���С����
		for(j = 1; j <= num-i; j++){
			if(order[j] > order[j+1]){
				temp = order[j];
				order[j] = order[j+1];
				order[j+1] = temp;
				temp = ready[j];
				ready[j] = ready[j+1];
				ready[j+1] = temp;
			}
		}
	}
	char s[2048]="ִ���Ⱥ�  ����ʱ��  ����ʱ��  �ȴ�ʱ��  ��תʱ��  ��Ȩ��ת\n";
	char s1[1024]="";
	for(i = 1; i <= num; i++){
		sprintf(s1,"%12d%12d%12d",
            ready[i],
            jobs[ready[i]].reach_time,
            jobs[ready[i]].need_time);
		strcat(s,s1);
		if(i==1){
				jobs[ready[i]].finish_time=jobs[ready[i]].reach_time+jobs[ready[i]].need_time;
	            jobs[ready[i]].wait_time=0;
		}
		else{
			if(jobs[ready[i-1]].finish_time>jobs[ready[i]].reach_time){  //�����һ����ҵ�����ʱ�������һ����ҵ�ĵ���ʱ�䣬����һ����ҵ�Ŀ�ʼʱ�����һ�������ʱ�俪ʼ
	    	jobs[ready[i]].finish_time=jobs[ready[i-1]].finish_time+jobs[ready[i]].need_time;
	    	jobs[ready[i]].wait_time=jobs[ready[i-1]].finish_time-jobs[ready[i]].reach_time;
		    }
		    else{
			jobs[ready[i]].finish_time=jobs[ready[i]].need_time+jobs[ready[i]].reach_time;
			jobs[ready[i]].wait_time=0;
		    }
		}
		jobs[ready[i]].tr_time=jobs[ready[i]].finish_time-jobs[ready[i]].reach_time;
	    jobs[ready[i]].wtr_time=double(jobs[ready[i]].tr_time)/jobs[ready[i]].need_time;
		sprintf(s1, "%12d%12d%12.2f\n",jobs[ready[i]].wait_time,jobs[ready[i]].tr_time,jobs[ready[i]].wtr_time);
		strcat(s,s1);

		sum1+=jobs[ready[i]].wait_time;
    	sum2+=jobs[ready[i]].tr_time;
    	sum3+=jobs[ready[i]].wtr_time;
	}
	strcat(s,"--------������ҵ�������------\n");
	sprintf(s1,"ƽ���ȴ�ʱ��: %.2f ƽ����תʱ��: %.2f ƽ����Ȩ��תʱ��: %.2f\n\n",sum1/num,sum2/num,sum3/num);
	strcat(s,s1);
	tool.writeRs(s);
    printf("�������,�����...\n\n");
}
