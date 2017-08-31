//给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
//解题思路：从左往右依次计算出第0项到每一项乘积，从右往左依次计算出每一项到第n-1项乘积，然后按照式子的两部分相乘得到结果
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