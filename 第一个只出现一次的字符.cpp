//��һ���ַ���(1<=�ַ�������<=10000��ȫ���ɴ�д��ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
//����˼·������һ��256���ȵ������¼ÿ���ַ����ֵĴ������ٴ�ɨ�������ַ����жϳ��ִ����Ƿ�Ϊ1����
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