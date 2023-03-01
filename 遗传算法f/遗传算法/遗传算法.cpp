#include<math.h> 
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h> 
#include "engine.h"  

using namespace std;
//��ز�����
float Pov[4]={0.2,0.2,0.2,0.2};//����ĸ���,��ֵ�ֱ�Ϊ���������Ĳ������������Ĳ��������ֱ��죬���ű��죬P0��P1���⣬����ı��������ͻ 
int layer;//������
int prine_number=100;//��ʼ������Ŀ
float max_c_p=1.0e+4;//��󻷾���Ӧ��
int max_generation=40;//����ݻ�����
int die_generation=5;//ÿ�����ٴ���̭һ��
float die_rate=0.5;//ÿ����̭�ı���
float in_percent;//�������ٷֱ�
int num_pre_generation=20;//ÿ���������¸������
float environment[20][3]={{-0.8,-0.4,0.447},{-0.4,-0.4,0.825},{0,0.8,0.6},{0.6,-0.8,0},{-0.8,-0.2,0.566},{-0.4,-0.6,0.693},{0,1,0},{0.6,-0.6,0.529},{-0.8,0,0.6},{-0.4,-0.8,0.477},{0.2,-0.8,0.566},{0.6,-0.4,0.693},{-0.8,-0.2,0.566},{0.2,-0.6,0.775},{0.6,-0.2,0.775},{-0.8,-0.4,0.447},{-0.2,-0.6,0.775},{-0.2,-0.4,0.894},{0.6,0,0.8},{-0.4,-0.8,0.566}};//ѧϰ��������ݣ������� 

//���vector 
template < class T >
void ClearVector( vector< T >& vt ) 
{
    vector< T > vtTemp;
    vtTemp.swap( vt );
}
//�Ŵ��㷨����DNA���ʾȾɫ�壺
class DNA{
	public: 
	string code;//�沨��ʽ 
	vector<float> d;//���泣�� 
	float c_p;//������Ӧ�� 
	//���뷽ʽ:
	float output(float A1,float A2){
		//�����鴢����ʱ����
		vector <float> tample;
		//�沨��ʽ���� 
		int i1 = 0;//��Ҫ�ļ�¼�� 
		int i2 = 0;
		for(int i=0;i<code.length();i++){
			switch(code[i]){
				if(i>tample.size()){
					cout<<this->code<<endl;
					system("pause");
				}
				case '0':
					tample.push_back(d[i2]);
					i1++;i2++;
					break;
				case '1': 
					tample.push_back(A1);
					i1++;
					break;	
				case '2': 
					tample.push_back(A2);
					i1++;
					break;	
				case '+':
					tample[i1-2]+=tample[i1-1];
					i1--;
					tample.pop_back();
					break;
				case '-':
					tample[i1-2]-=tample[i1-1];
					i1--;
					tample.pop_back();
					break;
				case '/':
					tample[i1-2]/=tample[i1-1];
					i1--;
					tample.pop_back();
					break;
				case '*':
					tample[i1-2]*=tample[i1-1];
					i1--;
					tample.pop_back();
					break;
				case 'f':
					tample[i1-1]=fabs(tample[i1-1]);
					break;
				case 'e':
					tample[i1-1]=exp(tample[i1-1]);
					break;
				case 'l':
					tample[i1-1]=log(tample[i1-1]);
					break;
				case 'a':
					tample[i1-1]=atan(tample[i1-1]);
					break;
				case 's':
					tample[i1-1]=sin(tample[i1-1]);
					break;
				case 'c':
					tample[i1-1]=cos(tample[i1-1]);
					break;
				default:
					cout<<"����δ֪��dna����"<<endl;
					system("pause");
					break; 
			}
		}
		if(!tample.size()){
					cout<<this->code<<endl;
					system("pause");
					return 100000;
		}
		else{
			return tample[0];
		}
		
	}
	//�������幹�캯�� 
	DNA(){
		int const_need=0;
		int num_tample;
		int t=0;
		//���DNA�Ǽ�����
		for (int i=0;i<7;i++){
			switch(rand()%4){
				case 0:
					code.push_back('+');
					break;
				case 1:
					code.push_back('-');
					break;
				case 2:
					code.push_back('/');
					break;
				case 3:
					code.push_back('*');
					break;
				default:
					cout<<"����δ֪��dna����"<<endl;
					system("pause");
					break; 
			}
		}
		//������ֲ���
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				for(int k=0;k<2;k++){
					num_tample=rand()%3;
					if(num_tample==0){
						const_need++;
					}
					code.insert(code.begin()+7*i+3*j,num_tample+48);
				}
			}
		}
		//�����ӵ�Ŀ����� 
		t=rand()%6;
		for (int i=0;i<t;i++){
			int k=rand()%code.length()+1;
			switch(4+rand()%6){
				case 4:
					code.insert(code.begin()+k,'f');
					break;
				case 5:
					code.insert(code.begin()+k,'e');
					break;
				case 6:
					code.insert(code.begin()+k,'l');
					break;
				case 7:
					code.insert(code.begin()+k,'a');
					break;
				case 8:
					code.insert(code.begin()+k,'s');
					break;
				case 9:
					code.insert(code.begin()+k,'c');
					break;
				default:
					cout<<"����δ֪��dna����"<<endl;
					system("pause");
					break; 
			}
		}
		//����������� 
		for (int i=0;i<const_need;i++){
			this->d.push_back(float(rand()%10000)/1000.0);
		}
		//�����沨��ʽ
		/*
		int tample[128]; 
		int i1=0;
		int i2=0;
		for(int i=0;i<this->code.length();i++){
			switch(this->code[i]){
				case '0':
					tample[i1++]=1;
					i2++;
					break;
				case '1': 
					tample[i1++]=0;
					break;	
				case '2': 
					tample[i1++]=0;
					break;
				case '+':
					if(tample[i1-1]&&tample[i1-2]){
						d[i2-2]+=d[i2-1];
						d.erase(d.begin()+i-1);
						code[i]='0';
						code.erase(i-2,2);
						i-=2;
						i1-=2;
						i2-=1;
					}
					break;
				case '-':
					if(tample[i1-1]&&tample[i1-2]){
						d[i2-2]-=d[i2-1];
						d.erase(d.begin()+i-1);
						code[i]='0';
						code.erase(i-2,2);
						i-=2;
						i1-=2;
						i2-=1;
					}
					break;
				case '/':
					if(tample[i1-1]&&tample[i1-2]){
						d[i2-2]/=d[i2-1];
						d.erase(d.begin()+i-1);
						code[i]='0';
						code.erase(i-2,2);
						i-=2;
						i1-=2;
						i2-=1;
					}
					break;
				case '*':
					if(tample[i1-1]&&tample[i1-2]){
						d[i2-2]*=d[i2-1];
						d.erase(d.begin()+i-1);
						code[i]='0';
						code.erase(i-2,2);
						i-=2;
						i1-=2;
						i2-=1;
					}
					break;
				case 'f':
					if(tample[i1-1]){
						d[i2-1]=fabs(d[i2-1]);
						code[i]='0';
						code.erase(i-1,1);
						i-=1;
						i1-=1;
					}
					break;
				case 'e':
					if(tample[i1-1]){
						d[i2-1]=exp(d[i2-1]);
						code[i]='0';
						code.erase(i-1,1);
						i-=1;
						i1-=1;
					}
					break;
				case 'l':
					if(tample[i1-1]){
						d[i2-1]=log(d[i2-1]);
						code[i]='0';
						code.erase(i-1,1);
						i-=1;
						i1-=1;
					}
					break;
				case 'a':
					if(tample[i1-1]){
						d[i2-1]=atan(d[i2-1]);
						code[i]='0';
						code.erase(i-1,1);
						i-=1;
						i1-=1;
					}
					break;
				case 's':
					if(tample[i1-1]){
						d[i2-1]=sin(d[i2-1]);
						code[i]='0';
						code.erase(i-1,1);
						i-=1;
						i1-=1;
					}
					break;
				case 'c':
					if(tample[i1-1]){
						d[i2-1]=cos(d[i2-1]);
						code[i]='0';
						code.erase(i-1,1);
						i-=1;
						i1-=1;
					}
					break;
				default:
					cout<<"����δ֪��dna����"<<endl;
					system("pause");
					break;
			}
		}	
		*/
		//��Ӧ������ 
		float a=0;
		for (int i=0;i<20;i++){
			a+=powl(environment[i][2]-this->output(environment[i][0],environment[i][1]),2);
		}
		this->c_p=a;
	}
	//�Ŵ�����캯��
	DNA(const DNA p1,const DNA p2){
		int need;
		int i,j;
		int const1=0,const2=0;
		const1=p1.d.size();
		if(rand()%1000/1000.0<Pov[0]+Pov[1]){//�������� 
			if(rand()%1000/1000.0<Pov[0]/(Pov[1]+Pov[0])){//������� 
				//���DNA 
				this->code=p1.code+p2.code;
				//�������� 
				switch(rand()%4){
					case 0:
						code.push_back('+');
						break;
					case 1:
						code.push_back('-');
						break;
					case 2:
						code.push_back('*');
						break;
					case 3:
						code.push_back('/');
						break;
				}
				//��ϳ���
				this->d=p1.d;
				this->d.insert(this->d.end(),p2.d.begin(),p2.d.end());
			}
			else{//�������
			 	//��ȡparent2���Ұ������������ɣ� 
			 	int t;
				for(t=p2.code.length();t>=0;t--){
					if(p2.code[t]=='+'||p2.code[t]=='-'||p2.code[t]=='*'||p2.code[t]=='/'){
			 			break;
					}
				}
			 	
				need=0;
				for(j=t;j>=0;j--){
					switch(p2.code[j]){
						case '+':
							need++;
							break;
						case '-':
							need++;
							break;
						case '/':
							need++;
							break;
						case '*':
							need++;
							break;
						case '0':
							const2++;
							need--;
							break;
						case '1': 
							need--;
							break;	
						case '2': 
							need--;
							break;	
						default:
							break;
					}
					if(need==0){break;}
				}
				//��ȡDNA 
				this->code=p2.code;
				this->code.erase(t);
				this->code.erase(0,j);
				//��ȡ����
				this->d.assign(p2.d.end()-const2,p2.d.end());
			}
		}
		else{//�����Ŵ�
			need=0;
			//��ȡparent1�ŵ�����������������ɣ� 
			int t;
			for(t=p1.code.length()-1;t>=0;t--){
				if(p1.code[t]=='+'||p1.code[t]=='-'||p1.code[t]=='*'||p1.code[t]=='/'){
		 			break;
				}
			}
			for(i=t;i>=0;i--){
				switch(p1.code[i]){
					case '+':
						need++;
						break;
					case '-':
						need++;
						break;
					case '/':
						need++;
						break;
					case '*':
						need++;
						break;
					case '0':
						const1--;
						need--;
						break;
					case '1': 
						need--;
						break;	
					case '2': 
						need--;
						break;	
					default:
						break;
				}
				if(need==0){break;}
			}
			//��ȡparent2���Ұ������������ɣ�
			need=0;
			for(t=p2.code.length()-1;t>=0;t--){
				if(p2.code[t]=='+'||p2.code[t]=='-'||p2.code[t]=='*'||p2.code[t]=='/'){
		 			break;
				}
			}
			for(j=t;j>=0;j--){
				switch(p2.code[j]){
					case '+':
						need++;
						break;
					case '-':
						need++;
						break;
					case '/':
						need++;
						break;
					case '*':
						need++;
						break;
					case '0':
						const2++;
						need--;
						break;
					case '1': 
						need--;
						break;	
					case '2': 
						need--;
						break;	
					default:
						break;
				}
				if(need==0){break;}
			}
			//���DNA 
			this->code=p2.code;
			this->code.erase(0,j);
			string tam;
			tam=p1.code;
			tam.erase(i);
			this->code=tam+this->code;
			//��ϳ���ֵ
			int z;
			z=p1.d.size();
			for(int i=0;i<const1;i++){
				this->d.push_back(p1.d[i]);
			}
			z=p2.d.size();
			for(int i=0;i<const2;i++){
				this->d.push_back(p2.d[z-const2+i]);
			}
		}
		//���ֱ���
		if(rand()%1000/1000.0<Pov[2]){
			vector<vector <int> > tample;
			int num=0;
			for(int i=0;i<code.size();i++){
				if(code[i]=='0'||code[i]=='1'||code[i]=='2'){
					vector <int> t;
					t.push_back(i);
					if(code[i]=='0'){
						t.push_back(num);
						num++;
					}
					else{
						t.push_back(num);
					}
					tample.push_back(t);
				}
			}
			int a;
			a=rand()%tample.size();
			if(code[tample[a][0]]=='0'){
				d.erase(d.begin()+tample[a][1]);
				if(rand()%2){
					code[tample[a][0]]='1';
				}
				else{
					code[tample[a][0]]='2';
				}
			}
			else{
				if(code[tample[a][0]]=='1'){
					if(rand()%1){
						code[tample[a][0]]='0';
						d.insert(d.begin()+tample[a][1],rand()%1000/1000.0);
					}
					else{
						code[tample[a][0]]='2';
					}
				}
				else{
					if(code[tample[a][0]]=='2'){
						if(rand()%1){
							code[tample[a][0]]='0';
							d.insert(d.begin()+tample[a][1],rand()%1000/1000.0);
						}
						else{
							code[tample[a][0]]='1';
						}
					}
				}
			}
		}
		//���ű���
		if(rand()%1000/1000.0<Pov[3]){
			vector<vector <int> > tample;
			for(int i=0;i<code.length();i++){
				if(code[i]!='0'&&code[i]!='1'&&code[i]!='2'){
					vector <int> t;
					t.push_back(i);
					if(code[i]=='+'||code[i]=='-'||code[i]=='*'||code[i]=='/'){
						t.push_back(0);
					}
					else{
						t.push_back(1);
					}
					tample.push_back(t);
				}
			}
			
			int a=rand()%tample.size();
			if(tample[a][1]){
				switch(rand()%6){
					case 0:
						code[tample[a][0]]='f';
						break;
					case 1:
						code[tample[a][0]]='e';
						break;
					case 2:
						code[tample[a][0]]='l';
						break;
					case 3:
						code[tample[a][0]]='a';
						break;
					case 4:
						code[tample[a][0]]='s';
						break;
					case 5:
						code[tample[a][0]]='c';
						break;
				}
			}
			else{
				switch(rand()%4){
					case 0:
						code[tample[a][0]]='+';
						break;
					case 1:
						code[tample[a][0]]='-';
						break;
					case 2:
						code[tample[a][0]]='*';
						break;
					case 3:
						code[tample[a][0]]='/';
						break;
				}
			}
		}
		//��Ӧ������ 
		float a=0;
		for (int i=0;i<20;i++){
			a+=powl(environment[i][2]-this->output(environment[i][0],environment[i][1]),2);
		}
		this->c_p=a;
	}
};
int main(){
	Engine *ep;

	// open engine
	if (!(ep = engOpen("\0")))
	{
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		return EXIT_FAILURE;
	}

	double xx[20] = { -0.8,-0.4,0.0,0.6,-0.8,-0.4,0.0,0.6,-0.8,-0.4,0.2,0.6,-0.8,-0.4,0.2,0.6,-0.8,-0.2,0.2,0.6 };
	double yy[20] = { -0.4,-0.4,0.8,-0.8,-0.2,-0.6,1.0,-0.6,0.0,-0.8,-0.8,-0.4,-0.2,-0.8,-0.6,-0.2,-0.4,-0.6,-0.4,0.0 };
	double zz[20] = { 0.477,0.825,0.600,0.000,0.566,0.693,0.000,0.529,0.600,0.477,0.566,0.693,0.566,0.566,0.775,0.775,0.447,0.775,0.894,0.800 };

	double x1[181], y1[181], z1[181][181];
	double tt = -0.8;
	for (int ii = 0; ii <= 180; ii++)
	{
		x1[ii] = tt;
		y1[ii] = tt;
		tt += 0.01;
	}

	vector<DNA> population;//DNA�飨���壩
	for(int i=0;i<prine_number;i++){
		population.push_back(DNA());
	}
	vector <float> p_c_p;//��Ӧ������
	int add_c_p=0;//��Ӧ�Ե�����
	ClearVector(p_c_p);
	for(int i=0;i<population.size();i++){
		if(isnan(population[i].c_p)||isinf(population[i].c_p)||population[i].c_p>1.0e+004){
			population.erase(population.begin()+i);
			i--;
		}
	}
	for(int i=0;i<population.size();i++){
		for(int j=0;j<population.size()-i-1;j++){
			if(population[j].c_p>population[j+1].c_p){
				DNA tamporary=population[j];
				population[j]=population[j+1];
				population[j+1]=tamporary;
			}
		}
		p_c_p.insert(p_c_p.begin(),population[population.size()-1-i].c_p);
		add_c_p+=1/p_c_p[0];
	}
	//ÿ���ķ��� 
	for(int generation=0;generation<max_generation;generation++){
		int S=population.size();
		//���ܹ��� 
		for(int i=0;i<num_pre_generation;i++){
			DNA t1,t2;
			float tp1=0,tp2=0;
			tp1=rand()%10000/10000.0;tp2=rand()%10000/10000.0;
			for(int i=0;i<S;i++){
				tp1-=1/(add_c_p*p_c_p[i]);
				tp2-=1/(add_c_p*p_c_p[i]);
				if(tp1<=0){
					t1=population[i];
					tp1=100;
				}
				if(tp2<=0){
					t2=population[i];
					tp2=100;
				}
				if(tp1>1&&tp2>1){
					break;
				}
			}
			population.push_back(DNA(t1,t2));
		}
		ClearVector(p_c_p);
		for(int i=0;i<population.size();i++){
			if(isnan(population[i].c_p)||isinf(population[i].c_p)||population[i].c_p>max_c_p){
				population.erase(population.begin()+i);
				i--;
			}
		}
		for(int i=0;i<population.size();i++){
			for(int j=0;j<population.size()-i-1;j++){
				if(population[j].c_p>population[j+1].c_p){
					DNA tamporary=population[j];
					population[j]=population[j+1];
					population[j+1]=tamporary;
				}
			}
			p_c_p.insert(p_c_p.begin(),population[population.size()-1-i].c_p);
		}
		if((generation+1)%die_generation==0){
			population.erase(population.begin()+population.size()-int(population.size()*die_rate),population.begin()+population.size());
		}
		p_c_p.erase(p_c_p.begin()+p_c_p.size()-int(p_c_p.size()*die_rate),p_c_p.begin()+p_c_p.size());
		for(int i=0;i<p_c_p.size();i++){
			add_c_p+=1/p_c_p[i];
		}
		//��������population[0].output(x,y)���z
	}
	//����������� 
	for(int i=0;i<population.size();i++){
		cout<<population[i].code<<' '<<population[i].c_p<<endl;
	}
	cout<<population.size();

	for (int ii = 0; ii <= 180; ii++)
	{
		for (int jj = 0; jj <= 180; jj++)
		{
			z1[ii][jj] = population[0].output(x1[ii], y1[jj]);
		}
	}

	mxArray *X = NULL, *Y = NULL, *Z = NULL, *Z1 = NULL, *result = NULL;
	X = mxCreateDoubleMatrix(1, 20, mxREAL);
	Y = mxCreateDoubleMatrix(1, 20, mxREAL);
	Z = mxCreateDoubleMatrix(1, 20, mxREAL);
	Z1 = mxCreateDoubleMatrix(181, 181, mxREAL);
	memcpy((void *)mxGetPr(X), (void *)xx, sizeof(xx));
	memcpy((void *)mxGetPr(Y), (void *)yy, sizeof(yy));
	memcpy((void *)mxGetPr(Z), (void *)zz, sizeof(zz));
	memcpy((void *)mxGetPr(Z1), (void *)z1, sizeof(z1));
	engPutVariable(ep, "X", X);
	engPutVariable(ep, "Y", Y);
	engPutVariable(ep, "Z", Z);
	engPutVariable(ep, "Z1", Z1);// put data to engine

	// execute matlab operations
	engEvalString(ep, "scatter3(X,Y,Z,'*');");
	engEvalString(ep, "hold on");
	engEvalString(ep, "X1=-0.8:0.01:1;");
	engEvalString(ep, "Y1=-0.8:0.01:1;");
	engEvalString(ep, "[X1,Y1]=meshgrid(X1,Y1);");
	engEvalString(ep, "mesh(X1,Y1,Z1);");
	engEvalString(ep, "hold off;");

	fgetc(stdin);

	// clean operation
	mxDestroyArray(X);
	mxDestroyArray(Y);
	mxDestroyArray(Z);
	mxDestroyArray(Z1);
	engEvalString(ep, "close;");


	engClose(ep);// �ر�����
}

