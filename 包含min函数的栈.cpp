//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������
//����˼·������һ����ͨջ�洢����Ԫ�أ�����һ����Сֵջ���洢ջ����СֵԪ��
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
	void push(int value) {
		data.push(value);
		if (!min_data.empty())
		{
			if (value <= min_data.top())
			{
				min_data.push(value);
			}
		}
		else
		{
			min_data.push(value);
		}
	}
	void pop() {
		if (!data.empty())
		{
			if (data.top() == min_data.top())
			{
				data.pop();
				min_data.pop();
			}
			else
			{
				data.pop();
			}
		}
	}
	int top() {
		if (!data.empty())
		{
			return data.top();
		}
		return 0;
	}
	int min() {
		if (!min_data.empty())
		{
			return min_data.top();
		}
		return 0;
	}
private:
	stack<int> data;
	stack<int> min_data;
};
int main()
{
	Solution s;
	s.push(1);
	s.push(4);
	s.push(0);
	int result;
	result = s.min();
	cout << result << endl;
	s.pop();
	result = s.min();
	cout << result << endl;
	s.pop();
	result = s.min();
	cout << result << endl;
	system("pause");
	return 0;
}