//����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]������ʹ�ó�����
//����˼·�������������μ������0�ÿһ��˻��������������μ����ÿһ���n-1��˻���Ȼ����ʽ�ӵ���������˵õ����
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
vector<int> multiply(const vector<int>& A);
int main()
{
	vector<int> A = { 1, 2, 3, 4, 5 };
	vector<int> result = multiply(A);
	Display_1D_Matrix(A);
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
vector<int> multiply(const vector<int>& A) 
{
	vector<int> result;
	if (A.size() == 0)
	{
		return result;
	}
	vector<int> left;
	left.push_back(A[0]);
	for (int i = 1; i < A.size(); i++)
	{
		left.push_back(left[i - 1] * A[i]);
	}
	vector<int> right;
	right.push_back(A[A.size() - 1]);
	for (int i = A.size() - 2; i >= 0; i--)
	{
		right.push_back(right[A.size() - 2 - i] * A[i]);
	}
	result.push_back(right[right.size() - 2]);
	for (int i = 1; i < A.size() - 1; i++)
	{
		result.push_back(left[i - 1] * right[A.size() - 2 - i]);
	}
	result.push_back(left[left.size() - 2]);
	return result;
}