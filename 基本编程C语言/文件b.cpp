#include <fstream>
#include<iostream> 
using namespace std;
// save_to_file�����Ӽ��̶���һ���ַ����������е���ĸ��������ļ�
void save_to_file( )
{
      ofstream outfile("f2.dat"); //��������ļ�������outfile��
                                                    //�������ʽ��f2.dat
      if(!outfile)
      {
            cerr<<"open f2.dat error!"<<endl;
            exit(1);
      }
      char c[80];
      cin.getline(c,80);//�Ӽ��̶���һ���ַ�
for(int i=0;c[i]!=0;i++)               //���ַ��������ֱ������0��Ϊֹ
      if(c[i]>=65 && c[i]<=90||c[i]>=97 && c[i]<=122)//�������ĸ�ַ�
      {
            outfile.put(c[i]);                      //����ĸ�ַ���������ļ�f2.dat
            cout<<c[i];}                            //ͬʱ����ʾ����ʾ
            cout<<endl;
            outfile.close();                         //�ر�f2.dat
}
//�Ӵ����ļ�f2.dat������ĸ�ַ�����Сд��ĸ��Ϊ��д��ĸ���ٴ���f3.dat
void get_from_file()
{
      char ch;
      ifstream infile("f2.dat",ios::in); //���������ļ���outfile
                                                     //�������뷽ʽ�򿪴����ļ�f2.dat
if(!infile)
{      cerr << "open f2.dat error!"<< endl;
       exit(1);
 }
ofstream outfile("f3.dat"); //��������ļ���outfile��
                                                    //�������ʽ�򿪴����ļ�f3.dat 
      if(!outfile)
      {   cerr << "open f3.dat error!"<< endl;
          exit(1);
      }
      while(infile.get(ch))//����ȡ�ַ��ɹ�ʱִ������ĸ������
      {
            if(ch>=97 && ch<=122)          //�ж�ch�Ƿ�ΪСд��ĸ
            ch = ch-32;                    //��Сд��ĸ��Ϊ��д��ĸ
            outfile.put(ch);               //���ô�д��ĸ��������ļ�f3.dat
            cout<<ch;                      //ͬʱ����ʾ�����
      }
      cout<<endl;
      infile.close();                  //�رմ����ļ�f2.dat
      outfile.close();                 //�رմ����ļ�f3.dat
}
int main( )
{
      save_to_file( );    //����save_to_file( )���Ӽ��̶���һ���ַ�����
                                   // ���е���ĸ��������ļ�f2.dat
      get_from_file( ); //����get_from_file()����f2.dat������ĸ�ַ���
                                   //��Ϊ��д��ĸ���ٴ���f3.dat 
      return 0;
}
