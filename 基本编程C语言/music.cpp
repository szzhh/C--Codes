#include <stdio.h>
#include <conio.h>
#include <Windows.h>

/*����1/8ʱ�䳤��Ϊ225ms������*/
const unsigned PER = 225;

/*�������ף�����*/
enum { Do = 262, Re = 294, Mi = 330, Fa = 349, So = 392, La = 440, Xi = 494 };
/*���岥��һ�������ĺ���
f--��ʾ��������ֵΪ���������ö����
a--	��ʾ���ߣ���ֵΪ1(����)��2(����)��3(����)
*/

void Play(int f, int a, int t)
{
	int i = 0;
	Beep((unsigned)(f*a), t*PER);
}

/*������ֹ����*/
void Stop(int t)
{
	Sleep(t*PER);
}

int main()
{
	while (1)
	{
		/*�����̣���һ��*/
		/*��һ��:3 3 4 5*/
		Play(Mi, 2, 2); Play(Mi, 2, 2); Play(Fa, 2, 2); Play(So, 2, 2);

		/*�ڶ���:5 4 3 2*/
		Play(So, 2, 2); Play(Fa, 2, 2); Play(Mi, 2, 2); Play(Re, 2, 2);

		/*������:1 1 2 3*/
		Play(Do, 2, 2); Play(Do, 2, 2); Play(Re, 2, 2); Play(Mi, 2, 2);

		/*���Ľ�:3 2 2 -*/
		Play(Mi, 2, 2); Play(Re, 2, 2); Play(Re, 2, 4);

		/*�����̵ڶ���*/
		/*��һ��:3 3 4 5*/
		Play(Mi, 2, 2); Play(Mi, 2, 2); Play(Fa, 2, 2); Play(So, 2, 2);

		/*�ڶ���:5 4 3 2*/
		Play(So, 2, 2); Play(Fa, 2, 2); Play(Mi, 2, 2); Play(Re, 2, 2);

		/*������:1 1 2 3*/
		Play(Do, 2, 2); Play(Do, 2, 2); Play(Re, 2, 2); Play(Mi, 2, 2);

		/*���Ľ�:2 1 1 -*/
		Play(Re, 2, 2); Play(Do, 2, 2); Play(Do, 2, 2);
	}

	Stop(0);

	return 0;
}
