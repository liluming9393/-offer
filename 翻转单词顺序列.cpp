//牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，
//有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
//正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
//解题思路：原地翻转，首先将整个字符串翻转，然后对每个子串翻转
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
string ReverseSentence(string str);
int main()
{
	string str = "i am a student.";
	cout << str << endl;
	string result = ReverseSentence(str);
	cout << result;
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
string ReverseSentence(string str) 
{
	if (str.size() == 0)
	{
		return str;
	}
	reverse(str.begin(), str.end());
	int left = 0;
	int right = 0;
	while (right < str.size())
	{
		while (str[right] != ' ' && right < str.size())
		{
			right++;
		}
		reverse(str.begin() + left, str.begin() + right);
		left = right + 1;
		right = right + 1;
	}
	return str;
}