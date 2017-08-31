//将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0 
//输入描述:输入一个字符串, 包括数字字母符号, 可以为空
//输出描述 :如果是合法的数值表达则返回该数字，否则返回0
//解题思路：注意输入是否合法，添加不合法标识
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
class Solution {
public:
	int StrToInt(string str) {
		g_nStatus = false;
		long long int result = 0;
		bool minus = false;
		if (str.size() != 0)
		{
			int i = 0;
			if (str[0] == '-')
			{
				minus = true;
				i++;
				if (str.size() == 1)
				{
					return 0;
				}
			}
			else if (str[0] == '+')
			{
				i++;
				if (str.size() == 1)
				{
					return 0;
				}
			}
			for (; i < str.size(); i++)
			{
				if (str[i] < '0' || str[i] > '9')
				{
					return 0;
				}
				result = result * 10 + str[i] - '0';
				if (minus == false && result > INT_MAX)
				{
					return 0;
				}
				else if (minus == true && (-result) < INT_MIN)
				{
					return 0;
				}
			}
			g_nStatus = true;
			if (minus == true)
			{
				result = -result;
			}
		}
		return (int)result;
	}
	bool g_nStatus;
};
int main()
{
	string str = "+123";
	cout << str << endl;
	Solution s;
	int result = s.StrToInt(str);
	if (result == 0)
	{
		if (s.g_nStatus == true)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << "error" << endl;
		}
	}
	else
	{
		cout << result << endl;
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
