//����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
//����˼·������k��С��multiset������k��������������ɨ�赽����С��k�������ֵ���滻���������µ�k������Ϊ��С
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
#include<functional>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
vector<int> GetLeastNumbers_Solution(vector<int> input, int k);
int main()
{
	vector<int> input = { 1, 1, 1, 6, 2, 7, 3, 8 };
	int k = 4;
	Display_1D_Matrix(input);
	vector<int> result = GetLeastNumbers_Solution(input, k);
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
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
{
	vector<int> result;
	if (input.size() < k || k < 1)
	{
		return result;
	}
	multiset<int, greater<int>> m;
	for (int i = 0; i < k; i++)
	{
		m.insert(input[i]);
	}
	multiset<int,greater<int>>::iterator it;
	for (int i = k; i < input.size(); i++)
	{
		it = m.begin();
		int max = *it;
		if (input[i] < max)
		{
			m.erase(it);
			m.insert(input[i]);
		}
	}
	it = m.begin();
	while (it != m.end())
	{
		result.push_back(*it);
		m.erase(it);
		it = m.begin();
	}
	return result;
}