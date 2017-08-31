//�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ������,�����������е�����Ե�����P��
//����P��1000000007ȡģ�Ľ������� �����P%1000000007 
/*��������:��Ŀ��֤�����������û�е���ͬ������
���ݷ�Χ��
���� % 50������, size <= 10 ^ 4
���� % 75������, size <= 10 ^ 5
���� % 100������, size <= 2 * 10 ^ 5
�������� :1, 2, 3, 4, 5, 6, 7, 0
������� :7*/
//����˼·�����ù鲢�����ںϲ������м�������Ը���
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
int InversePairs(vector<int> data);
void MergeSort(vector<int> &data, vector<int> &temp, long long int left, long long int right, long long int &result);
void Merge(vector<int>&data, vector<int>&temp, long long int l, long long int m, long long int r, long long int &result);
int main()
{
	//vector<int> data = { 7, 5, 6, 4, 3 };
	vector<int> data = { 1, 2, 3, 4, 5, 6, 7, 0 };
	Display_1D_Matrix(data);
	int result = InversePairs(data);
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
int InversePairs(vector<int> data) 
{
	long long int result = 0;
	if (data.size() <= 1)
	{
		return 0;
	}
	vector<int> temp = data;
	MergeSort(data, temp, 0, data.size() - 1, result);
	return result % 1000000007;
}
void MergeSort(vector<int> &data, vector<int> &temp, long long int left, long long int right, long long int &result)
{
	if (left < right)
	{
		long long int i = left + (right - left) / 2;
		MergeSort(temp, data, left, i, result);
		MergeSort(temp, data, i + 1, right, result);
		Merge(temp, data, left, i, right, result);
	}
}
void Merge(vector<int>&data, vector<int>&temp, long long int l, long long int m, long long int r, long long int &result)
{
	long long int i = m, j = r, k = r;
	while (i >= l && j >= (m + 1))
	{
		if (data[i] >= data[j])
		{
			temp[k] = data[i];
			k--;
			i--;
			result = result + (j - m);
		}
		else if (data[i] < data[j])
		{
			temp[k] = data[j];
			j--; 
			k--;
		}
	}
	if (i < l)
	{
		while (j >= (m + 1))
		{
			temp[k] = data[j];
			k--;
			j--;
		}
	}
	else
	{
		while (i >= l)
		{
			temp[k] = data[i];
			k--;
			i--;
		}
	}
}
