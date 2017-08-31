//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
//但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
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
bool isNumeric(char* string);
int main()
{
	bool result;
	//char* string1 = "+100";
	//char* string1 = "5e2";
	//char* string1 = "-123";
	//char* string1 = "3.13";
	//char* string1 = "-1e-15";
	//char* string1 = "12e";
	//char* string1 = "1a3.14";
	//char* string1 = "1.2.3";
	//char* string1 = "+-5";
	//char* string1 = "12e+5.4";
	char* string1 = "1.2e3";
	result = isNumeric(string1);
	cout << string1 << endl;
	if (result == true)
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
bool isNumeric(char* string)
{
	if (string == NULL)
	{
		return false;
	}
	if ((*string) == '+' || (*string) == '-')
	{
		string++;
	}
	if ((*string) == '\0')
	{
		return false;
	}
	while ((*string != '\0') && (*string >= '0') && (*string <= '9'))
	{
		string++;
	}
	if ((*string) == '\0')
	{
		return true;
	}
	else
	{
		if ((*string) == '.')
		{
			string++;
			while ((*string != '\0') && (*string >= '0') && (*string <= '9'))
			{
				string++;
			}
			if ((*string) == '\0')
			{
				return true;
			}
			else if ((*string) == 'e' || (*string) == 'E')
			{
				string++;
				if ((*string) == '+' || (*string) == '-')
				{
					string++;
				}
				if (*string == '\0')
				{
					return false;
				}
				while ((*string != '\0') && (*string >= '0') && (*string <= '9'))
				{
					string++;
				}
				if ((*string) == '\0')
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else if ((*string) == 'e' || (*string) == 'E')
		{
			string++;
			if ((*string) == '+' || (*string) == '-')
			{
				string++;
			}
			if (*string == '\0')
			{
				return false;
			}
			while ((*string != '\0') && (*string >= '0') && (*string <= '9'))
			{
				string++;
			}
			if ((*string) == '\0')
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}