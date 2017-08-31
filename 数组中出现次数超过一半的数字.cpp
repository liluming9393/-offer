//数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
//例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
//解题思路：解法一使用partition函数知道partition的数处于中间位置，然后遍历数组验证该数是否为超过一半的数
//解法二使用一个候选数一个次数进行记录，每次从数组中删去两个不同的数，最后剩下的数是唯一可能的结果，遍历数组验证
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
int MoreThanHalfNum_Solution(vector<int> numbers);
int main()
{
	vector<int> numbers = { 1, 3, 2, 1, 1, 5, 1, 4 };
	int result = MoreThanHalfNum_Solution(numbers);
	cout << result << endl;
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
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.size() == 0)
	{
		return 0;
	}
	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < numbers.size(); i++)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else
		{
			if (numbers[i] == result)
			{
				times++;
			}
			else
			{
				times--;
			}
		}
	}
	int count = 0;
	if (times == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			if (result == numbers[i])
			{
				count++;
			}
		}
	}
	if (count <= numbers.size() / 2)
	{
		return 0;
	}
	return result;
}