#include<iostream>
using namespace std;
class A
{ public:
    A() { cout << "A�Ĺ��캯��" << endl; }
    virtual ~A()   { cout << "A����������" << endl; }
};
class B:public A
{ public:
    B() { cout << "B�Ĺ��캯��" << endl; }
    ~B() { cout << "B����������" << endl; }
};
main()
{   A *Ap = new B;	
    B *Bp2 = new B;
    delete Ap;
    delete Bp2;
}
