//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
//例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
//解题思路：考虑边界条件进行循环打印
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<stack>
using namespace std;
vector<int> printMatrix(vector<vector<int> > matrix);
int main()
{
	//vector<vector<int>> matrix = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	//vector<vector<int>> matrix = { { 1, 2, 3, 4 } };
	//vector<vector<int>> matrix = { { 1 }, { 2 }, { 3 } };
	//vector<vector<int>> matrix = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 } };
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	vector<int> result = printMatrix(matrix);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
vector<int> printMatrix(vector<vector<int> > matrix) 
{
	vector<int> result;
	if (matrix.size() == 0)
	{
		return result;
	}
	int start = 0;
	int rows = matrix.size();
	int cols = matrix[0].size();
	while (rows>start * 2 && cols > start * 2)
	{
		//打印上面一行
		for (int i = start; i <= (cols - 1 - start); i++)
		{
			result.push_back(matrix[start][i]);
		}
		//打印右面一列
		if ((rows - 1 - start) > start)
		{
			for (int i = start + 1; i <= (rows - 1 - start); i++)
			{
				result.push_back(matrix[i][cols - 1 - start]);
			}
		}
		//打印下面一行
		if ((cols - 1 - start) > start && (rows - 1 - start) > start)
		{
			for (int i = (cols - 1 - start - 1); i >= start; i--)
			{
				result.push_back(matrix[rows - 1 - start][i]);
			}
		}
		//打印左面一列
		if ((cols - 1 - start) > start && (rows - 1 - start) > (start + 1))
		{
			for (int i = (rows - 1 - start - 1); i >= (start + 1); i--)
			{
				result.push_back(matrix[i][start]);
			}
		}
		start++;
	}
	return result;
}