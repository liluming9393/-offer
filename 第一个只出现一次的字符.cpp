//在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)中找到第一个只出现一次的字符,并返回它的位置
//解题思路：建立一个256长度的数组记录每个字符出现的次数，再次扫描整个字符串判断出现次数是否为1即可
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
int FirstNotRepeatingChar(string str);
int main()
{
	string str = "ABABCDDE";
	int result = FirstNotRepeatingChar(str);
	cout << str << endl;
	cout << result << endl;
	if (result != -1)
	{
		cout << str[result] << endl;
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
int FirstNotRepeatingChar(string str)
{
	if (str.size() == 0)
	{
		return -1;
	}
	int count[256] = { 0 };
	for (int i = 0; i < str.size(); i++)
	{
		count[str[i]]++;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (count[str[i]] == 1)
		{
			return i;
		}
	}
	return -1;
}