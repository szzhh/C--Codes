#include <cstdio>
#include <cstring>
#include <iostream>
 
using namespace std;
 
class student       // student ��Ϊ����ϵͳ��һ���ڵ�
{
    friend class studentMessage;
    student      *next;
    char         name[30];
    char         num[30];
    double       score[6];
public:
    student()
    {
        strcpy(name, "null");
        strcpy(num, "null");
        for (int i = 0; i < 6; ++i) score[i] = 0;
    }
    student(const student &a)
    {
        strcpy(name, a.name);
        strcpy(num, a.num);
        for (int i = 0; i < 6; ++i)
            score[i] = a.score[i];
    }
    student &input()
    {
        cout << "������";  cin >> name;
        cout << "ѧ�ţ�";  cin >> num;
        for (int i = 0; i < 5; ++i)
        {
            cout << "�����" << (i + 1) << "�ųɼ�:";
            cin >> score[i];
            score[5] += score[i];
        }
        return *this;
    }
    student* get_next()
    {
        return next;
    }
    void print()
    {
        printf("%8s %10s ", name, num);
        for (int i = 0; i < 6; ++i) printf(" %6.2f ", score[i]);
        printf("\n");
    }
    void Swap() // ������ǰ������һ��
    {
        char temp[30];
        strcpy(temp, name);
        strcpy(name, next->name);
        strcpy(next->name, temp);
 
        strcpy(temp, num);
        strcpy(num, next->num);
        strcpy(next->num, temp);
 
        for (int i = 0; i < 6; ++i)
        {
            int tmp = score[i];
            score[i] = next->score[i];
            next->score[i] = tmp;
        }
    }
};
 
class studentMessage
{
protected:
    student *first;
    student *last;
public:
    studentMessage()
    {
        first = last = new student;
    }
    ~studentMessage()
    {
        Clear();
        delete first;
    }
    studentMessage &Append();           // ������β������ڵ�
    student *Find(const char *x);       // ����
    void Query();                       // ��ѯ
    studentMessage &Delete();           // ɾ�����ҽ��
    studentMessage &Clear();            // ɾ�����н��
    studentMessage &Sort();             // ����i�ſ�����
    void print();                       // ��ʾ���нڵ�
    int menu();                         // ��ʾ�˵�
};
 
studentMessage &studentMessage::Append()
{
    student x;
    x.input();
    student *ptr = last;
    *ptr = x;
    last = new student;
    ptr->next = last;
    return *this;
}
 
studentMessage &studentMessage::Delete()
{
    char x[30];
    cout << "����Ҫɾ������Ϣ��ѧ�Ż�������\n";
    cin >> x;
    student *ptr = Find(x);
 
    if (ptr == last)
    {
        cout << "δ�ҵ������Ϣ\n";
        return *this;
    }
    ptr->print();
    cout << "�Ƿ�ɾ������Ϣ����������1��������0��";
    cin >> x;
    if (*x == '1')
    {
        if (ptr == first)
        {
            first = first->next;
            delete first;
        }
        else
        {
            student *temp = first;
            while (temp->next != ptr) temp = temp->next;
            temp->next = ptr->next;
            delete ptr;
        }
        cout << "��ɾ��\n";
    }
    else
    {
        cout << "��ȡ��\n";
    }
    return *this;
}
 
studentMessage &studentMessage::Clear()
{
    char ch[30];
    cout << "��ɾ��������Ϣ��ȷ���밴Y";
    cin >> ch;
    if (*ch != 'Y' && *ch != 'y')
    {
        cout << "��ȡ��\n";
        return *this;
    }
    student *ptr = first;
    while (ptr != last)
    {
        student *next = ptr->next;
        delete ptr;
        ptr = next;
    }
    first = last;
    return *this;
}
 
void studentMessage::print()
{
    if (first == last)
    {
        cout << "������Ϣ\n";
        return ;
    }
    cout << "---------------------------------�ɼ��б�------------------------------" << endl;
    cout << "���  ����      ѧ��      �ɼ�1   �ɼ�2   �ɼ�3   �ɼ�4   �ɼ�5  �ܳɼ�" << endl;
    int no = 1;
    student *ptr = first;
    while (ptr != last)
    {
        printf("%3d:", no++);
        ptr->print();
        ptr = ptr->next;
    }
}
 
student *studentMessage::Find(const char *x)
{
    student *ptr = first;
    while (ptr != last)
    {
        if (strcmp(ptr->name, x) == 0 || strcmp(ptr->num, x) == 0)
            break;
        ptr = ptr->next;
    }
    return ptr;
}
 
void studentMessage::Query()
{
    char x[30];
    cout << "������Ҫ��ѯ����Ϣ(ѧ�Ż�����)";
    cin >> x;
    student *ptr = Find(x);
    if (ptr == last)
    {
        cout << "û�в�ѯ�������Ϣ\n";
    }
    else
    {
        ptr->print();
    }
}
 
// ð������
studentMessage &studentMessage::Sort()
{
    int x;
    cout << "�������밴�����ſεĳɼ�������?((1-5)�ܳɼ�����6):";
    cin >> x;
    x--;
    student *ptr, *cnt = last;
    while (cnt != first)
    {
        ptr = first;
        while (ptr->next != cnt)
        {
            if (ptr->next->score[x] > ptr->score[x])
            {
                ptr->Swap();
            }
            ptr = ptr->next;
        }
        cnt = ptr;
    }
    return *this;
}
 
int studentMessage::menu()
{
    cout << "===============================\n";
    cout << "      ѧ���ɼ�����ϵͳ\n\n";
    cout << "      1.��ʾ����ѧ���ɼ�\n";
    cout << "      2.�����Ϣ\n";
    cout << "      3.��ѯ��Ϣ\n";
    cout << "      4.ɾ����Ϣ\n";
    cout << "      5.�ɼ�����\n";
    cout << "      6.ɾ��������Ϣ\n";
    cout << "      0.�˳�\n";
    cout << "===============================\n";
 
    int ch;
    cin >> ch;
    return ch;
}
 
int main()
{
    studentMessage ls;
    int ch;
    while (ch = ls.menu())
    {
        switch(ch)
        {
            case 1: ls.print(); break;
            case 2: ls.Append(); break;
            case 3: ls.Query(); break;
            case 4: ls.Delete(); break;
            case 5: ls.Sort(); break;
            case 6: ls.Clear(); break;
        }
    }
 
 
    return 0;
}
