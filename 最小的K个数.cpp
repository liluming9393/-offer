//输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
//解题思路：利用k大小的multiset，放入k个数，接下来若扫描到的数小于k个数最大值则替换，最终留下的k个数即为最小
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