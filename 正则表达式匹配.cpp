//��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
//�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<queue>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
bool match(char* str, char* pattern);
int main()
{
	char str[] = "abaa";
	cout << str << endl;
	char pattern[] = "ab*aa";
	cout << pattern << endl;
	bool result = match(str, pattern);
	if (result)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}
void Display_1D_Matrix(vector<int> & data)
{
	if (data.size() == 0)
	{
		return;
	}
	for (int i = 0; i < data.size() - 1; i++)
	{
		cout << data[i] << " ";
	}
	cout << data[data.size() - 1] << endl;
}
void Display_2D_Matrix(vector<vector<int>> & data)
{
	if (data.size() == 0)
	{
		return;
	}
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size() - 1; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << data[i][data[i].size() - 1] << endl;
	}
}
bool match(char* str, char* pattern)
{
	if ((*str) == '\0' && (*pattern) == '\0')
	{
		return true;
	}
	if ((*str) != '\0' && (*pattern) == '\0')
	{
		return false;
	}
	if ((*(pattern + 1)) == '*')
	{
		if ((*str) == (*pattern) || ((*pattern) == '.' && (*str) != '\0'))
		{
			return match(str + 1, pattern) || match(str, pattern + 2);
		}
		else
		{
			return match(str, pattern + 2);
		}
	}
	if ((*str) == (*pattern) || ((*pattern) == '.' && (*str) != '\0'))
	{
		return match(str + 1, pattern + 1);
	}
	return false;
}