//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
//解题思路：扫描整个链表进行删除
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
ListNode* deleteDuplication(ListNode* pHead);
int main()
{
	vector<int> data = { 1, 2, 3, 3, 3 };
	ListNode* head = CreateList(data);
	DispList(head);
	head = deleteDuplication(head);
	DispList(head);
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
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
	{
		return pHead;
	}
	ListNode *myhead = new ListNode(0);
	myhead->next = pHead;
	ListNode *p1 = myhead;
	ListNode *p2 = pHead;
	ListNode *p3 = pHead->next;
	while (p3 != NULL)
	{
		if (p2->val == p3->val)
		{
			while (p2->val == p3->val)
			{
				p1->next = p3;
				p2 = p3;
				p3 = p3->next;
				if (p3 == NULL)
				{
					break;
				}
			}
			if (p3 != NULL)
			{
				p1->next = p3;
				p2 = p3;
				p3 = p3->next;
			}
			else
			{
				p1->next = p3;
			}
		}
		else
		{
			p1 = p2;
			p2 = p3;
			p3 = p3->next;
		}
	}
	return myhead->next;
}