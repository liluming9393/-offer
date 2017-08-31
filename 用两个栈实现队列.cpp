//������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�
//����˼·��ÿ����Ӷ�ѹ��ջ1������ʱ�����ж�ջ2�Ƿ���Ԫ�أ�����ֱ�Ӵ�ջ2���ӣ���û����ջ1������Ԫ�ص������ջ2����ջ2��ջ������
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
class Solution
{
public:
	void push(int node) {
		stack1.push(node);
	}

	int pop() {
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int data = stack2.top();
		stack2.pop();
		return data;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
int main()
{
	Solution myqueue;
	myqueue.push(1);
	myqueue.push(2);
	int data;
	data = myqueue.pop();
	cout << data << endl;
	myqueue.push(3);
	data = myqueue.pop();
	cout << data << endl;
	data = myqueue.pop();
	cout << data << endl;
	system("pause");
	return 0;
}