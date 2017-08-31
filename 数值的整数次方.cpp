//给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
//解题思路：分类讨论指数为正数、零、负数情况
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
double Power(double base, int exponent);
double Power_unsigned(double base, unsigned int exponent);
int main()
{
	double base = 0.5;
	int exponent = -2;
	cout << base << endl;
	cout << exponent << endl;
	double result = Power(base, exponent);
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
double Power_unsigned(double base, unsigned int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	if (exponent == 1)
	{
		return base;
	}
	double result = Power_unsigned(base, exponent >> 1);
	result = result * result;
	if (exponent & 1 == 1)
	{
		result = result*base;
	}
	return result;
}
double Power(double base, int exponent) 
{
	if (base < 0.0000001 && base > -0.0000001 && exponent < 0)
	{
		return 0;
	}
	double result;
	int absexp = exponent;
	if (exponent == 0)
	{
		return 1;
	}
	if (exponent < 0)
	{
		absexp = -exponent;
	}
	result = Power_unsigned(base, absexp);
	if (exponent < 0)
	{
		result = 1 / result;
	}
	return result;
}