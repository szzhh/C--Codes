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
#include "DNA.h"

using namespace std;

//���vector 
template < class T >
void ClearVector( vector< T >& vt ) 
{
    vector< T > vtTemp;
    vtTemp.swap( vt );
}


int main(){
	srand(time(NULL));
	double x1[181], y1[181], zz1[181][181];
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
	printf("%s\n","hello");
	//����������� 
	for(int i=0;i<population.size();i++){
		cout<<population[i].code<<' '<<population[i].c_p<<endl;
	}
	cout<<population.size();

}

