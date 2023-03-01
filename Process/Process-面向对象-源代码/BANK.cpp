// BANK.cpp: implementation of the BANK class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BANK.h"
#include<stdio.h>
#include <iostream>

using namespace std;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BANK::BANK()
{

}

BANK::~BANK()
{

}


void BANK::showInfo(int resourceNum, int available[], int processNum, int **maxRequest, int **allocation, int **need)
{
    int i,j;
	cout<<endl;
	cout<<"---------------------------------------bank algorithm---------------------------------------"<<endl;
	cout<<"��ǰϵͳ������Դʣ�ࣺ";
    for(j = 0; j < resourceNum; j++)
	{
        cout<<available[j]<<" ";
    }
    cout<<endl;
    cout<<"��ǰϵͳ��Դ���:"<<endl;
    cout<<"ID"<<"\tMax\t\tAllocation\tNeed"<<endl;
    for(i = 0; i < processNum; i++)
	{
        cout<<" P"<<i<<"\t";
        for(j = 0; j < resourceNum; j++)
		{
		    //��ʽ���������c
            printf("%2d",maxRequest[i][j]);
        }
        cout<<"\t\t";
        for(j = 0; j < resourceNum; j++)
		{
            printf("%2d",allocation[i][j]);
        }
        cout<<"\t\t";
        for(j = 0; j < resourceNum; j++)
		{
            printf("%2d",need[i][j]);
        }
        cout<<endl;
    }
}

//��ӡ��ȫ�����Ϣ
void BANK::SafeInfo(int *work, int i, int resourceNum, int **allocation, int **need)
{
    int j;
    cout<<" P"<<i<<"\t";
    for(j = 0; j < resourceNum; j++)
	{
        printf("%2d",work[j]);
    }
    cout<<"\t\t";
    for(j = 0; j < resourceNum; j++)
	{
        printf("%2d",allocation[i][j]);
    }
    cout<<"\t\t";
    for(j = 0; j < resourceNum; j++)
	{
        printf("%2d",need[i][j]);
    }
    cout<<"\t\t";
    for(j = 0; j < resourceNum; j++)
	{
        printf("%2d",allocation[i][j]+work[j]);
    }
    cout<<endl;
}

//�ж�һ�����̵���Դ�Ƿ�ȫΪ��
bool BANK::isAllZero(int kang, int num, int resourceNum, int **need)
{
	num = 0;
	for(int i = 0; i < resourceNum; i++ )
	{
		if(need[kang][i] == 0)
		{
			num ++;
		}
	}
	if(num == resourceNum)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��ȫ���
bool BANK::isSafe(int resourceNum, int num, int **need, int **allocation, int safeSeries[], int available[], int processNum, bool Finish[])
{
	//int resourceNumFinish = 0;
	int i;
	int safeIndex = 0;
	int allFinish = 0;
    int work[resourceNum] = {0};
	int r = 0;
	int temp = 0;
	int pNum = 0;
	//Ԥ����Ϊ�˱���available[]
    for(i = 0; i < resourceNum; i++)
	{
        work[i] = available[i];
    }
	//��δ��ɽ�����Ϊfalse
    for(i = 0; i < processNum; i++)
	{
		bool result = isAllZero(i,num,resourceNum,need);
		if(result == true)
		{
			Finish[i] = true;
			allFinish++;
		}
		else
		{
			Finish[i] = false;
		}

    }
	//Ԥ���俪ʼ
    while(allFinish != processNum)
	{
		num = 0;
        for(i = 0; i < resourceNum; i++)
		{
			if(need[r][i] <= work[i] && Finish[r] == false)
			{
				num ++;
			}
		}
		if(num == resourceNum)
		{
			for(i = 0; i < resourceNum; i++ )
			{
				work[i] = work[i] + allocation[r][i];
			}
			allFinish ++;
			SafeInfo(work,r,resourceNum,allocation,need);
			safeSeries[safeIndex] = r;
			safeIndex ++;
			Finish[r] = true;
		}
		r ++;//��ʽ�����ڴ˴�
		if(r >= processNum)
		{
			r = r % processNum;
			if(temp == allFinish)
			{
				break;
			}
			temp = allFinish;
		}
		pNum = allFinish;
    }
	//�ж�ϵͳ�Ƿ�ȫ
	for(i = 0; i < processNum; i++)
	{
		if(Finish[i] == false)
		{
			cout<<"�޷��ҵ���ȫ���У�ϵͳ״̬����ȫ"<<endl;
			return false;
		}
	}
	//��ӡ��ȫ����
	cout<<"ϵͳ��ȫ��"<<endl;
	cout<<"�ҵ���ȫ����:";
	for(i = 0; i < processNum; i++)
	{
		bool result = isAllZero(i,num,resourceNum,need);
		if(result == true)
		{
			pNum --;
		}
    }
	for(i = 0; i < pNum; i++)
	{
		printf("%d ",safeSeries[i]);
	}
    return true;
}

//������
void BANK::doBank()
{
    //>>>>>>>>>>>>��ʼ������>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int resourceNum = 3;
    int processNum = 5;
    //ϵͳ���ã�ʣ�ࣩ��Դ
    int available[resourceNum]={3,3,2};
    //���̵��������
    int list_maxrequest[]={7,5,3,3,2,2,9,0,2,2,2,2,4,3,3};
    int **maxRequest;
    maxRequest = new int *[processNum];
    int t = 0;
    for(int i=0;i<processNum;i++) {
        maxRequest[i] = new int[resourceNum];
        for(int j=0;j<resourceNum;j++) {
            maxRequest[i][j] = list_maxrequest[t];
            t++;
        }
    }
    //�����Ѿ�ռ�У����䣩��Դ
    int list_allocation[] = {0,1,0,2,0,0,3,0,2,2,1,1,0,0,2};
    int **allocation;
    allocation = new int *[processNum];
    t = 0;
    for(int i=0;i<processNum;i++) {
        allocation[i] = new int[resourceNum];
        for(int j=0;j<resourceNum;j++) {
            allocation[i][j] = list_allocation[t];
            t++;
        }
    }
    //���̻���Ҫ��Դ
    int list_need[] = {7,4,3,1,2,2,6,0,0,0,1,1,4,3,1};
    int **need;
    need = new int *[processNum];
    t = 0;
    for(int i=0;i<processNum;i++) {
        need[i] = new int[resourceNum];
        for(int j=0;j<resourceNum;j++) {
            need[i][j] = list_need[t];
            t++;
        }
    }
    //�Ƿ�ȫ
    bool Finish[processNum];
    //��ȫ���к�
    int safeSeries[processNum]={0,0,0,0,0};
    //����������Դ��
    int request[resourceNum];
    //��Դ��������
    int num = 0;
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

    int i,j;
    int curProcess = 0;
	int a = -1;
    showInfo(resourceNum,available,processNum,maxRequest,allocation,need);
	cout<<" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation"<<endl;
	bool isStart = isSafe(resourceNum,num,need,allocation,safeSeries,available,processNum,Finish);
	//�û��������Ԥ��ϵͳ��Դ���������ܼ������н��̷��乤��
    while(isStart)
	{
		//�����û����룬�Է��û�������ڽ������������֣��Լ����������ַ��������ǲ�����ģ�
      	do
		{
			if(curProcess >= processNum || a == 0)
			{
				cout<<"�����ʽ���󣡻�����ֵ��Χ���Ϸ�";
				while(getchar() != '\n'){};//��ջ�����
				a = -1;
			}
			cout<<endl;
			cout<<"---------------------------------------bank algorithm---------------------------------------"<<endl;
			cout<<"����Ľ��̣�";
			cin>>curProcess;
			a = curProcess;
			cout<<endl;

		}while(curProcess >= processNum || a == 0);

		//�����û����룬�˴�ֻ�������֣��Է��û����������ַ��������ǲ�����ģ�
		for(i = 0; i < resourceNum; i++)
		{
			do
			{
				if(a == 0)
				{
                    cout<<"�����ʽ���󣡻�����ֵ��Χ���Ϸ�";
					while(getchar() != '\n'){};//��ջ�����
					a = -1;
				}
                    printf("������Ҫ����ID:%d ��%d ����Դ��",curProcess,i+1);
                    cin>>request[i];
				a = request[i];
			}while( a == 0);
		}

		//�ж��û�����ķ����Ƿ�������������ʼ����Ԥ����
		num  = 0;
        for(i = 0; i < resourceNum; i++)
		{
            if(request[i] <= need[curProcess][i] && request[i] <= available[i])
			{
				num ++;
			}
            else
			{
				cout<<"ϵͳ���ֿ�Ԥ������"<<endl;;
				cout<<"1. ����������Դ���ܴ��ڸý��̵�ĳЩ��Դ�������Ҫ��"<<endl;
				cout<<"2. ϵͳ��ʣ����Դ�Ѿ�����"<<endl;
				break;
			}
        }
        if(num == resourceNum)
		{
			num = 0;
            for(j = 0; j < resourceNum; j++)
			{
				//������Դ
                available[j] = available[j] - request[j];
                allocation[curProcess][j] = allocation[curProcess][j] + request[j];
                need[curProcess][j] = need[curProcess][j] - request[j];
				//��¼�����Ժ��Ƿ�ý�����ҪֵΪ0��
				if(need[curProcess][j] == 0)
				{
					num ++;
				}
            }
			//��������Ժ���ָý��̶�������Դ������Ϊ0�ˣ������ͷŸý���ռ����Դ����Ϊ��ɣ�
			if(num == resourceNum)
			{
				//�ͷ��������Դ
				for(i = 0; i < resourceNum; i++ )
				{
					available[i] = available[i] + allocation[curProcess][i];
				}
				cout<<endl;
				cout<<"���η������ID"<<curProcess<<"��ɣ����̵���Դ�Ѿ��ͷ�"<<endl;
			}
			else
			{
				//��Դ������Բ���һ���������������
				cout<<endl;
				cout<<"���η������ID"<<curProcess<<"ʧ��"<<endl;
			}

			showInfo(resourceNum,available,processNum,maxRequest,allocation,need);
           	cout<<"��ȫ�Է���"<<endl;
			cout<<" PID\t Work\t\tAllocation\t Need\t\tWork+Allocation"<<endl;

			//Ԥ��������Ժ��жϸ�ϵͳ�Ƿ�ȫ������ȫ����ɼ������з��䣬������ȫ�����Ѿ��������Դ������
            if(!isSafe(resourceNum,num,need,allocation,safeSeries,available,processNum,Finish))
			{
				for(j = 0; j < resourceNum; j++)
				{
					available[j] = available[j] + request[j];
					allocation[curProcess][j] = allocation[curProcess][j] - request[j];
					need[curProcess][j] = need[curProcess][j] +request[j];
				}
				cout<<"ϵͳ��Դ���㣬����ʧ��"<<endl;
				cout<<endl;
            }
        }
    }
}
