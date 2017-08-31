//��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ������磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
//���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"�� 
//�������:�����ǰ�ַ���û�д��ڳ���һ�ε��ַ�������#�ַ���
//����˼·��ʹ��һ��map��¼ÿ����ĸ�ĳ��ִ������ҳ����ִ���Ϊ1�ĵ�һ���ַ�����
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
