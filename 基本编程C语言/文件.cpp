#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream outfile;
    char ch;
    outfile.open("filel.txt");
    if(!outfile) {
        cout << "�ļ���ʧ��" << endl;
        return 1;
    }
    cout << "������һ���ַ���" << endl;
    do {
        cin.get(ch);
        if(ch!='#')outfile<<ch;
    }
    while(ch!='#');
    outfile<<"#";
    return 0;
}
