//请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
//当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。 
//输出描述:如果当前字符流没有存在出现一次的字符，返回#字符。
//解题思路：使用一个map记录每个字母的出现次数，找出出现次数为1的第一个字符即可
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
class Solution
{
public:
	//Insert one char from stringstream
	void Insert(char ch)
	{
		str += ch;
		map<char, int>::iterator it;
		it = m.find(ch);
		if (it == m.end())
		{
			m.insert(pair<char, int>(ch, 1));
		}
		else
		{
			it->second++;
		}
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		map<char, int>::iterator it;
		for (int i = 0; i < str.size(); i++)
		{
			it = m.find(str[i]);
			if (it->second == 1)
			{
				return str[i];
			}
		}
		return '#';
	}
private:
	string str;
	map<char, int> m;
};
int main()
{
	Solution s;
	char ch;
	while (cin >> ch)
	{
		s.Insert(ch);
		char result = s.FirstAppearingOnce();
		cout << result << endl;
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
