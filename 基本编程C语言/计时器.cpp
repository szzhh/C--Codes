#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;
int main(void)
{
time_t t_start,t_end;
t_start = time(NULL) ;
cout<<"��ʱ�Ѿ���ʼ����Enter����ͣ��ʱ����"<<endl;
getch();
t_end = time(NULL) ;
cout<<"ʱ��Ϊ��"<<difftime(t_end,t_start)<<"s"<<endl;
return 0;
}
