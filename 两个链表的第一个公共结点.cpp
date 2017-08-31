//输入两个链表，找出它们的第一个公共结点。
//解题思路：计算两个链表长度，长的链表先走l1-l2步，两者同时向前走，第一个共同节点即为公共节点
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
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2);
int main()
{
	vector<int> data1 = { 5, 5, 3, 4, 5 };
	ListNode* head1 = CreateList(data1);
	DispList(head1);
	vector<int> data2 = { 1, 2 };
	ListNode *head2 = CreateList(data2);
	ListNode *p1 = head1;
	p1 = p1->next;
	p1 = p1->next;
	ListNode *p2 = head2;
	p2 = p2->next;
	p2->next = p1;
	DispList(head2);
	ListNode *result = FindFirstCommonNode(head1, head2);
	if (result == NULL)
	{
		cout << "no common node" << endl;
	}
	else
	{
		cout << result->val << endl;
	}
	system("pause");
	return 0;
}
ListNode* CreateList(vector<int> &data)
{
	if (data.size() == 0)
	{
		return NULL;
	}
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
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL || pHead2 == NULL)
	{
		return NULL;
	}
	int length1 = 0;
	int length2 = 0;
	ListNode *p1 = pHead1;
	ListNode *p2 = pHead2;
	while (p1 != NULL)
	{
		length1++;
		p1 = p1->next;
	}
	while (p2 != NULL)
	{
		length2++;
		p2 = p2->next;
	}
	p1 = pHead1;
	p2 = pHead2;
	if (length1 >= length2)
	{
		for (int i = 0; i < (length1 - length2); i++)
		{
			p1 = p1->next;
		}
	}
	else
	{
		for (int i = 0; i < (length2 - length1); i++)
		{
			p2 = p2->next;
		}
	}
	while (p1 != NULL && p2 != NULL)
	{
		if (p1 == p2)
		{
			return p1;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return NULL;
}