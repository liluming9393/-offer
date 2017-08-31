//每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。
//其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
//每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,
//继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
//请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
//解题思路：使用list进行删除计算，直到剩余一个人
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
#include<list>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
int LastRemaining_Solution(int n, int m);
int main()
{
	int n = 10;
	int m = 2;
	int result = LastRemaining_Solution(n, m);
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
int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}
	list<int> num;
	for (int i = 0; i < n; i++)
	{
		num.push_back(i);
	}
	list<int>::iterator it;
	it = num.begin();
	while (num.size() > 1)
	{
		for (int i = 1; i < m; i++)
		{
			it++;
			if (it == num.end())
			{
				it = num.begin();
			}
		}
		list<int>::iterator temp;
		temp = ++it;
		if (temp == num.end())
		{
			temp = num.begin();
		}
		it--;
		num.erase(it);
		it = temp;
	}
	return (*it);
}