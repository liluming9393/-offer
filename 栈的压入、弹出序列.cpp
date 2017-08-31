//���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ�
//��������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
//��ע�⣺���������еĳ�������ȵģ�
//����˼·�����Ͻ�����ջֱ��������ջ���е�һ������Ȼ���ж�ջ��Ԫ���Ƿ�Ϊ��ջ���еڶ������������ջ�������򽫺������������ջֱ�������������Դ�����
//������������ջ��û����������������в���һ����Ӧ�ĵ�������
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
bool IsPopOrder(vector<int> pushV, vector<int> popV);
int main()
{
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV = { 5, 4, 3, 2, 1 };
	bool result = IsPopOrder(pushV, popV);
	if (result == true)
	{
		cout << "true" << endl;
	}
	else if (result == false)
	{
		cout << "false" << endl;
	}
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
bool IsPopOrder(vector<int> pushV, vector<int> popV) 
{
	if (pushV.size() == 0)
	{
		return true;
	}
	stack<int> temp;
	int flag = 0;
	for (int i = 0; i < popV.size(); i++)
	{
		if (!temp.empty())
		{
			if (temp.top() == popV[i])
			{
				temp.pop();
			}
			else
			{
				while (temp.top() != popV[i] && flag != pushV.size())
				{
					temp.push(pushV[flag]);
					flag++;
				}
				if (temp.top() != popV[i] && flag == pushV.size())
				{
					return false;
				}
				else
				{
					temp.pop();
				}
			}
		}
		else
		{
			while (pushV[flag] != popV[i] && flag!=pushV.size())
			{
				temp.push(pushV[flag]);
				flag++;
			}
			if (flag == pushV.size())
			{
				return false;
			}
			else
			{
				flag++;
			}
		}
	}
	return true;
}