//定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。
//解题思路：定义一个普通栈存储所有元素，定义一个最小值栈，存储栈中最小值元素
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