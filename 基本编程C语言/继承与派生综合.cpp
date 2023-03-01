#include<iostream>
using namespace std;class Point
{public:
     Point(float, float);                   //���캯��
     void setPoint(float, float);      //��������ֵ
     float getX( ) const {return x;}//��x����
     float getY( ) const {return y;}//��y����
     friend ostream & operator << (ostream &, 
                            const Point &);  //�����������<<��
protected: 
     float x, y;
};
//Point�Ĺ��캯��
Point::Point(float a=0, float b=0) { x = a; y = b;} //��x, y��ʼ��
//����x��y������ֵ
void Point::setPoint(float a, float b)         //Ϊx, y����ֵ
{x=a; y=b;}
//�����������<<����ʹ֮������������
ostream & operator<<(ostream & output, const Point & p)
{
     output<<"["<<p.x<<","<<p.y<<"]"<<endl;
     return output;
}
class Circle: public Point  //circle��Point��Ĺ���������
{public:
     Circle(float, float, float);  //���캯��
     void setRadius(float);       //���ð뾶ֵ
     float getRadius( ) const;   //��ȡ�뾶ֵ
     float area ( ) const;            //����Բ���
     friend ostream & operator << (ostream &,
                          const Circle &);        //�����������<<��
 private:
  float radius;
};
//���幹�캯������Բ������Ͱ뾶��ʼ��
Circle::Circle(float a = 0, float b = 0, float r = 0)
     :Point(a, b) { radius = r; }
//���ð뾶ֵ
void Circle::setRadius(float r) {radius = r;}
//��ȡ�뾶ֵ
float Circle::getRadius( ) const {return radius;}
//����Բ���
//����Բ���
float Circle::area( ) const {return 3.14159*radius*radius;}
//�����������<<����ʹ֮���涨����ʽ���Բ����Ϣ
ostream &operator<<(ostream &output,const Circle &c)
{ output << "Center=[" << c.x << "," << c.y << "],r=" << 
               c.radius << ",area=" << c.area() << endl;
 return output;
}
class Cylinder: public Circle// ��Circle�๫�м̳й���
{public:
     Cylinder (float, float, float, float);//���캯��
     void setHeight(float);                     //����Բ����
     float getHeight( ) const;                 //��ȡԲ����
     float area( ) const;                          //����Բ�����
     float volume( ) const;                     //����Բ�����
     friend ostream & operator << (ostream&,
                      const Cylinder&);         //�����������<<��
 protected:  float height;                               //Բ����
};
//���幹�캯��
Cylinder::Cylinder(float a = 0, float b = 0, float r = 0, 
           float h= 0): Circle(a,b,r), height(h) {  }
//����Բ����
void Cylinder::setHeight(float h) {height = h;}
//��ȡԲ����
float Cylinder::getHeight( ) const {return height;}//����Բ�����
float Cylinder::area( ) const
{ return 2*Circle::area( )+2*3.14159*Circle::getRadius()*height;}
//����Բ�����
float Cylinder::volume() const {return Circle::area()*height;}
//�����������<<��
ostream & operator << (ostream & output, const Cylinder & cy)
{
     output << "Center=[" << cy.x << "," << cy.y << "],r=" << 
               cy. getRadius() << ",h=" << cy.height << "\narea=" << 
               cy.area() << ", volume=" << cy.volume( ) << endl;
     return output;
}
main( )
{
     Cylinder cy1(3.5,6.4,5.2,10);//����Cylinder�����cy1
     cout << "original cylinder:\nx=" << cy1.getX() << ", y="
             << cy1.getY() << ", r=" <<cy1.getRadius( ) << ", h=" 
             << cy1.getHeight() << "\narea=" << cy1.area()
             << ",volume=" << cy1.volume() << endl;//��ϵͳ�������
             cout<<"\n"<<cy1;                                           //�����<<�����cy1������
     cy1.setHeight(15);                    //����Բ����
     cy1.setRadius(7.5);                  //����Բ�뾶
cy1.setPoint(5,5);                     //����Բ������ֵx, y
     cout << "\nnew cylinder:\n" << cy1;   //�������������<<��
                                                        //���cy1������
     Point & pRef = cy1;        //pRef��Point���������ñ���
     cout << "\npRef as a Point:" << pRef; //pRef��Ϊ���㡱���
     Circle &cRef=cy1;          //cRef��Circle���������ñ���
     cout << "\ncRef as a Circle:" << cRef; //cRef��Ϊ��Բ�����
     return 0;
}
