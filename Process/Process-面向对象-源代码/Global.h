//������ҵ��Ϣ�ṹ
#ifndef _GLOBAL_H_
#define _GLOBAL_H_
typedef struct job{
    char number;        //��ҵ��
	int reach_time;     //��ҵ�ִ�ʱ��
	int need_time;      //��ҵ��ִ��ʱ��
	int privilege;	    //��ҵ����Ȩ
	float excellent;    //��Ӧ��
	int start_time;     //��ҵ��ʼʱ��
	int wait_time;      //�ȴ�ʱ��
	int tr_time;        //��תʱ��
	double wtr_time;    //��Ȩ��תʱ��
	int run_time;       //��ҵ�ۼ���ִ��ʱ��
	bool visited;		//��ҵ�Ƿ񱻷��ʹ�
	int finish_time;	//��ҵ���ʱ��
	bool reached;		//��ҵ�Ƿ�ִ�
}job;

const int MAX_NUM = 10;//�����ҵ����
const int MAX_LINE=1024;//һ�е�size

#define inf 0x3f3f3f
#endif