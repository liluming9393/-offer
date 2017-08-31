//��һ������Ϊn����������������ֶ���0��n - 1�ķ�Χ�ڡ� ������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�Ҳ��֪��ÿ�������ظ����Ρ�
//���ҳ�����������һ���ظ������֡� ���磬������볤��Ϊ7������{ 2, 3, 1, 0, 2, 5, 3 }����ô��Ӧ��������ظ�������2����3��
//����˼·:1���������������Ȼ��ɨ���������飬ʱ�临�Ӷ�O(nlogn),�ռ临�Ӷ�O(1)
//2��ʹ��set��ÿ�������д洢��ɨ����������ֱ�����ظ���ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
//3����ÿ�����ַ��õ����Ӧ˳���λ�ã�����Ҫ��������������ͬ��Ϊ�ظ����֣�ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(1)
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
bool duplicate(int numbers[], int length, int* duplication);
int main()
{
	int numbers[] = { 2, 2, 6, 3, 3, 1, 0 };
	//int numbers[] = { 2, 5, 6, 4, 3, 1, 0 };
	int length = 7;
	int duplication = 0;
	bool result = duplicate(numbers, length, &duplication);
	if (result == false)
	{
		cout << "false" << endl;
	}
	else if (result == true)
	{
		cout << "true:" << duplication << endl;
	}
	system("pause");
	return 0;
}
void Display_1D_Matrix(vector<int> & data)
{
	for (int i = 0; i < data.size() - 1; i++)
	{
		cout << data[i] << " ";
	}
	cout << data[data.size() - 1] << endl;
}
void Display_2D_Matrix(vector<vector<int>> & data)
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size() - 1; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << data[i][data[i].size() - 1] << endl;
	}
}
bool duplicate(int numbers[], int length, int* duplication) 
{
	//�ⷨ1
	/*vector<int> num;
	for (int i = 0; i < length; i++)
	{
		num.push_back(numbers[i]);
	}
	sort(num.begin(), num.end());
	for (int i = 0; i < length - 1; i++)
	{
		if (num[i] == num[i + 1])
		{
			*duplication = num[i];
			return true;
		}
	}
	return false;*/
	//�ⷨ2
	/*if (length == 0)
	{
		return false;
	}
	set<int> num;
	num.insert(numbers[0]);
	for (int i = 1; i < length; i++)
	{
		int set_size = num.size();
		num.insert(numbers[i]);
		if (set_size == num.size())
		{
			*duplication = numbers[i];
			return true;
		}
	}
	return false;*/
	//�ⷨ3
	if (numbers == NULL || length <= 0)
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] < 0 || numbers[i] >= length)
		{
			return false;
		}
	}
	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			swap(numbers[i], numbers[numbers[i]]);
		}
	}
	return false;
}