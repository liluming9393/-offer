//用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
//解题思路：每次入队都压入栈1，出队时首先判断栈2是否有元素，若有直接从栈2出队，若没有则将栈1的所有元素倒序放入栈2，从栈2的栈顶出队
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