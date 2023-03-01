//���̿��ƿ�
typedef struct PCB
{
	int id;
	char name[20];
	enum STATUS status;
	HANDLE hThis;
	unsigned int threadID;
	int count;
	struct PCB *next;
}PCB,*pPCB;
//�������кͻ���������
typedef struct
{
	pPCB head;
	pPCB tail;
	int pcbNum;
}readyList,freeList,*pList;
//���������̣���¼���̲���
typedef struct apply
{
	char name[20];
	int time;
	struct apply *next;
}applyProcess,*applyList;
//���������̶���
typedef struct
{
	applyList head;
	applyList tail;
	int applyNum;
}applyQueue;

enum STATUS{RUN,READY,WAIT};
//�����߳���
const int PCB_LIMIT=10;

void init();
void createProcess(char* name,int ax);
void addApplyProcess(char* name,int time);
void createIfAnyApply();
void scheduleProcess();
void remove(pPCB removeTarget);
void removeProcess(char* name);
void fprintReadyList();
void printCurrent();
void stopAllThreads();