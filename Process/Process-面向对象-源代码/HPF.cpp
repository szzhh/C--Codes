// HPF.cpp: implementation of the HPF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "HPF.h"
#include "Global.h"
#include "Tool.h"

#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define min(a,b) ((a)<(b))?(a):(b)
using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HPF::HPF()
{

}

HPF::~HPF()
{

}

int HPF::findNextHPF(job j[MAX_NUM], int length,int time,job jobs[],int num)
{
	//����ֵԽ�� ��ʾ����ȨԽ��
    // p���Ѿ�������ӵ���������Ȩ�Ľ��̵��±�
    // q��û�е���Ľ�����ӵ�����絽��ʱ��Ľ��̵��±�
    int i, p, q;
    int minReachTime,minPrivilege1;
    p = q = -1; minPrivilege1  = minReachTime = inf;
    for( i = 1; i <= length; i++ ) {
    	if(!j[i].visited){
            // ��һ���
            if( j[i].reach_time<=time && j[i].privilege<=minPrivilege1 )
			{

			    if(j[i].privilege==j[p].privilege){   //�������Ȩһ�� ������ִ�ʱ��
			    	if(j[i].reach_time<j[p].reach_time){
			    		p=i;
					}
				}
				else{
				  p = i;
				 minPrivilege1 = j[i].privilege;
				}
			 }
            // �ڶ������
            else if(j[i].reach_time>time && j[i].reach_time<=minReachTime  ){
                q = i; minReachTime = j[i].reach_time;
            }
        }
    }
    // pΪ-1ʱ,������timeʱ�̻�û���̵���,��ʱѡ����һ�����絽��Ľ���q
    if( p != -1 ) return p;
    return q;
}

void HPF::doHPF(job jobs[],int num)
{
	Tool tool;
	tool.writeRs("----------------------------------------------------------------------------------HPF-----");
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
		int index=findNextHPF(jobs,num,finish,jobs,num);
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
