//输入一个链表，从尾到头打印链表每个节点的值。
//解题思路：将链表从头到尾压入栈中，出栈顺序即为倒序
//没有头结点
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
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* CreateList(vector<int> &data);
void DispList(ListNode* head);
vector<int> printListFromTailToHead(ListNode* head);
int main()
{
	vector<int> data = { 1, 2, 3, 4, 5 };
	ListNode* head = CreateList(data);
	DispList(head);
	vector<int> result;
	result = printListFromTailToHead(head);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
ListNode* CreateList(vector<int> &data)
{
	ListNode *head = new ListNode(data[0]);
	ListNode *p = head;
	for (int i = 1; i < data.size(); i++)
	{
		ListNode *temp = new ListNode(data[i]);
		p->next = temp;
		p = p->next;
	}
	p->next = NULL;
	return head;
}
void DispList(ListNode* head)
{
	ListNode *p = head;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
vector<int> printListFromTailToHead(ListNode* head) 
{
	vector<int> result;
	stack<int> data;
	while (head != NULL)
	{
		data.push(head->val);
		head = head->next;
	}
	while (!data.empty())
	{
		result.push_back(data.top());
		data.pop();
	}
	return result;
}