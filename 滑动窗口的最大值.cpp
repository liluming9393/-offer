//����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ�����磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3����ôһ������6���������ڣ�
//���ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}�� �������{2,3,4,2,6,2,5,1}�Ļ�������������6���� 
//{[2,3,4],2,6,2,5,1}�� {2,[3,4,2],6,2,5,1}�� {2,3,[4,2,6],2,5,1}�� {2,3,4,[2,6,2],5,1}�� {2,3,4,2,[6,2,5],1}�� {2,3,4,2,6,[2,5,1]}��
//����˼·������һ���ܹ�ֱ��ȡ�����ֵ�Ķ��У���k����������У�ÿ�γ���һ�������һ����ֱ�ӻ�ȡ���ֵ
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
vector<int> maxInWindows(const vector<int>& num, unsigned int size);
int main()
{
	vector<int> num = { 2, 3, 4, 4, 4, 2, 5, 8 };
	unsigned int size = 3;
	Display_1D_Matrix(num);
	vector<int> result = maxInWindows(num, size);
	Display_1D_Matrix(result);
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
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> result;
	if (num.size() == 0 || size <= 0 || num.size() < size)
	{
		return result;
	}
	deque<int> max;
	for (int i = 0; i < size; i++)
	{
		while (!max.empty() && num[i] > max.back())
		{
			max.pop_back();
		}
		max.push_back(num[i]);
	}
	for (int i = size; i < num.size(); i++)
	{
		result.push_back(max.front());
		if (num[i - size] == max.front())
		{
			max.pop_front();
		}
		while (!max.empty() && num[i] > max.back())
		{
			max.pop_back();
		}
		max.push_back(num[i]);
	}
	result.push_back(max.front());
	return result;
}