//С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
//���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22��
//���ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck! 
//�������:������к�ΪS�������������С������ڰ��մ�С�����˳�����м䰴�տ�ʼ���ִ�С�����˳��
//����˼·��ʹ����������ʾ���е�ͷβ������������еĺͣ���С��sum��β�����ң�������sum��ͷ�����ң��������������ֱ���͵�һ��Ϊֹ
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
vector<vector<int> > FindContinuousSequence(int sum);
int main()
{
	int sum = 100;
	vector<vector<int>> result = FindContinuousSequence(sum);
	Display_2D_Matrix(result);
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
vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int>> result;
	if (sum < 3)
	{
		return result;
	}
	int left = 1;
	int right = 2;
	int temp = 3;
	while (left < ((sum + 1) / 2))
	{
		if (temp == sum)
		{
			int count = result.size();
			result.resize(count + 1);
			for (int i = left; i <= right; i++)
			{
				result[count].push_back(i);
			}
			temp -= left;
			left++;
		}
		else if (temp < sum)
		{
			right++;
			temp += right;
		}
		else if (temp > sum)
		{
			temp -= left;
			left++;
			
		}
	}
	return result;
}