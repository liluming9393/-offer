//ţ���������һ����Ա��Fish��ÿ���糿���ǻ�����һ��Ӣ����־��дЩ�����ڱ����ϡ�ͬ��Cat��Fishд�������ĸ���Ȥ��
//��һ������Fish������������ȴ������������˼�����磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ�
//��ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô��
//����˼·��ԭ�ط�ת�����Ƚ������ַ�����ת��Ȼ���ÿ���Ӵ���ת
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