#include <iostream>
#include <string>
//#include <cctype>
using std::cout;
using std::endl;
using std::cin;
using std::string;
int main(void){
	string str1="hi,test,hello";
	string str2="hi,test";
	//�ַ����Ƚ�
	if(str1.compare(str2)>0)
		printf("str1>str2\n");
	else if(str1.compare(str2)<0)
		printf("str1<str2\n");
	else
		printf("str1==str2\n");
	
	//str1���Ӵ���������3��ʼ������4���ַ�����str2���бȽ�
	if(str1.compare(3,4,str2)==0)
		printf("str1��ָ���Ӵ�����str2\n");
	else
		printf("str1��ָ���Ӵ�������str2\n");
	
	//str1ָ���Ӵ���str2��ָ���Ӵ����бȽ�
	if(str1.compare(3,4,str2,3,4)==0)
		printf("str1��ָ���Ӵ�����str2��ָ���Ӵ�\n");
	else
		printf("str1��ָ���Ӵ�������str2��ָ���Ӵ�\n");
	
	//str1ָ���Ӵ����ַ�����ǰn���ַ����бȽ�
	if(str1.compare(0,2,"hi,hello",2)==0)
		printf("str1��ָ���Ӵ�����ָ���ַ�����ǰ2���ַ���ɵ��Ӵ�\n");
	else
		printf("str1��ָ���Ӵ�������ָ���ַ�����ǰ2���ַ���ɵ��Ӵ�\n");
	return 0;
}
