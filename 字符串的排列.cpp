//����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba�� 
//��������:����һ���ַ���, ���Ȳ�����9(�������ַ��ظ�), �ַ�ֻ������Сд��ĸ��
//����˼·���������ַ�����ȫ���У�ͨ�����Ͻ���ȷ��ÿ��λ���ַ���ʹ��set����ȥ��
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