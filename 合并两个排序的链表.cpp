//输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。
//解题思路：分别用两个指针指向两个链表，比较两个指针所指元素的值，小的与合并链表结果相连，知道一个指针为空，将另一个链表连到后面，注意特殊情况
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
ListNode* Merge(ListNode* pHead1, ListNode* pHead2);
int main()
{
	vector<int> data1 = { 1, 2, 3, 4, 5 };
	ListNode* head1 = CreateList(data1);
	DispList(head1);
	vector<int> data2 = { 3, 4, 5, 6 };
	ListNode* head2 = CreateList(data2);
	DispList(head2);
	ListNode *result = Merge(head1, head2);
	DispList(result);
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
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL && pHead2 == NULL)
	{
		return NULL;
	}
	if (pHead1 != NULL && pHead2 == NULL)
	{
		return pHead1;
	}
	if (pHead1 == NULL && pHead2 != NULL)
	{
		return pHead2;
	}
	ListNode *result;
	ListNode *p1 = pHead1;
	ListNode *p2 = pHead2;
	if (p1->val <= p2->val)
	{
		result = p1;
		p1 = p1->next;
	}
	else
	{
		result = p2;
		p2 = p2->next;
	}
	ListNode *p3 = result;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->val <= p2->val)
		{
			p3->next = p1;
			p1 = p1->next;
		}
		else
		{
			p3->next = p2;
			p2 = p2->next;
		}
		p3 = p3->next;
	}
	if (p1 == NULL)
	{
		p3->next = p2;
	}
	else
	{
		p3->next = p1;
	}
	return result;
}