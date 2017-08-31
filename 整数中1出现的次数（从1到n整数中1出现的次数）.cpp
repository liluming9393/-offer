//���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,
//���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�����
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
#include<sstream>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
int NumberOf1Between1AndN_Solution(int n);
int myNumberOf1(char *str);
int main()
{
	int n = 1001;
	cout << n << endl;
	int result = NumberOf1Between1AndN_Solution(n);
	cout << result << endl;
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
int myNumberOf1(char *str)
{
	if (str == NULL || (*str) < '0' || (*str) > '9' || (*str) == '\0')
	{
		return 0;
	}
	int first = (*str) - '0';
	int length = strlen(str);
	if (length == 1)
	{
		if (first == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	int numfirstdigit = 0;
	if (first > 1)
	{
		numfirstdigit = pow(10, length - 1);
	}
	else if (first == 1)
	{
		numfirstdigit = atoi(str + 1) + 1;
	}
	int numotherdigits = 0;
	numotherdigits = first*(length - 1)*pow(10, length - 2);
	int numrecursive = 0;
	numrecursive = myNumberOf1(str + 1);
	return numfirstdigit + numotherdigits + numrecursive;
}
int NumberOf1Between1AndN_Solution(int n)
{
	if (n <= 0)
	{
		return 0;
	}
	ostringstream ss;
	ss << n;
	string s;
	s = ss.str();
	char *str = (char*)s.c_str();
	int result = myNumberOf1(str);
	return result;
}