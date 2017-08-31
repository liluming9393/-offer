//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��������������Yes,�������No���������������������������ֶ�������ͬ��
//����˼·���������һ���ڵ�Ϊ���ڵ㣬������ͷ���ҳ�����С�ڸ��ڵ����Ϊ����������㣬�ж�ʣ�����Ƿ񶼱ȸ��ڵ�󣬵ݹ�ֱ��ж����������Ƿ�Ϊ����������
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
bool VerifySquenceOfBST(vector<int> sequence);
int main()
{
	vector<int> sequence = { 5, 7, 6, 9, 11, 10, 8 };
	Display_1D_Matrix(sequence);
	bool result = VerifySquenceOfBST(sequence);
	if (result == true)
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
bool VerifySquenceOfBST(vector<int> sequence) 
{
	if (sequence.size() == 0)
	{
		return false;
	}
	int root = sequence[sequence.size() - 1];
	int i = 0;
	for (i = 0; i < sequence.size() - 1; i++)
	{
		if (sequence[i]>root)
		{
			break;
		}
	}
	vector<int> left;
	for (int k = 0; k < i; k++)
	{
		left.push_back(sequence[k]);
	}
	for (int j = i; j < sequence.size() - 1; j++)
	{
		if (sequence[j] < root)
		{
			return false;
		}
	}
	vector<int> right;
	for (int k = i; k < sequence.size() - 1; k++)
	{
		right.push_back(sequence[k]);
	}
	bool left_flag = true;
	if (left.size() != 0)
	{
		left_flag = VerifySquenceOfBST(left);
	}
	bool right_flag = true;
	if (right.size() != 0)
	{
		right_flag = VerifySquenceOfBST(right);
	}
	return left_flag && right_flag;
}