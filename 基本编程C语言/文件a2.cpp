#include <fstream>
#include<iostream>
using namespace std;
int main( )
{
int a[10], max, i, order;
 ifstream infile("f1.dat", ios::in);
//���������ļ������������뷽ʽ�򿪴����ļ�f1.dat
 if(!infile)
 {  cerr<<"open error!"<<endl;
     exit(1); 
  } 
  for(i=0;i<10;i++)
  {   infile >> a[i]; //�Ӵ����ļ�����10��������˳������a������
       cout << a[i] << " "; //����ʾ����˳����ʾ10����
  }
  cout << endl;
max=a[0]; 
order=0;
 for(i=1;i<10;i++)
 if(a[i]>max)
 {
      max=a[i];           //����ǰ���ֵ����max��
      order=i+1;             //����ǰ���ֵ��Ԫ����ŷ���order��
 }
 cout << "max=" << max << endl << "order=" << order << endl;
 infile.close();
 return 0;
}
