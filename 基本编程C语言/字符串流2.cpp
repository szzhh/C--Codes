#include<iostream>
#include <strstream>
using namespace std;
int main( )
{
      char c[50]="12 34 65 -23 -32 33 61 99 321 32";
      int a[10], i , j, t;
      cout<<"array c:"<<c<<endl;//��ʾ�ַ������е��ַ���
      istrstream strin(c,sizeof(c));  //�������봮������strin�����ַ�����c����
      for(i=0;i<10;i++)    strin>>a[i]; //���ַ�����c����10������������������a
      cout<<"array a:";
      for(i=0;i<10;i++)   cout<<a[i]<<" ";                 //��ʾ��������a��Ԫ��
      cout<<endl;
      for(i=0;i<9;i++)                   //�����ݷ�������a����
           for(j=0;j<9-i;j++)
                 if(a[j]>a[j+1])
                 {   t=a[j];   a[j]=a[j+1];   a[j+1]=t;  }
ostrstream strout(c, sizeof(c));    //���������������strout
                                                           //�����ַ�����c����
 for(i=0;i<10;i++)     strout<<a[i]<<" ";      //��10������������ַ�����c
 strout<<ends;                      //�����\\0��
 cout<<"array c:"<<c<<endl;         //��ʾ�ַ�����c
 return 0;
} 
