//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。 
//输入描述:输入一个字符串, 长度不超过9(可能有字符重复), 字符只包括大小写字母。
//解题思路：对所有字符进行全排列，通过不断交换确定每个位置字符，使用set进行去重
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
vector<string> Permutation(string str);
void myPermutation(set<string> &s, string str, int i);
int main()
{
	string str = "aba";
	cout << str << endl;
	vector<string> result = Permutation(str);
	if (result.size() != 0)
	{
		for (int i = 0; i < result.size() - 1; i++)
		{
			cout << result[i] << " ";
		}
		cout << result[result.size() - 1] << endl;
	}
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
void myPermutation(set<string> &s, string str, int i)
{
	if (i == str.size() - 1)
	{
		s.insert(str);
		return;
	}
	for (int k = i; k < str.size(); k++)
	{
		swap(str[k], str[i]);
		myPermutation(s, str, i + 1);
		swap(str[k], str[i]);
	}
}
vector<string> Permutation(string str) 
{
	vector<string> result;
	if (str.size() == 0)
	{
		return result;
	}
	set<string> s;
	myPermutation(s, str, 0);
	set<string>::iterator it;
	it = s.begin();
	while (it != s.end())
	{
		result.push_back(*it);
		it++;
	}
	return result;
}