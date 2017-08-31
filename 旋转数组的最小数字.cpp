//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
//��������{ 3, 4, 5, 1, 2 }Ϊ{ 1, 2, 3, 4, 5 }��һ����ת�����������СֵΪ1��
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
//����˼·���������������޷��ж�ʱ˳������
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