#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
int main()
{
    string  username;
    string  password;
    char  a[20];
    do{
        cout  <<"�û�����";
        getline(cin,username,'\n');
        cout  <<"���룺";
        int z;
        for(z=0;z<20;z++)
        {
            a[z]=getch();     
            if (a[z] == 13) //��Ӧ�س�
            {
                break;
            }
            else if (a[z] == '\b')  //��Ӧ�˸��
            {
                if (z == 0) //�����ǰ�Ѿ�û���ַ�����ֱ������
                {
                    continue;
                }
                //��Ļ��ɾ�����ַ���ɿո񣬲����˹��
                cout << "\b";
                cout << " ";
                cout << "\b";
                //��������Ӧλ�����0
                z--;
                a[z] = 0;
                //��i��ǰ��һλ����Ϊ��������ִ��forѭ����i++
                z--;
                //������뻺�壬����س��������ַ�����
                cin.clear();
            }
            else
            {
                cout  << "*";
            }
        }
        cout << endl;
        //a�ַ�����β��������password
        a[z] = 0;
        password = a;
 
        if(username=="sunzhonghao" && password=="szh123")
            cout <<"��½�ɹ���" << endl;
        else
            cout  <<"�û����������������������"<< endl;
    }
    while(username!="sunzhonghao" || password!="szh123");
}
