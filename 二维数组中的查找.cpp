//��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
//����˼·�����������Ͻǿ�ʼ����target������бȽϣ�����򷵻�true
//��target�ϴ����ڸ������������С�ڵ�ǰ�Ƚϵ�������˲����ܵ���target���Ƚϸ�����һ�е���
//��target��С�����ڸ����������������ڵ�ǰ�Ƚϵ�������˲����ܵ���target���Ƚϸ������һ�е���
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std; 
bool Find1(int target, vector<vector<int>> array);
int main()
{
	bool result;
	int target;
	int data[4][4] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	vector<vector<int>> array(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			array[i].push_back(data[i][j]);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	cin >> target;
	cout << "target=" << target << endl;
	result = Find1(target, array);
	if (result == true)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}
bool Find1(int target, vector<vector<int>> array) 
{
	int height = array.size();
	if (height == 0)
	{
		return false;
	}
	int width = array[0].size();
	int i = 0;
	int j = width - 1;
	while (i < height && j >= 0)
	{
		if (array[i][j] == target)
		{
			return true;
		}
		else if (array[i][j] > target)
		{
			j--;
			continue;
		}
		else if (array[i][j] < target)
		{
			i++;
			continue;
		}
	}
	return false;
}