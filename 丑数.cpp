//把只包含因子2、3和5的数称作丑数（Ugly Number）。
//例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
//解题思路：解法一，逐个判断一个数是不是丑数，记录已找到的丑数的个数，判断方法不断除以2、3、5看剩下的因子是否包含别的
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
int GetUglyNumber_Solution(int index);
bool isUgly(int num);
int main()
{
	int index = 10;
	int result = GetUglyNumber_Solution(index);
	cout << result << endl;
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
bool isUgly(int num)
{
	while (num % 2 == 0)
	{
		num /= 2;
	}
	while (num % 3 == 0)
	{
		num /= 3;
	}
	while (num % 5 == 0)
	{
		num /= 5;
	}
	return (num == 1) ? true : false;
}
int GetUglyNumber_Solution(int index)
{
	/*if (index <= 0)
	{
		return 0;
	}
	int count = 0;
	int num = 0;
	while (count < index)
	{
		num++;
		if (isUgly(num))
		{
			count++;
		}
	}
	return num;*/
	if (index <= 0)
	{
		return 0;
	}
	queue<int> q2;
	queue<int> q3;
	queue<int> q5;
	int num = 1;
	int count = 1;
	q2.push(num * 2);
	q3.push(num * 3);
	q5.push(num * 5);
	while (count < index)
	{
		if (q2.front() <= q3.front() && q2.front() <= q5.front())
		{
			num = q2.front();
			q2.pop();
			q2.push(num * 2);
			q3.push(num * 3);
			q5.push(num * 5);
		}
		else if (q3.front() <= q2.front() && q3.front() <= q5.front())
		{
			num = q3.front();
			q3.pop();
			q3.push(num * 3);
			q5.push(num * 5);
		}
		else if (q5.front() <= q2.front() && q5.front() <= q3.front())
		{
			num = q5.front();
			q5.pop();
			q5.push(num * 5);
		}
		count++;
	}
	return num;
}