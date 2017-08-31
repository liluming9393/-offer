//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣�
//���磬����������¾��� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
//����˼·�����Ǳ߽���������ѭ����ӡ
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
		//��ӡ����һ��
		for (int i = start; i <= (cols - 1 - start); i++)
		{
			result.push_back(matrix[start][i]);
		}
		//��ӡ����һ��
		if ((rows - 1 - start) > start)
		{
			for (int i = start + 1; i <= (rows - 1 - start); i++)
			{
				result.push_back(matrix[i][cols - 1 - start]);
			}
		}
		//��ӡ����һ��
		if ((cols - 1 - start) > start && (rows - 1 - start) > start)
		{
			for (int i = (cols - 1 - start - 1); i >= start; i--)
			{
				result.push_back(matrix[rows - 1 - start][i]);
			}
		}
		//��ӡ����һ��
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