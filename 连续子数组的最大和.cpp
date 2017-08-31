//HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:
//在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
//但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
//例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。你会不会被他忽悠住？(子向量的长度至少是1)
//解题思路：迭代计算以第i项为结尾的最大和，若该和为负数则下一项的最大和为其本身，否则下一项的最大和为前一项最大和加上其本身，每一项结尾的最大和进行比较的出总的最大和
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
int FindGreatestSumOfSubArray(vector<int> array);
int main()
{
	vector<int> array = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int result = FindGreatestSumOfSubArray(array);
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
int FindGreatestSumOfSubArray(vector<int> array) 
{
	if (array.size() == 0)
	{
		return 0;
	}
	int result = array[0];
	int temp = array[0];
	for (int i = 1; i < array.size(); i++)
	{
		if (temp <= 0)
		{
			temp = array[i];
		}
		else
		{
			temp = temp + array[i];
		}
		if (temp > result)
		{
			result = temp;
		}
	}
	return result;
}