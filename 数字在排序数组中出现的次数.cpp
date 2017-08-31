//统计一个数字在排序数组中出现的次数。
//解题思路：使用二分搜索分别找出k出现的第一个位置和最后一个位置，复杂度O(logn)
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
int GetNumberOfK(vector<int> data, int k);
int GetFirstK(vector<int> data, int k);
int GetLastK(vector<int> data, int k);
int main()
{
	vector<int> data = { 1, 2, 3, 3, 3, 3, 4, 5 };
	Display_1D_Matrix(data);
	int k = 6;
	int result = GetNumberOfK(data, k);
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
int GetFirstK(vector<int> data, int k)
{
	if (data.size() == 0)
	{
		return -1;
	}
	if (data[0] == k)
	{
		return 0;
	}
	int start = 0;
	int end = data.size() - 1;
	while (start <= end)
	{
		int middle = (start + end) / 2;
		if (k == data[middle])
		{
			if (middle > 0 && data[middle - 1] != k)
			{
				return middle;
			}
			else
			{
				end = middle - 1;
			}
		}
		else if (k > data[middle])
		{
			start = middle + 1;
		}
		else if (k < data[middle])
		{
			end = middle - 1;
		}
	}
	return -1;
}
int GetLastK(vector<int> data, int k)
{
	if (data.size() == 0)
	{
		return -1;
	}
	if (data[data.size() - 1] == k)
	{
		return data.size() - 1;
	}
	int start = 0;
	int end = data.size() - 1;
	while (start <= end)
	{
		int middle = (start + end) / 2;
		if (k == data[middle])
		{
			if (middle < (data.size() - 1) && data[middle + 1] != k)
			{
				return middle;
			}
			else
			{
				start = middle + 1;
			}
		}
		else if (k > data[middle])
		{
			start = middle + 1;
		}
		else if (k < data[middle])
		{
			end = middle - 1;
		}
	}
	return -1;
}
int GetNumberOfK(vector<int> data, int k) 
{
	if (data.size() == 0)
	{
		return 0;
	}
	int first = GetFirstK(data, k);
	int last = GetLastK(data, k);
	int result = 0;
	if (first != -1 && last != -1)
	{
		result = last - first + 1;
	}
	return result;
}