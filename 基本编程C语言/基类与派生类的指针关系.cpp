#include <iostream> 
using namespace std;
class B_class
{
    string name;
public:
    void put_name(string s)
    {
        name=s;
    }
    void show_name()
    {
        cout << name << endl;
    }
};
class D_class:public B_class
{
    string phone_num;
public:
    void put_phone(string num)
    {
        phone_num=num;
    }
    void show_phone()
    {
        cout << phone_num << endl;
    }
};
main()
{   B_class *bp;
    B_class Bobj;
    D_class *dp;
    D_class Dobj;
    bp=&Bobj;    
    bp->put_name("Zhang San"); 
    bp=&Dobj; //����ָ��ָ�����������
    bp->put_name("Li Si"); //���ü̳й����ĳ�Ա����
    Bobj.show_name();
    Dobj.show_name();
    ((D_class *) bp)->put_phone("0731-1234567");
    ((D_class *) bp)->show_phone();
}
