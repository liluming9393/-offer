//������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
//���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
//���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�
//����˼·��ʹ�þ������Ѿ��������ĸ��ӣ�Ȼ����������û���������ĸ���
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
int movingCount(int threshold, int rows, int cols);
void mymovingCount(int threshold, int rows, int cols, int row, int col, vector<vector<int>> &visited, int &result);
bool check(int threshold, int rows, int cols, int row, int col, vector<vector<int>> &visited);
int main()
{
	int threshold = 12;
	int rows = 20; int cols = 20;
	int result = movingCount(threshold, rows, cols);
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
void mymovingCount(int threshold, int rows, int cols, int row, int col, vector<vector<int>> &visited, int &result)
{
	
	if (check(threshold, rows, cols, row, col, visited))
	{
		result++;
		mymovingCount(threshold, rows, cols, row + 1, col, visited, result);
		mymovingCount(threshold, rows, cols, row, col + 1 , visited, result);
		mymovingCount(threshold, rows, cols, row - 1, col, visited, result);
		mymovingCount(threshold, rows, cols, row, col - 1, visited, result);
	}
}
bool check(int threshold, int rows, int cols, int row, int col, vector<vector<int>> &visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols && visited[row][col] == 0)
	{
		visited[row][col] = 1;
		int temp = 0;
		while (row != 0)
		{
			temp = temp + row % 10;
			row = row / 10;
		}
		while (col != 0)
		{
			temp = temp + col % 10;
			col = col / 10;
		}
		if (temp <= threshold)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}
int movingCount(int threshold, int rows, int cols)
{
	if (rows <= 0 || cols <= 0 || threshold < 0)
	{
		return 0;
	}
	vector<vector<int>> visited(rows);
	for (int i = 0; i < visited.size(); i++)
	{
		visited[i].resize(cols);
	}
	int result = 0;
	mymovingCount(threshold, rows, cols, 0, 0, visited, result);
	return result;
}