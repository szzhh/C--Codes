#include <iostream>
int main()
{
  std::cout << "���Ƿ�֪����Ҳϲ���㣿(Y/N)" << std::endl;
  char c = 0;
  bool loveYou = false;
  std::cin >> c;

  if (c == 'Y')
  {
    loveYou = true;
  }
  else
  {
    loveYou = false;
  }

  if (!loveYou)
  {
    std::cout << "������û�õģ��õ���������\"лл������һ���ܺõ�Ů���������"
                 "�ܸж�������......������лл!\""
              << std::endl;
    std::cout << "����̫�����Ҳ��ҿ���������Դ��Աߵ���ַ";
    std::cout << "https://pic1.zhimg.com/0ed4344f448006bbe91864bef6a5cc80_b.png"
              << std::endl;
    std::cout << "��ײ���������ϲ����ļ��ʣ�����ϲ���㣬�����û���κ��õġ�"
              << std::endl;
  }
  else
  {
    std::cout << "ֱ��Լ���������죬ֱ��˵�ͺã���ʲôC++. "
                 "ǿ��һ�㣬��·��ʱ��ֱ�Ӱ���ǣס�����������ϻص����ң���"
                 "���˵����衣"
              << std::endl;
  }
}
