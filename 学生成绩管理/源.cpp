
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string> 
using namespace std;
const int MAX_STUDENT_NUM = 30;
class Student
{
public:
	void inputId();//����ѧ�� 
	void inputName();// �������� 
	void inputRegularGrade();//����ƽʱ�ɼ� 
	void inputFinaExam();//������ĩ���Գɼ� 
	int getId();// ���ѧ��
	static void heading()//����ɼ�����
	{
		cout << setw(10) << "ѧ��" << setw(10) << "����" << setw(10) << "ƽʱ" << setw(10) << "��ĩ" << endl;
	}
	void output();//����ɼ���Ϣ 
	float CalTatalMark();//���������ɼ�=ƽʱ*50%+��ĩ*50%
private:
	int id;//ѧ��
	char name[20]; //����
	float regularGrade;//ƽʱ�ɼ�
	float finalExam;//��ĩ���Գɼ� 
};
void Student::inputId()
{
	cout << "������ѧ�ţ�1-40֮�䣩��";
	cin >> id;
	while (id < 1 || id>40)
	{
		cout << "����ѧ����������������ѧ�ţ�1-40֮�䣩: " << endl;
		cin >> id;
	}

}
void Student::inputName()
{
	cin.ignore(80, '\n');
	cout << "������������";
	cin.getline(name, 20);
}
void Student::inputRegularGrade()
{
	cout << "������ƽʱ�ɼ���0-100֮�䣩��";
	cin >> regularGrade;
	while (regularGrade < 0 || regularGrade>100)
	{
		cout << "������󣬳ɼ�Ӧ����0��100֮�䣡" << endl;
		cout << "������ƽʱ�ɼ���0-100֮�䣩��";
		cin >> regularGrade;
	}
}
void Student::inputFinaExam()
{
	cout << "��������ĩ���Գɼ���0-100֮�䣩��";
	cin >> finalExam;
	while (finalExam < 0 || finalExam>100)
	{
		cout << "������󣬳ɼ�Ӧ����0��100֮�䣡" << endl;
		cout << "��������ĩ���Գɼ���0-100֮�䣩��";
		cin >> finalExam;
	}
}
int Student::getId()
{
	return id;
}

void Student::output()
{
	cout << setw(10) << id << setw(10) << name << setiosflags(ios::fixed) << setprecision(1) << setw(10) << regularGrade << setw(10) << finalExam << endl;
}

float Student::CalTatalMark()
{
	return regularGrade * 0.5 + finalExam * 0.5;
}

//¼������ѧ����Ϣ 
void Input(Student stu[], int& num)
{
	//	float score;//ѧ���ɼ�
	int i = 0; //����
	string str;//�����ж��Ƿ����������ַ���
	if (num == 0)
	{
		while (true)
		{
			stu[i].inputId();
			for (int j = 0;j < num;j++)
			{
				if (stu[i].getId() == stu[j].getId())
				{
					cout << "ѧ�Ų������ظ�����ѧ���Ѿ����ڣ�\n";
					stu[i].inputId();
				}
			}
			stu[i].inputName();
			stu[i].inputRegularGrade();
			stu[i].inputFinaExam();
			i++;
			num = i;
			cout << "��������ѧ�������밴y��Y��";
			cin >> str;
			if (i == MAX_STUDENT_NUM)
			{
				cout << "�����Ѵﵽ" << MAX_STUDENT_NUM << "�����ޣ��޷������룡\n";
				break;
			}
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
	else //����ѧ����Ϣ 
	{
		if (num == MAX_STUDENT_NUM)
		{
			cout << "�����Ѵﵽ" << MAX_STUDENT_NUM << "�����ޣ��޷��ٲ��룡\n";
		}
		else
		{
			i = num;//��ǰ����Ԫ�ظ���
			while (true)
			{
				stu[i].inputId();
				for (int j = 0;j < num;j++)
				{
					if (stu[i].getId() == stu[j].getId())
					{
						cout << "ѧ�Ų������ظ�����ѧ���Ѿ����ڣ�\n";
						stu[i].inputId();
					}
				}
				stu[i].inputName();
				stu[i].inputRegularGrade();
				stu[i].inputFinaExam();
				i++;
				num = i;
				cout << "��������ѧ�������밴y��Y��";
				cin >> str;
				if (i == MAX_STUDENT_NUM)
				{
					cout << "�����Ѵﵽ" << MAX_STUDENT_NUM << "�����ޣ��޷������룡\n";
					break;
				}
				if (str == "y" || str == "Y")
				{
					continue;
				}
				else
				{
					break;
				}
			}
		}
	}
}
//�����ʾ�ɼ���Ϣ 
void Output(Student stu[], int num)
{
	if (num != 0)
	{
		stu[0].heading();//ѧ����Ϣ����
		for (int i = 0;i < num;i++)
		{
			stu[i].output();
		}
	}
	else
	{
		cout << "���޳ɼ���Ϣ����ѡ��1=¼��ѧ����Ϣ" << endl;
	}
}
//������������ 
void Order(Student stu[], int num)
{
	if (num != 0)
	{
		int i, j, k;
		Student temp;
		for (i = 0;i < num;i++)
		{
			for (j = 0;j < num - i - 1;j++)
			{
				if (stu[j].CalTatalMark() < stu[j + 1].CalTatalMark())
				{
					temp = stu[j];
					stu[j] = stu[j + 1];
					stu[j + 1] = temp;
				}
			}
		}
		stu[0].heading();//ѧ����Ϣ����
		for (k = 0;k < num;k++)
		{
			stu[k].output();
		}
		cout << endl;
	}
	else
	{
		cout << "���޳ɼ���Ϣ����ѡ��1=¼��ѧ����Ϣ" << endl;
	}
}

//����ѧ����Ϣ 
void Search(Student stu[], int num)
{
	int id;
	string str;//�����ж��Ƿ����������ַ���
	while (true)
	{
		cout << "��������Ҫ���ҵ�ѧ�ţ�";
		cin >> id;
		int flag = 0;
		if (id >= 1 && id <= 40)
		{
			for (int i = 0;i < num;i++)
			{
				if (stu[i].getId() == id)
				{
					flag++;
				}
			}
			if (flag == 0)
			{
				cout << "û�и�ѧ��ѧ����Ϣ��" << endl;
			}
			else
			{
				stu[0].heading();//ѧ����Ϣ����
				for (int i = 0;i < num;i++)
				{
					if (stu[i].getId() == id)
					{
						stu[i].output();
					}
				}
			}
			cout << "���������밴y��Y��";
			cin >> str;
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "����ѧ����������������ѧ�ţ�1-40֮�䣩\n " << endl;
			cout << "���������밴y��Y��";
			cin >> str;
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
}

void Delete(Student stu[], int& num)
{
	int id;
	string str;//�����ж��Ƿ����������ַ���
	while (true)
	{
		cout << "������Ҫɾ��ѧ����ѧ�ţ�";
		cin >> id;
		int flag = 0;//����ͳ��ɾ����ʣ�������Ԫ�ظ���
		Student a[100];
		if (id >= 1 && id <= 40)
		{
			for (int i = 0;i < num;i++)
			{
				if (stu[i].getId() != id)
				{
					a[flag] = stu[i];
					flag++;
				}
			}
			if (flag == num)
			{
				cout << "û�и�ѧ��ѧ����" << endl;
			}
			else
			{
				num = flag;
				for (int k = 0;k < num;k++)
				{
					stu[k] = a[k];
				}
				cout << id << "��ѧ����Ϣɾ���ɹ���" << endl;
			}
			cout << "����ɾ������ѧ���밴y��Y��";
			cin >> str;
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			cout << "����ѧ����������������ѧ�ţ�1-40֮�䣩��\n";
			cout << "����ɾ������ѧ���밴y��Y��";
			cin >> str;
			if (str == "y" || str == "Y")
			{
				continue;
			}
			else
			{
				break;
			}
		}
	}
}

//ͳ������ 
void Statis(Student stu[], int num)
{
	int	i, a[5] = { 0 };
	for (i = 0;i < num;i++)
	{
		if (stu[i].CalTatalMark() >= 90 && stu[i].CalTatalMark() <= 100)
		{
			a[0] += 1;
		}
		else if (stu[i].CalTatalMark() >= 80 && stu[i].CalTatalMark() < 90)
		{
			a[1] += 1;
		}
		else if (stu[i].CalTatalMark() >= 70 && stu[i].CalTatalMark() < 80)
		{
			a[2] += 1;
		}
		else if (stu[i].CalTatalMark() >= 60 && stu[i].CalTatalMark() < 70)
		{
			a[3] += 1;
		}
		else
		{
			a[4] += 1;
		}
	}
	cout << "     100~90    89~80    79~70    69~60     <60" << endl;
	for (i = 0;i < 5;i++)
	{
		cout << setw(9) << a[i];
	}
	cout << endl;
}

//���˵� 
void Menu()
{
	cout << "          =================================================\n";
	cout << "          =              ��ӭʹ�óɼ�����ϵͳ             =\n";
	cout << "          =           1=¼��ѧ��     2=��ʾ��Ϣ           =\n";
	cout << "          =           3=��������     4=����ѧ��           =\n";
	cout << "          =           5=����ѧ��     6=ɾ��ѧ��           =\n";
	cout << "          =           7=ͳ������     0=�˳�               =\n";
	cout << "          =================================================\n";
	cout << "��ѡ��:";
}

int main()
{
	int currentN = 0;
	Student stu[MAX_STUDENT_NUM];
	/*���ļ������� */
	ifstream filein("students.dat", ios::binary);
	if (filein)
	{
		filein.read((char*)&currentN, sizeof(currentN));
		for (int i = 0;i < currentN;i++)
		{
			filein.read((char*)&stu[i], sizeof(stu[i]));
		}
	}
	filein.close();
	string a;//�����жϲ˵�ѡ��,��string 
	Menu();
	while (cin >> a)
	{

		if (a == "1")
		{
			cout << "��ѡ����1=¼��ѧ��" << endl;
			Input(stu, currentN);//����
			Menu();
		}
		else if (a == "2")
		{
			cout << "��ѡ����2=��ʾ��Ϣ" << endl;
			Output(stu, currentN);//����ɼ���Ϣ
			Menu();
		}
		else if (a == "3")
		{
			cout << "��ѡ����3=��������" << endl;
			Order(stu, currentN);
			Menu();
		}
		else if (a == "4")
		{
			cout << "��ѡ����4=����ѧ��" << endl;
			Search(stu, currentN);
			Menu();
		}
		else if (a == "5")
		{
			cout << "��ѡ����5=����ѧ��" << endl;
			Input(stu, currentN);
			Menu();
		}
		else if (a == "6")
		{
			cout << "��ѡ����6=ɾ��ѧ��" << endl;
			Delete(stu, currentN);
			Menu();
		}
		else if (a == "7")
		{
			cout << "��ѡ����7=ͳ������" << endl;
			Statis(stu, currentN);
			Menu();
		}
		else if (a == "0")
		{
			/*���ļ�д������*/
			ofstream fileout("students.dat", ios::binary);
			if (!fileout)
			{
				cout << "�ļ����ܱ��򿪣�" << endl;
				return 0;
			}
			fileout.write((char*)&currentN, sizeof(currentN));
			for (int i = 0;i < currentN;i++)
			{
				fileout.write((char*)&stu[i], sizeof(stu[i]));
			}
			fileout.close();
			cout << "�˳��ɹ���" << endl;
			return 0;
		}
		else
		{
			cout << "����Ƿ������������룡" << endl;
			Menu();
		}

	}
	return 0;
}