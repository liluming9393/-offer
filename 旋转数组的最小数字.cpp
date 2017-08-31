//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{ 3, 4, 5, 1, 2 }为{ 1, 2, 3, 4, 5 }的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
//解题思路：二分搜索，当无法判断时顺序搜索
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
int minNumberInRotateArray(vector<int> rotateArray);
int main()
{
	vector<int> rotateArray = { 1,1,2,1,1 };
	Display_1D_Matrix(rotateArray);
	int result = minNumberInRotateArray(rotateArray);
	cout << result << endl;
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
int minNumberInRotateArray(vector<int> rotateArray) 
{
	if (rotateArray.size() == 0)
	{
		return 0;
	}
	int left = 0;
	int right = rotateArray.size() - 1;
	int mid = left + (right - left) / 2;
	int result;
	while (rotateArray[left] >= rotateArray[right])
	{
		if (right - left == 1)
		{
			return rotateArray[right];
		}
		mid = left + (right - left) / 2;
		if (rotateArray[mid] == rotateArray[left] && rotateArray[mid] == rotateArray[right])
		{
			result = rotateArray[0];
			for (int i = 0; i < rotateArray.size(); i++)
			{
				if (rotateArray[i] < result)
				{
					result = rotateArray[i];
				}
			}
			return result;
		}
		else if (rotateArray[mid] >= rotateArray[left])
		{
			left = mid;
		}
		else if (rotateArray[mid] <= rotateArray[right])
		{
			right = mid;
		}
	}
	return rotateArray[left];
}