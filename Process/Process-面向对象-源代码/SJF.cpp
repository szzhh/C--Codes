// SJF.cpp: implementation of the SJF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SJF.h"
#include "Global.h"
#include "Tool.h"

#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
using namespace std;
#define min(a,b) ((a)<(b))?(a):(b)
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SJF::SJF()
{

}

SJF::~SJF()
{

}

void SJF::doSJF(job jobs[],int num)
{
	Tool tool;
	tool.writeRs("-----------------------------------------------------------------------------------SJF------");
	int i,j;
	double sum1=0; //�ܵĵȴ�ʱ��
	double sum2=0; //�ܵ���תʱ��
	double sum3=0; //�ܵĴ�Ȩ��תʱ��
	int finish=inf; //��ǰ���ʱ��
	for(i=1;i<=num;i++){
		finish=min(finish,jobs[i].reach_time);
	}
	char s[2048]="ִ���Ⱥ�  ����ʱ��  ����ʱ��  �ȴ�ʱ��  ��תʱ��  ��Ȩ��ת\n";
	char s1[1024]="";
	for(i=1;i<=num;i++){
		int index=findNextSJF(jobs,num,finish);
		sprintf(s1,"%12d%12d%12d",
            index,
            jobs[index].reach_time,
			jobs[index].need_time);
		strcat(s,s1);

		if(jobs[index].reach_time<=finish){
			jobs[index].wait_time=finish-jobs[index].reach_time;
			jobs[index].start_time=finish;
		}
		else{
			jobs[index].start_time=jobs[index].reach_time;
			jobs[index].wait_time=0;
		}
		jobs[index].finish_time=jobs[index].start_time+jobs[index].need_time;
		jobs[index].tr_time=jobs[index].finish_time-jobs[index].reach_time;
		jobs[index].wtr_time=(double)jobs[index].tr_time/jobs[index].need_time;
	    jobs[index].visited=true;
	    sum1+=jobs[index].wait_time;
    	sum2+=jobs[index].tr_time;
        sum3+=jobs[index].wtr_time;
        finish=jobs[index].finish_time;

        sprintf(s1, "%12d%12d%12.2f\n",jobs[index].wait_time,jobs[index].tr_time,jobs[index].wtr_time);
		strcat(s,s1);
	}

  	strcat(s,"--------������ҵ�������------\n");
	sprintf(s1,"ƽ���ȴ�ʱ��: %.2f ƽ����תʱ��: %.2f ƽ����Ȩ��תʱ��: %.2f\n\n",sum1/num,sum2/num,sum3/num);
	strcat(s,s1);
	tool.writeRs(s);

    printf("�������,�����...\n\n");
}

int SJF::findNextSJF(job j[], int length, int time)
{
	// p���Ѿ�������ӵ���������ʱ��Ľ��̵��±�
    // q��û�е���Ľ�����ӵ�����絽��ʱ��Ľ��̵��±�
    int i, p, q;
    int minNeedTime, minReachTime,minTime;
    p = q = -1; minTime = minNeedTime = minReachTime = inf;
    for( i = 1; i <= length; i++ ) {
    	if(!j[i].visited){
            // ��һ���
            if( j[i].reach_time<=time && j[i].need_time<=minNeedTime )
                { p = i; minNeedTime = j[i].need_time; }
            // �ڶ������
            else if( j[i].reach_time>time && j[i].reach_time<=minReachTime  ){
                if(j[i].need_time<minTime)
                { q = i; minReachTime = j[i].reach_time; minTime = j[i].need_time; }
            }
        }
    }
    // pΪ-1ʱ,������lastTimeʱ�̻�û���̵���,��ʱѡ����һ�����絽��Ľ���q
    if( p != -1 ) return p;
    return q;
}
