#include <iostream>
#include <iomanip>//��Ҫ���ǰ�����ͷ�ļ�
using namespace std;
 main()
{  int a = 34;    char *pt="China";    double pi=22.0/7.0;
    cout << "dec:" << dec << a << endl; //ʮ������ʽ���
    cout << "hex:" << hex<< a << endl;//ʮ��������ʽ���
    cout << "oct:" << setbase(8) << a << endl;//�˽�����ʽ���
    cout << setw(10) << pt << endl; //ָ�����Ϊ10������ַ���
    cout << setfill('*') << setw(10) << pt << endl; //ָ�����10��
                                                   // ����ַ������հ״��ԡ�*�����
     cout << setiosflags(ios::scientific) << setprecision(8); //��ָ��
                                                   //��ʽ�����8λС��
     cout << "pi=" << pi << endl;    //���piֵ
     cout << "pi=" << setprecision(4) << pi << endl;//��Ϊ4λС��
     cout << "pi=" << setiosflags(ios::fixed) << pi << endl;
                                                       //��ΪС����ʽ���

}
