//�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ���������������һ���������ַ�����S���������ѭ������Kλ������������
//���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨����
//����˼·��ԭ����ת�����Ӵ�1-n��n-length���е��ã��������ַ�������
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
string LeftRotateString(string str, int n);
int main()
{
	string str = "abcdefg";
	cout << str << endl;
	int n = 3;
	string result = LeftRotateString(str, n);
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
string LeftRotateString(string str, int n) 
{
	if (str.size() == 0 || str.size() < n)
	{
		return "";
	}
	reverse(str.begin(),str.begin()+n);
	reverse(str.begin() + n, str.end());
	reverse(str.begin(), str.end());
	return str;
}