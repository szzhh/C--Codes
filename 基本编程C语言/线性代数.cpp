#include<iostream>//written by ������
#include<iomanip>
#include<math.h>
using namespace std;
class matrix
{
private:
	float a[101][101];//��������
	float b[101][101];//��������
	float c[101][101][101];//������
	float d[101][101][101];//������
	float tr[101][101];//ת�þ���
	float algc[101][101];//����ʽ
	float fol[101][101];//�������
	float in[101][101];//�����
	float tra[101][101];//������
	float tri[101][101];//������
	float algc_tri[101][101];//����ʽ��������
	float sim[101][101];//�������
	float agm[101][101];//�������
	float tra_agm[101][101];//��������������
	float sim_agm[101][101];//���������������
	float sol[101][101];//������ϵ
	int n;//����n
	int i;//����i
	int j;//����j
	int jj;//�����������jj
	int k;//��k��
	int l;//��l��
	int R;//��
	int RR;//����������
public:
	bool higher;//�Ƿ񳬳��������з�Χ
	bool full;//�ж��Ƿ�����
	bool square;//�ж��Ƿ�Ϊ����
	void if_square();//�Ƿ�Ϊ����
	void if_full();//�Ƿ�����
	void divider()//�ָ���
	{int q;
	for(q=1;q<=40;q++){cout<<"* ";}
	cout<<endl;
	}
	void chg_tr();//����ת��
	void chg_add();//�������
	void chg_mal();//����˷�
	void chg_fol();//��������
	void chg_in();//������
	void chg_tri(int);//��������
	void chg_algc_tri(int);//����ʽ��������
	void chg_tra();//��������
	void chg_tra_agm();//�������������
	void chg_sim();//���������
	void chg_sim_agm();//��������������
	void basic_solution(bool);//�����Է�����ͨ��
	int caclR();//����
	int caclR_agm();//������������
	float caclalgc(int kk,int ll);//��������ʽ
	float determinant();//������ʽ
	void inputa(bool);//�������
	void outputsim();//����������
	void outputa();//�������
	void outputtra();//���������
	void outputtr();//���ת�þ���
	void outputin();//�������
};
void matrix::inputa(bool sq)//�������
{
	divider();
	if(sq==false){
		cout<<"����~����������������������!"<<endl;
		cout<<"��:";
		cin>>i;
		cout<<"��:";
		cin>>j;
		if(i==j)n=i;
	}
	if(sq==true){
		cout<<"����~�����뷽��Ľ�����!"<<endl;
		cout<<"����:";
		cin>>n;
		i=j=n;
	}
	divider();
	if(i>100||j>100){
		cout<<"�޷�������˸߽׵ķ���ѽ����"<<endl;
		higher=true;
	}
	else{
		cout<<"������������������~"<<endl<<"����:"<<endl;;
		for(k=1;k<=i;k++){
			for(l=1;l<=j;l++){
				cin>>a[k][l];
			}
		}
	}
	divider();
}
void matrix::if_square()//�Ƿ�Ϊ����
{
	if(i!=j)square=false;
	else square=true;
}
void matrix::outputa()//�������
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			cout.precision(2);
			cout.width(5);
			cout.setf(ios::left);
			cout<<a[k][l];
		}
		cout<<endl;
	}
}
void matrix::outputsim()//����������
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(8);
			cout.setf(ios::left);
			cout<<sim[k][l];
		}
		cout<<endl;
	}
}
void matrix::outputtra()//���������
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(8);
			cout.setf(ios::left);
			cout<<tra[k][l];
		}
		cout<<endl;
	}
}
void matrix::outputtr()//���ת�þ���
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(8);
			cout.setf(ios::left);
			cout<<tr[k][l];
		}
		cout<<endl;
	}
}
void matrix::outputin()//�������
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(8);
			cout.setf(ios::left);
			cout<<in[k][l];
		}
		cout<<endl;
	}
}
void matrix::chg_tr()//����ת��
{
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			tr[l][k]=a[k][l];
		}
	}
	outputtr();
}
void matrix::chg_add()//����ӷ�
{
	int d0,ctost;
	bool ctn;
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			d[0][k][l]=a[k][l];
		}
	}
	for(d0=0,ctn=true;ctn==true;d0++){
		cout<<"��������Ҫ���ϵ�"<<i<<"��"<<j<<"�����"<<endl;
		for(k=1;k<=i;k++){
			for(l=1;l<=j;l++){
				cin>>b[k][l];
			}
		}
		for(k=1;k<=i;k++){
			for(l=1;l<=j;l++){
				d[d0+1][k][l]=d[d0][k][l]+b[k][l];
			}
		}
		cout<<"����,������ӵĽ��Ϊ:"<<endl;
		for(k=1;k<=i;k++){
			for(l=1;l<=j;l++){
				cout.setf(ios::fixed);
				cout.precision(2);
				cout.width(8);
				cout.setf(ios::left);
				cout<<d[d0+1][k][l];
			}
			cout<<endl;
		}
		if(d0==100){
			cout<<"���˿�ͣ�°�,���ܲ���"<<endl;
			break;
		}
		divider();
		cout<<"����Ҫ��Ҫ����һ��������?(����!=0/����=0)"<<endl<<"�ж�ָ��:";
		cin>>ctost;
		if(ctost==0)ctn=false;
	}
}
void matrix::chg_mal()//����˷�
{
	int ib,jb,l1,lr,ctost,c0=0;
	bool lor,ctn;
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			c[0][k][l]=a[k][l];
		}
	}
	for(ctn=true;ctn==true;c0++){
		cout<<"����Ҫ��˻����ҳ���?(���=1/�ҳ�=2)"<<endl<<"�ж�ָ��:";
		cin>>lr;
		if(lr!=1&&lr!=2){
			for(;lr!=1&&lr!=2;){
				cout<<"��������Ĳ�����~Ҫ��������Ŷ(���=1/�ҳ�=2)"<<endl<<"�ж�ָ��:";
				cin>>lr;
				divider();
			}
		}
		if(lr==2)lor=true;
		else if(lr==1)lor=false;
		if(lor==true){
			cout<<"Ҫ�������ҳ˾����������~"<<endl;
			cin>>jb;
			cout<<"����Ҫ�ҳ˵�"<<j<<"��"<<jb<<"�ľ��������"<<endl;
			for(k=1;k<=j;k++){
				for(l=1;l<=jb;l++){
					cin>>b[k][l];
				}
			}
			divider();
			for(k=1;k<=i;k++){
				for(l=1;l<=jb;l++){
					c[c0+1][k][l]=0;
					for(l1=1;l1<=j;l1++){
						c[c0+1][k][l]=c[c0+1][k][l]+c[c0][k][l1]*b[l1][l];
					}
				}
			}
			cout<<"����,������˵Ľ��Ϊ:"<<endl;;
			for(k=1;k<=i;k++){
				for(l=1;l<=jb;l++){
					cout.setf(ios::fixed);
					cout.precision(2);
					cout.width(8);
					cout.setf(ios::left);
					cout<<c[c0+1][k][l];
				}
				cout<<endl;
			}
		}
		if(lor==false){
			cout<<"Ҫ��������˾����������~"<<endl;
			cin>>ib;
			cout<<"����Ҫ��˵�"<<ib<<"��"<<j<<"�ľ��������"<<endl;
			for(k=1;k<=ib;k++){
				for(l=1;l<=j;l++){
					cin>>b[k][l];
				}
			}
			divider();
			for(k=1;k<=ib;k++){
				for(l=1;l<=j;l++){
					c[c0+1][k][l]=0;
					for(l1=1;l1<=j;l1++){
						c[c0+1][k][l]=c[c0+1][k][l]+b[k][l1]*c[c0][l1][l];
					}
				}
			}
			cout<<"����,������˵Ľ��Ϊ:"<<endl;
			for(k=1;k<=ib;k++){
				for(l=1;l<=j;l++){
					cout.setf(ios::fixed);
					cout.precision(2);
					cout.width(8);
					cout.setf(ios::left);
					cout<<c[c0+1][k][l];
				}
				cout<<endl;
			}
		}
		if(c0==100){
			cout<<"���˿�ͣ�°�,���ܲ���"<<endl;
			break;
		}
		divider();
		cout<<"����Ҫ��Ҫ����һ��������?(����!=0/����=0)"<<endl<<"�ж�ָ��:";
		cin>>ctost;
		if(ctost==0)ctn=false;
	}
}
float matrix::caclalgc(int kk,int ll)//���������ʽ
{
	int k1,l1;
	for(k1=1,k=1;k<=n;k++,k1++){
		if(k==kk)k++;
		for(l1=1,l=1;l<=n;l1++,l++){
			if(l==ll)l++;
			algc[k1][l1]=a[k][l];
		}
	}
	int p;
	float D=1;
	for(p=1;p<=n-1;p++)chg_algc_tri(p);
	for(p=1;p<=n-1;p++)D*=algc_tri[p][p];
	return D;
}
void matrix::chg_fol()//��������
{
	int k2,l2;
	for(k2=1;k2<=n;k2++){
		for(l2=1;l2<=n;l2++){
			fol[l2][k2]=caclalgc(k2,l2);
		}
	}
}
void matrix::chg_in()//������
{
	float D;
	D=determinant();
	chg_fol();
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			in[k][l]=fol[k][l];
			in[k][l]=in[k][l]/D;
		}
	}
}
void matrix::chg_tri(int t)//��Ϊ������
{
	int g,b,d,e,y,z;
	float c;
	if(t==1){
		for(y=1;y<=i;y++){
			for(z=1;z<=j;z++){
				tri[y][z]=a[y][z];
			}
		}
	}
	if(tri[t][t]==0){
		for(g=t+1;g<=n;g++){
			if(tri[g][t]!=0){
				for(b=1;b<=n;b++)swap(tri[t][b],tri[g][b]);
				break;
			}
		}
	}
	if(tri[t][t]!=0){
		for(d=t+1;d<=n;d++){
			c=tri[d][t]/tri[t][t];
			for(e=1;e<=n;e++){
				tri[d][e]=tri[d][e]-c*tri[t][e];
			}
		}
	}
}
void matrix::chg_algc_tri(int t)//����ʽ��Ϊ������
{
	int g,b,d,e,y,z;
	float c;
	if(t==1){
		for(y=1;y<=i-1;y++){
			for(z=1;z<=j-1;z++){
				algc_tri[y][z]=algc[y][z];
			}
		}
	}
	if(algc_tri[t][t]==0){
		for(g=t+1;g<=n-1;g++){
			if(algc_tri[g][t]!=0){
				for(b=1;b<=n-1;b++){swap(algc_tri[t][b],algc_tri[g][b]);}
				break;
			}
		}
	}
	if(algc_tri[t][t]!=0){
		for(d=t+1;d<=n-1;d++){
			c=algc_tri[d][t]/algc_tri[t][t];
			for(e=1;e<=n-1;e++){
				algc_tri[d][e]=algc_tri[d][e]-c*algc_tri[t][e];
			}
		}
	}
}
float matrix::determinant()//������ʽ
{
	int p;
	float D=1;
	for(p=1;p<=n;p++)chg_tri(p);
	for(p=1;p<=n;p++)D*=tri[p][p];
	return D;
}
void matrix::chg_tra()//��������
{
	float f;
	int b,c,d,e;
	int w,x,y,z;
	for(y=1;y<=i;y++){
		for(z=1;z<=j;z++){
			tra[y][z]=a[y][z];
		}
	}
	for(w=x=1;x<=j;w++,x++){
		if(fabs(tra[w][x]-0)<1e-6){
			for(b=w+1;b<=i;b++){
				if(tra[b][w]!=0){
					for(c=1;c<=j;c++){swap(tra[w][c],tra[b][c]);}
					break;
				}
			}
		}
		if(fabs(tra[w][x]-0)>1e-6){
			for(d=w+1;d<=i;d++){
				f=tra[d][x]/tra[w][x];
				for(e=1;e<=j;e++){
					tra[d][e]=tra[d][e]-f*tra[w][e];
				}
			}
		}
		if(tra[w][x]==0)w-=1;
	}
}
void matrix::chg_tra_agm()//�������������
{
	float f;
	int b,c,d,e;
	int w,x,y,z;
	for(y=1;y<=i;y++){
		for(z=1;z<=jj;z++){
			tra_agm[y][z]=agm[y][z];
		}
	}
	for(w=x=1;x<=jj;w++,x++){
		if(tra_agm[w][x]==0){
			for(b=w+1;b<=i;b++){
				if(tra_agm[b][w]!=0){
					for(c=1;c<=jj;c++){swap(tra_agm[w][c],tra_agm[b][c]);}
					break;
				}
			}
		}
		if(fabs(tra_agm[w][x]-0)>1e-6){
			for(d=w+1;d<=i;d++){
				f=tra_agm[d][x]/tra_agm[w][x];
				for(e=1;e<=jj;e++){
					tra_agm[d][e]=tra_agm[d][e]-f*tra_agm[w][e];
				}
			}
		}
		if(tra_agm[w][x]==0)w-=1;
	}
}
void matrix::chg_sim()//���������
{
	int b,c;
	float f;
	chg_tra();
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			sim[k][l]=tra[k][l];
		}
	}
	for(k=1;k<=i;k++){
		for(l=1;l<=j;l++){
			if(fabs(sim[k][l]-0)>1e-6)break;
		}
		if(l<=j){
			for(b=l;b<=j;b++){
				sim[k][b]=sim[k][b]/sim[k][l];
			}
			for(b=k-1;b>=1;b--){
				f=sim[b][l]/sim[k][l];
				for(c=1;c<=j;c++){
					sim[b][c]=sim[b][c]-f*sim[k][c];
				}
			}
		}
	}
}
void matrix::chg_sim_agm()//��������������
{
	int b,c;
	float f;
	chg_tra_agm();
	for(k=1;k<=i;k++){
		for(l=1;l<=jj;l++){
			sim_agm[k][l]=tra_agm[k][l];
		}
	}
	for(k=1;k<=i;k++){
		for(l=1;l<=jj;l++){
			if(fabs(sim_agm[k][l]-0)>1e-6)break;
		}
		if(l<=j){
			for(b=l;b<=jj;b++){
				sim_agm[k][b]=sim_agm[k][b]/sim_agm[k][l];
			}
			for(b=k-1;b>=1;b--){
				f=sim_agm[b][l]/sim_agm[k][l];
				for(c=1;c<=jj;c++){
					sim_agm[b][c]=sim_agm[b][c]-f*sim_agm[k][c];
				}
			}
		}
	}
}
void matrix::basic_solution(bool equal)//�����Է�����ͨ��
{
	if_full();
	if(equal==true&&full==true)cout<<"������ֻ�����"<<endl;
	else{
		int au[101];
		bool aut[101];
		int p,q=1,r=j,k1,l1;
		for(p=1;p<=100;p++)*(au+p)=0;
		for(k=1;k<=100;k++){
			aut[k]=false;
			for(l=1;l<=100;l++){
				sol[k][l]=0;
			}
		}
		chg_sim();
		for(k=i;k>=1;k--){//ȷ����δ֪��
			for(l=1;l<=j;l++){
				if(sim[k][l]!=0)break;
			}
			if(l==j+1)continue;
			for(p=l+1;;p++){
				if(p>r){
					r=l-1;
					break;
				}			
				*(au+q)=p;
				q++;
			}
		}
		for(p=1;p<=100;p++){
			if(au[p]==0){
				p--;
				break;
			}
		}
		for(l=p;l>=1;l--){
			sol[au[l]][l]=1;
			aut[au[l]]=true;
		}
		for(l=p;l>=1;l--){
			for(k=1,k1=1;k<=j-p;k++,k1++){
				for(;k<=i;k++){
					if(aut[k]==false)break;
				}
				sol[k][l]=-sim[k1][au[l]];
			}
		}
		l1=p;
		if(equal==true){
			cout<<"����,ͨ��Ϊ:"<<endl;
			cout<<"(";
			for(p=1;p<=j;p++){
				printf("x%d",p);
				if(p==j)break;
				cout<<",";
			}
			cout<<")T=";
			for(l=1;l<=l1;l++){
				printf("k%d(",l);
				for(k=1;k<=j;k++){
					cout<<sol[k][l];
					if(k==j)break;
					cout<<",";
				}
				cout<<")T";
				if(l==l1)break;
				cout<<"+";
			}
		}
		if(equal==false){
			jj=j+1;
			for(k=1;k<=i;k++){
				for(l=1;l<=j;l++){
					agm[k][l]=a[k][l];
				}
			}
			cout<<"���뷽����ĳ����������"<<endl;
			for(k=1;k<=i;k++)cin>>agm[k][jj];
			chg_sim_agm();
			for(k=1;k<=i;k++)sol[k][0]=agm[k][jj];
			R=caclR();
			RR=caclR_agm();
			if(RR>R)cout<<"�������޽�������";
			else if(i==j&&R==n){
				cout<<"��������Ψһ��������"<<endl<<"������Ľ�����Ϊ(";
				for(k=1;;k++){
					cout<<sol[k][0];
					if(k==i)break;
					cout<<",";
				}
				cout<<")";
			}
			else{
				cout<<"����,ͨ��Ϊ";
				cout<<"����,ͨ��Ϊ:"<<endl;
				cout<<"(";
				for(p=1;p<=j;p++){
					printf("x%d",p);
					if(p==j)break;
					cout<<",";
				}
				cout<<")T=";
				cout<<"(";
				for(k=1;;k++){
					cout<<sol[k][0];
					if(k==i)break;
					cout<<",";
				}
				cout<<")T+";
				for(l=1;l<=l1;l++){
					printf("k%d(",l);
					for(k=1;k<=j;k++){
						cout<<sol[k][l];
						if(k==j)break;
						cout<<",";
					}
					cout<<")T";
					if(l==l1)break;
					cout<<"+";
				}
			}
		}
		cout<<endl;
	}
}
int matrix::caclR()//����
{
	bool zero=true;
	int m;
	chg_tra();
	for(m=i;zero==true&&m>=1;m--){
		if(fabs(tra[m][j]-0)>1e-6)zero=false;
	}
	m+=1;
	return m;
}
int matrix::caclR_agm()//������������
{
	bool zero=true;
	int m;
	chg_tra_agm();
	for(m=i;zero==true&&m>=1;m--){
		if(fabs(tra_agm[m][j]-0)>1e-6)zero=false;
	}
	m+=1;
	return m;
}
void matrix::if_full()//�ж��Ƿ�����
{
	R=caclR();
	if(i==j&&R==n)full=true;
	else full=false;
}
int main()
{
	int yon;
	bool inside,outside,square,equal;
	cout<<"LMX is charming!"<<endl;
	matrix *mat;
	for(outside=true;outside==true;){
		mat=new matrix;
		int which;
		enum way {CHGTR=1,CHGTA,CALR,CHGSR,BSSL,CALAD,CALML,CALD,CALIN};//(����ת��,��������,����,���������,�������ϵ,�������,�������,����ʽ,����)
		way way1;
		cout<<"����~���Ҫ�����ľ����ǲ��Ƿ�����?(����=!0/�Ƿ���=0)"<<endl;
		cout<<"�ж�ָ��:";
		cin>>yon;
		if(yon==0)square=0;
		else square=1;
		mat->inputa(square);
		if(mat->higher==true)return 0;
		for(inside=true;inside==true;){
			cout<<"������Ҫ��ʲô��?"<<endl;
			if(square==true){
				cout<<"(����ת��=1,��������=2,����=3,���������=4,�������ϵ=5,�������=6,�������=7,����ʽ=8,����=9)"<<endl;
				cout<<"����ָ��:";
				do{
					cin>>yon;
					if(yon>8)cout<<"�������,����Ҫ��������Ŷ"<<endl;
				}while(yon>8);
			}
			if(square==false){
				cout<<"(����ת��=1,��������=2,����=3,���������=4,�������ϵ=5,�������=6,�������=7)"<<endl;
				cout<<"����ָ��:";
				do{
					cin>>yon;
					if(yon>8)cout<<"�������,����Ҫ��������Ŷ~"<<endl;
				}while(yon>8);
			}
			which=yon;
			mat->divider();
			way1=way(which);
			if(way1==CHGTR){
				cout<<"����,ת�þ���Ϊ:"<<endl;
				mat->chg_tr();
			}
			if(way1==CALD){
				float D;
				if(mat->higher==true)return 0;
				D=mat->determinant();
				cout.setf(ios::fixed);
				cout.precision(4);
				cout<<"�������ʽ��ֵ��"<<endl<<"*"<<D<<"*��"<<endl;
				cout.unsetf(ios::fixed);
			}
			if(way1==CHGTA){
				mat->chg_tra();
				mat->outputtra();
			}
			if(way1==CALR){
				cout<<"�þ������Ϊ"<<mat->caclR()<<"��"<<endl;
			}
			if(way1==CHGSR){
				mat->chg_sim();
				mat->outputsim();
			}
			if(way1==BSSL){
				cout<<"��������ľ�������η�������?(��η�����=!0/����η�����=0)"<<endl;
				cout<<"�ж�ָ��:";
				cin>>yon;
				if(yon==0)equal=false;
				else equal=true;
				mat->basic_solution(equal);
			}
			if(way1==CALAD){
				mat->chg_add();
			}
			if(way1==CALML){
				mat->chg_mal();
			}
			if(way1==CALIN){
				mat->if_square();
				if(square==false)cout<<"�þ����޷���������~����"<<endl;
				else{
					mat->chg_in();
					cout<<"����,�������Ϊ:"<<endl;
					mat->outputin();
				}
			}
			mat->divider();
			cout<<"���˻���Ҫ�������������Щʲô��?(yes=!0/no=0)"<<endl;
			cout<<"�ж�ָ��:";
			cin>>yon;
			if(yon==0)inside=0;
			else inside=1;
		}
		delete mat;
		cout<<"���˻���Ҫ������ľ�����?(yes=!0/no=0)"<<endl;
		cout<<"�ж�ָ��:";
		cin>>yon;
		if(yon==0)outside=0;
		else outside=1;
	}
	return 0;
}
