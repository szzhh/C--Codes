#include<iostream>
using namespace std;
 int f(int i)
 {	
 char m;
 if(i>15) f(i/16);
 if((m=i%16+'0')>0x39) m+=7;
  cout<<m;
 }
main()
{
	int n;
	cout<<"����һ��ʮ���Ƶ�����";
	cin>>n;
	cout<<"ת��Ϊʮ������Ϊ��";
	f(n);
	cout<<endl; 
}
