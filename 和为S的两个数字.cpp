//输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。 
//输出描述:对应每个测试案例，输出两个数，小的先输出。
//解题思路：使用两个指针指向第一个数和最后一个数，求其之和，若小于sum则左边指针向右移动，若大于sum则右边指针向左移动
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
vector<int> FindNumbersWithSum(vector<int> array, int sum);
int main()
{
	vector<int> array = { 1, 2, 6, 7, 11, 15 };
	int sum = 8;
	vector<int> result = FindNumbersWithSum(array, sum);
	Display_1D_Matrix(result);
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
vector<int> FindNumbersWithSum(vector<int> array, int sum) 
{
	vector<int> result;
	if (array.size() == 0)
	{
		return result;
	}
	int left = 0;
	int right = array.size() - 1;
	int multiply = 0;
	bool first_flag = false;
	while (left < right)
	{
		if ((array[left] + array[right]) == sum)
		{
			if (first_flag == false)
			{
				multiply = array[left] * array[right];
				result.push_back(array[left]);
				result.push_back(array[right]);
				first_flag = true;
			}
			else
			{
				if ((array[left] * array[right]) < multiply)
				{
					multiply = array[left] * array[right];
					result.clear();
					result.push_back(array[left]);
					result.push_back(array[right]);
				}
			}
			left++;
		}
		else if ((array[left] + array[right]) < sum)
		{
			left++;
		}
		else if ((array[left] + array[right]) > sum)
		{
			right--;
		}
	}
	return result;
}