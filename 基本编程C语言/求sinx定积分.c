#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
void def(float a,float b,int n)
{
 int i;
 float d,s=0;
 d=(b-a)/n;
 for(i=0;i<n;i++)
  s+=(sin(a+d*i)+sin(a+d*(i+1)))*d/2.0;
  printf("����������ֵ������Ϊ: "); 
 printf("%f",s);
}
int main()
{
 float x,y;
 int z;
 printf("�����붨���ֵ����: "); 
 scanf("%f",&x);
 printf("�����붨���ֵ��յ�: "); 
 scanf("%f",&y);
 printf("���������ֶ���: "); 
 scanf("%d",&z);
 def(x,y,z);
 return 0;
}
