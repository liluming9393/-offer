//��ʵ��һ����������һ���ַ����еĿո��滻�ɡ� % 20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are % 20Happy��
//�Ӻ���ǰ�����滻�����㷨���Ӷ�
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
void replaceSpace(char *str, int length);
int main()
{
	char str[50] = { "We are happy." };
	cout << str << endl;
	replaceSpace(str, 50);
	cout << str << endl;
	system("pause");
	return 0;
}
//lengthΪ����������
void replaceSpace(char *str, int length)
{
	if (str == NULL || length == 0)
	{
		return;
	}
	int count_space = 0;
	int i = 0;
	for (; i < length; i++)
	{
		if (str[i] == '\0')
		{
			break;
		}
		if (str[i] == ' ')
		{
			count_space++;
		}
	}
	int oldlength = i + 1;
	int newlength = oldlength + count_space * 2;
	if (newlength>length)
	{
		return;
	}
	int k = newlength - 1;
	for (int j = oldlength - 1; j >= 0; j--)
	{
		if (str[j] != ' ')
		{
			str[k] = str[j];
			k--;
		}
		else
		{
			str[k] = '0';
			k--;
			str[k] = '2';
			k--;
			str[k] = '%';
			k--;
		}
	}
}