//请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
//在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
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