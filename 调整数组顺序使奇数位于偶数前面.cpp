//����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ��λ������ĺ�벿�֣�
//����֤������������ż����ż��֮������λ�ò��䡣
//����˼·�����������ռ佫������ż���ֱ�洢��Ȼ�󸲸�ԭ����
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
void reOrderArray(vector<int> &array);
int main()
{
	vector<int> array = { 2, 3, 5, 6, 1, 4 };
	Display_1D_Matrix(array);
	reOrderArray(array);
	Display_1D_Matrix(array);
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
void reOrderArray(vector<int> &array) 
{
	if (array.size() == 0)
	{
		return;
	}
	vector<int> odd;
	vector<int> even;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 == 1)
		{
			odd.push_back(array[i]);
		}
		else
		{
			even.push_back(array[i]);
		}
	}
	for (int i = 0; i < odd.size();i++)
	{
		array[i] = odd[i];
	}
	for (int i = 0; i < even.size(); i++)
	{
		array[i + odd.size()] = even[i];
	}
}