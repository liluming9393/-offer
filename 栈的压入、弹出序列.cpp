//输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。
//例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
//（注意：这两个序列的长度是相等的）
//解题思路：不断将数入栈直到遇到出栈序列第一个数，然后判断栈顶元素是否为出栈序列第二个数，是则出栈，不是则将后面的数继续入栈直到遇到该数，以此类推
//若所有数都入栈仍没有遇到该数则该序列不是一个对应的弹出序列
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