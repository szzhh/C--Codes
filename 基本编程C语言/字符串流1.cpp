#include<iostream>
#include <strstream>
using namespace std;
struct student
{     int num;
      char name[20];
      float score;
};
main( )
{
      student stud[3]={1001,"Li",78,1002,"Wang",89.5,1004,"Fun",90};
      char c[50];//�û�������ַ�����
      ostrstream strout(c,30); //��������ַ�������
                                               //������c������������������30
      for(int i=0;i<3;i++)        //���ַ�����cд3��ѧ��������
            strout<<stud[i].num<<stud[i].name<<stud[i].score;
      strout<<ends;             //ends��C++��I/O������������һ����\0��
      cout<<"array c:"<<c<<endl;    //��ʾ�ַ�����c�е��ַ�
}
