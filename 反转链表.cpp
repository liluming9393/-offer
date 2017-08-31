//输入一个链表，反转链表后，输出链表的所有元素。
//解题思路：使用多个指针迭代改变链表指向
//没有头结点
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode* CreateList(vector<int> &data);
void DispList(ListNode* head);
ListNode* ReverseList(ListNode* pHead);
int main()
{
	vector<int> data = { 1, 2, 3, 4 };
	ListNode* head = CreateList(data);
	DispList(head);
	ListNode *result = ReverseList(head);
	DispList(result);
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
ListNode* ReverseList(ListNode* pHead) 
{
	if (pHead == NULL || pHead->next == NULL)
	{
		return pHead;
	}
	ListNode *temp1 = pHead;
	ListNode *temp2 = pHead->next;
	ListNode *temp3 = pHead->next->next;
	temp1->next = NULL;
	while (temp3 != NULL)
	{
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = temp3;
		temp3 = temp3->next;
	}
	temp2->next = temp1;
	return temp2;
}