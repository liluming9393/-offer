//һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�
//����˼·�����������ֽ�����򣬽��Ϊ�����������ֵ���������ҳ�bitΪ1������һλ�����������ְ���һλ��Ϊ���飬��bitΪ1��0��ÿ�������������Ϊ���
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
void FindNumsAppearOnce(vector<int> data, int* num1, int *num2);
int main()
{
	vector<int> data = { 2, 4, 5, 6, 5, 4, 14, 2 };
	int num1 = 0;
	int num2 = 0;
	Display_1D_Matrix(data);
	FindNumsAppearOnce(data, &num1, &num2);
	cout << num1 << " " << num2 << endl;
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
void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) 
{
	if (data.size() < 2)
	{
		return;
	}
	int temp = 0;
	for (int i = 0; i < data.size(); i++)
	{
		temp = temp^data[i];
	}
	int flag = 1;
	for (int i = 0; i < 32;i++)
	{
		if ((temp & flag) == flag)
		{
			break;
		}
		flag = flag << 1;
	}
	(*num1) = 0;
	(*num2) = 0;
	for (int i = 0; i < data.size(); i++)
	{
		if ((data[i] & flag) == flag)
		{
			(*num1) ^= data[i];
		}
		else
		{
			(*num2) ^= data[i];
		}
	}
}