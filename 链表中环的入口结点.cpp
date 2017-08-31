//一个链表中包含环，请找出该链表的环的入口结点。
//解题思路：首先使用快慢指针判断链表是否有环，若有环计算环中有多少个结点，然后使用双指针指向头结点，其中一个先走环中结点个数步，然后两个指针一起走，相遇时即为入口结点
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
ListNode* EntryNodeOfLoop(ListNode* pHead);
int main()
{
	vector<int> data = { 1, 2, 3, 4, 5, 6 };
	ListNode* head = CreateList(data);
	ListNode *p1 = head;
	ListNode *p2 = head;
	while (p2->next != NULL)
	{
		p2 = p2->next;
	}
	p1 = p1->next;
	p1 = p1->next;
	p2->next = p1;
	ListNode * result = EntryNodeOfLoop(head);
	if (result == NULL)
	{
		cout << "no loop" << endl;
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
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	ListNode *p1 = pHead;
	ListNode *p2 = pHead;
	while (p2->next != NULL && p2->next->next != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
		if (p2 == NULL)
		{
			return NULL;
		}
		p2 = p2->next;
		if (p2 == NULL)
		{
			return NULL;
		}
		if (p1 == p2)
		{
			break;
		}
	}
	if (p2->next == NULL || p2->next->next == NULL)
	{
		return NULL;
	}
	int count = 0;
	p2 = p2->next;
	count++;
	while (p1 != p2)
	{
		p2 = p2->next;
		count++;
	}
	p1 = pHead;
	p2 = pHead;
	for (int i = 0; i < count; i++)
	{
		p2 = p2->next;
	}
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}