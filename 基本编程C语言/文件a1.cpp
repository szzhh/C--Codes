#include <fstream>
#include<iostream>
using namespace std;
int main( )
{      int a[10];
ofstream outfile("f1.dat", ios::out); //�����ļ������󣬴򿪴����ļ�f1.dat
if(!outfile)                        //�����ʧ�ܣ�outfile����0ֵ
{  cerr << "open error!" << endl;
   exit(1);
}
cout << "enter 10 integer numbers:"<<endl;
for(int i=0;i<10;i++)
{  cin >> a[i];    outfile << a[i] << " ";   //������ļ���f1.dat���������
}
outfile.close();           //�رմ����ļ���f1.dat��
return 0;
} 
