//����һ����������������һ������S���������в������������ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ� 
//�������:��Ӧÿ�����԰����������������С���������
//����˼·��ʹ������ָ��ָ���һ���������һ����������֮�ͣ���С��sum�����ָ�������ƶ���������sum���ұ�ָ�������ƶ�
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
vector<int> FindNumbersWithSum(vector<int> array, int sum);
int main()
{
	vector<int> array = { 1, 2, 6, 7, 11, 15 };
	int sum = 8;
	vector<int> result = FindNumbersWithSum(array, sum);
	Display_1D_Matrix(result);
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
vector<int> FindNumbersWithSum(vector<int> array, int sum) 
{
	vector<int> result;
	if (array.size() == 0)
	{
		return result;
	}
	int left = 0;
	int right = array.size() - 1;
	int multiply = 0;
	bool first_flag = false;
	while (left < right)
	{
		if ((array[left] + array[right]) == sum)
		{
			if (first_flag == false)
			{
				multiply = array[left] * array[right];
				result.push_back(array[left]);
				result.push_back(array[right]);
				first_flag = true;
			}
			else
			{
				if ((array[left] * array[right]) < multiply)
				{
					multiply = array[left] * array[right];
					result.clear();
					result.push_back(array[left]);
					result.push_back(array[right]);
				}
			}
			left++;
		}
		else if ((array[left] + array[right]) < sum)
		{
			left++;
		}
		else if ((array[left] + array[right]) > sum)
		{
			right--;
		}
	}
	return result;
}