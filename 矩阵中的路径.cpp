//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
//每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。 
//例如 a b c e s f c s a d e e 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，
//因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
//解题思路：以矩阵的每一格为起点进行搜索，分别向四周进行前进
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
bool hasPath(char* matrix, int rows, int cols, char* str);
bool myhasPath(char *matrix, int rows, int cols, int row, int col, char *str, vector<int> visited);
int main()
{
	char matrix[] = "abcesfcsadee";
	int rows = 3;
	int cols = 4;
	char str[] = "abccse";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i*cols + j] << " ";
		}
		cout << endl;
	}
	cout << str << endl;
	bool result = hasPath(matrix, rows, cols, str);
	if (result)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
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
bool myhasPath(char *matrix, int rows, int cols, int row, int col, char *str, vector<int> visited)
{
	if ((*str) == '\0')
	{
		return true;
	}
	if (row >= 0 && row < rows && col >= 0 && col < cols)
	{
		if (visited[row*cols + col] == 0 && matrix[row*cols + col] == (*str))
		{
			visited[row*cols + col] = 1;
			str++;
			if (myhasPath(matrix, rows, cols, row + 1, col, str, visited))
			{
				return true;
			}
			if (myhasPath(matrix, rows, cols, row - 1, col, str, visited))
			{
				return true;
			}
			if (myhasPath(matrix, rows, cols, row, col + 1, str, visited))
			{
				return true;
			}
			if (myhasPath(matrix, rows, cols, row, col - 1, str, visited))
			{
				return true;
			}
		}
	}
	return false;
}
bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == NULL || rows <= 0 || cols <= 0 || str == NULL || (*str)=='\0')
	{
		return false;
	}
	vector<int> visited(rows*cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			visited.clear();
			visited.resize(rows*cols);
			if (myhasPath(matrix, rows, cols, i, j, str, visited))
			{
				return true;
			}
		}
	}
	return false;
}
