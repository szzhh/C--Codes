// HRRF.cpp: implementation of the HRRF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HRRF.h"
#include "Global.h"
#include "Tool.h"

#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HRRF::HRRF()
{

}

HRRF::~HRRF()
{

}

void HRRF::doHRRF(job jobs[], int num)
{
	Tool tool;
	tool.writeRs("-----------------------------------------------------------------------------------HRRF----");
	int i,j;
	double sum1=0; //�ܵĵȴ�ʱ��
	double sum2=0; //�ܵ���תʱ��
	double sum3=0; //�ܵĴ�Ȩ��תʱ��
	int pre=1;
	jobs[1].finish_time=0;

    char s[2048]="ִ���Ⱥ�  ����ʱ��  ����ʱ��  �ȴ�ʱ��  ��תʱ��  ��Ȩ��ת\n";
	char s1[1024]="";
	for(i=1;i<=num;i++){

		int index=findNextHRRF(pre,jobs,num);

		sprintf(s1,"%12d%12d%12d",
            index,
            jobs[index].reach_time,
			jobs[index].need_time);
		strcat(s,s1);

		if(i==1){
			jobs[index].start_time=jobs[index].reach_time;
			jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
			jobs[index].tr_time=jobs[index].need_time;
			jobs[index].wtr_time=1.00;
			jobs[index].wait_time=0;
		}
		else{
		   if(jobs[index].reach_time>jobs[pre].finish_time){
			jobs[index].wait_time=0;
			jobs[index].start_time=jobs[index].reach_time;
	    	}
	    	else{
			jobs[index].start_time=	jobs[pre].finish_time;
			jobs[index].wait_time=	jobs[pre].finish_time-jobs[index].reach_time;
	    	}
	    	jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
		    jobs[index].tr_time=jobs[index].finish_time-jobs[index].reach_time;
		    jobs[index].wtr_time=(double)jobs[index].tr_time/jobs[index].need_time;
		}
		    jobs[index].visited=true;
	        pre=index;
	        sum1+=jobs[index].wait_time;
    	    sum2+=jobs[index].tr_time;
            sum3+=jobs[index].wtr_time;

            sprintf(s1, "%12d%12d%12.2f\n",jobs[index].wait_time,jobs[index].tr_time,jobs[index].wtr_time);
            strcat(s,s1);
	}
    strcat(s,"--------������ҵ�������------\n");
	sprintf(s1,"ƽ���ȴ�ʱ��: %.2f ƽ����תʱ��: %.2f ƽ����Ȩ��תʱ��: %.2f\n\n",sum1/num,sum2/num,sum3/num);
	strcat(s,s1);
	tool.writeRs(s);
    printf("�������,�����...\n\n");
}

int HRRF::findNextHRRF(int pre, job jobs[], int num)
{
	int current=1,i,j;    //����Ȩ=(�ȴ�ʱ��+Ҫ�����ʱ��)/Ҫ�����ʱ��
    for(i=1;i<=num;i++)
    {
    	if(!jobs[i].visited){
        jobs[i].wait_time=	jobs[pre].finish_time-jobs[i].reach_time;    //�ȴ�ʱ��=��һ�����̵����ʱ��-����ʱ��
        jobs[i].excellent=(float)(jobs[i].wait_time+jobs[i].need_time)/jobs[i].need_time;
        }
    }
    for(i=1;i<=num;i++)
    {
        if(!jobs[i].visited)
        {
            current=i;    //�ҵ���һ����û��ɵ���ҵ
            break;
        }
    }
    for(j=i;j<=num;j++)    //�ͺ������ҵ�Ƚ�
    {
        if(!jobs[j].visited)    //��û��ɣ����У�
        {
            if(jobs[current].reach_time<jobs[pre].finish_time)    //�����������һ���������֮ǰ����
            {
                if(jobs[j].excellent>jobs[current].excellent)
                current=j;    //�ҳ�����ʱ������һ���������֮ǰ������Ȩ�ߵĽ���
            }
            else    //�������������һ���������֮�󵽴�
            {
                if(jobs[j].reach_time<jobs[current].reach_time)
                    current=j;    //�ҳ��Ƚ��絽���һ��
                else if(jobs[j].reach_time==jobs[current].reach_time&&jobs[j].excellent>jobs[current].excellent)    //���ͬʱ����
                    current=j;    //�ҳ�����ʱ��Ƚ϶̵�һ��
            }
        }
    }
    return current;    //���ص�ǰ����
}
