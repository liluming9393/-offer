//�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����һ�����ӿ�ʼ��
//ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ����һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� 
//���� a b c e s f c s a d e e �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·����
//��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�
//����˼·���Ծ����ÿһ��Ϊ�������������ֱ������ܽ���ǰ��
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
