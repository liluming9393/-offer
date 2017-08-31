//在一个长度为n的数组里的所有数字都在0到n - 1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
//请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{ 2, 3, 1, 0, 2, 5, 3 }，那么对应的输出是重复的数字2或者3。
//解题思路:1、对数组进行排序，然后扫描整个数组，时间复杂度O(nlogn),空间复杂度O(1)
//2、使用set对每个数进行存储，扫描整个数组直到有重复，时间复杂度O(n),空间复杂度O(n)
//3、将每个数字放置到其对应顺序的位置，若需要交换的两个数相同则为重复数字，时间复杂度O(n),空间复杂度O(1)
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
	//解法1
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
	//解法2
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
	//解法3
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