#include <iostream>
using namespace std;
class time
{
public:
time() //constructor.���캯��
{
hour=0;
minute=0;
sec=0;
}
time(const time &obj)  //�������캯��
{
hour = obj.hour;
minute = obj.minute;
sec = obj.sec;
}
time& operator=(const time &obj)  //��������أ�������ɸ�ֵ����
{
this->hour = obj.hour;
this->minute = obj.minute;
this->sec = obj.sec;
return *this;
}
void set_time();
void show_time();
private:
int hour;
int minute;
int sec;
};
int main()
{
class time t1;  //����time()���캯��Ϊ��Ա����ֵ
t1.show_time();
t1.set_time();
t1.show_time();
class time t2=t1;   //���ÿ������캯����Ϊ����t2��ֵ
t2.show_time();
class time t3;
t3=t1;  //�������������=������Ϊ����t3��ֵ
t3.show_time();
return 0;
}
void time::set_time()
{
cin >>hour;
cin >>minute;
cin >>sec;
}
void time::show_time()
{ 
cout<<hour<<":"<<minute<<":"<<sec<<endl;
}
