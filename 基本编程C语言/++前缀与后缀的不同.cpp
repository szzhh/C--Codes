#include<iostream>
using namespace std;
 class X
{
    int a, b;
public:
    X(){a = 0; b = 0;};
    X(int i, int j) {a = i; b = j;}
    X operator++()  //  ǰ׺��ʽ
    { a++;    b++;    return *this; }
    X operator++(int t)  // ��׺��ʽ
    {  X temp=*this;
        a++;    b++;    return temp;
    }
    friend void show(X obj)
    {  cout << obj.a << "," << obj.b 
                << endl;
    }
};
 main()
{
    X x(1,2);
    show(++x);
    show(x);
    show(x++);
    show(x);
}
