#include <fstream>
#include<iostream>
#include<string.h>
using namespace std;
struct student
{     int num;
      char name[20];
      float score;
};
int main( )
{      int i;
      student stud[5]={1001,"Li",85,1002,"Fun",97.5,1004,"Wang",54,
                  1006,"Tan",76.5,1010,"ling",96};
      fstream iofile("stu.dat",ios::in|ios::out|ios::binary);  
                           //��fstream�ඨ����������������ļ�������iofile
      if(!iofile)
      {     cerr<<"open error!"<<endl;
             abort();
      }
for(i=0;i<5;i++)//������ļ����5��ѧ��������
            iofile.write((char *)&stud[i],sizeof(stud[i]));  
      student stud1[5];                  //������ŴӴ����ļ����������
      for(i=0;i<5;i=i+2)
      {     iofile.seekg(i*sizeof(stud[i]),ios::beg);  //��λ�ڵ�0,2,4ѧ�����ݿ�ͷ
             iofile.read((char *)&stud1[i/2],sizeof(stud1[0])); //�Ⱥ����3��ѧ��
                                                  //�����ݣ������stud1[0],stud[1]��stud[2]��
             cout << stud1[i/2].num << " " << stud1[i/2].name << " " << stud1[i/2].score << endl;
                                         //���stud1[0],stud[1]��stud[2]����Ա��ֵ
      }
      cout<<endl;
      stud[2].num=1012;                         //�޸ĵ�3��ѧ��(���Ϊ2)������
      strcpy(stud[2].name,"Wu");
      stud[2].score=60;
      iofile.seekp(2*sizeof(stud[0]),ios::beg);   //��λ�ڵ�3��ѧ�����ݵĿ�ͷ
      iofile.write((char *)&stud[2],sizeof(stud[2])); //���µ�3��ѧ������
      iofile.seekg(0,ios::beg);                       //���¶�λ���ļ���ͷ
for(i=0;i<5;i++)
      {
            iofile.read((char *)&stud[i],sizeof(stud[i]));  //����5��ѧ��������
            cout<<stud[i].num<<" "<<stud[i].name<<" "<<stud[i].score<<endl;
      }
      iofile.close();
      return 0;
}

