//在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
//请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
//解题思路：从数组右上角开始，将target与其进行比较，相等则返回true
//若target较大，由于改行左边所有数小于当前比较的数，因此不可能等于target，比较该列下一行的数
//若target较小，由于该列下面所有数大于当前比较的数，因此不可能等于target，比较改行左边一列的数
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