//输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
//（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
//解题思路：在每个结点后插入相同结点，并将random指针指向正确位置，然后将两个链表拆开
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
struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
RandomListNode* CreateList(vector<int> &data);
void DispList(RandomListNode* head);
RandomListNode* Clone(RandomListNode* pHead);
int main()
{
	vector<int> data = { 1, 2, 3, 4, 5 };
	RandomListNode* head = CreateList(data);
	RandomListNode* p1 = head;
	p1->random = p1->next->next;
	p1 = p1->next;
	p1->random = p1->next->next->next;
	p1->next->next->random = p1;
	DispList(head);
	RandomListNode *result = Clone(head);
	DispList(result);
	system("pause");
	return 0;
}
RandomListNode* CreateList(vector<int> &data)
{
	if (data.size() == 0)
	{
		return NULL;
	}
	RandomListNode *head = new RandomListNode(data[0]);
	RandomListNode *p = head;
	for (int i = 1; i < data.size(); i++)
	{
		RandomListNode *temp = new RandomListNode(data[i]);
		p->next = temp;
		p = p->next;
	}
	p->next = NULL;
	return head;
}
void DispList(RandomListNode* head)
{
	RandomListNode *p = head;
	while (p != NULL)
	{
		cout << p->label << " ";
		p = p->next;
	}
	cout << endl;
}
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}
	RandomListNode *p1 = pHead;
	while (p1 != NULL)
	{
		RandomListNode *temp = new RandomListNode(p1->label);
		temp->next = p1->next;
		p1->next = temp;
		p1 = p1->next->next;
	}
	p1 = pHead;
	while (p1 != NULL)
	{
		if (p1->random != NULL)
		{
			p1->next->random = p1->random->next;
		}
		p1 = p1->next->next;
	}
	RandomListNode *result = pHead->next;
	RandomListNode *p2 = result;
	p1 = pHead;
	while (p1 != NULL)
	{
		p1->next = p2->next;
		p1 = p2->next;
		if (p1 != NULL)
		{
			p2->next = p1->next;
			p2 = p1->next;
		}
	}
	return result;
}