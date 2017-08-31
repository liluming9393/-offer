//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
//��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��
//����˼·���ⷨһʹ��partition����֪��partition���������м�λ�ã�Ȼ�����������֤�����Ƿ�Ϊ����һ�����
//�ⷨ��ʹ��һ����ѡ��һ���������м�¼��ÿ�δ�������ɾȥ������ͬ���������ʣ�µ�����Ψһ���ܵĽ��������������֤
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
int MoreThanHalfNum_Solution(vector<int> numbers);
int main()
{
	vector<int> numbers = { 1, 3, 2, 1, 1, 5, 1, 4 };
	int result = MoreThanHalfNum_Solution(numbers);
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
int MoreThanHalfNum_Solution(vector<int> numbers)
{
	if (numbers.size() == 0)
	{
		return 0;
	}
	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < numbers.size(); i++)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		else
		{
			if (numbers[i] == result)
			{
				times++;
			}
			else
			{
				times--;
			}
		}
	}
	int count = 0;
	if (times == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < numbers.size(); i++)
		{
			if (result == numbers[i])
			{
				count++;
			}
		}
	}
	if (count <= numbers.size() / 2)
	{
		return 0;
	}
	return result;
}