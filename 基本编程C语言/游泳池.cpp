#include <iostream>
#include <cmath>
using namespace std;
const double pi(3.14);
class pool{
private:
	double r;//�뾶
public:
	pool(double rr){r=rr;}
	double getPeri();//���ܳ�
	double getArea();
 
};

double pool::getPeri(){
	return 2*pi*r;
}
double pool::getArea(){
	return pi*(r*r-(r-5)*(r-5));
}
int main (){
	double r;
	cout<<"����뾶:"; 
	cin>>r;
	pool po(r+5);
	cout<<"դ�����="<<po.getPeri()*50<<endl;
	cout<<"�������="<<po.getArea()*150<<endl;
	return 0;
}
