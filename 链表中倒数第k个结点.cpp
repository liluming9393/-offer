//����һ����������������е�����k����㡣
//����˼·��ʹ��˫ָ�룬��һ��ָ��������k����㣬����ָ��һ���ߣ�ֱ����һ��ָ���ߵ�����β�����ڶ���ָ��ָ������k����㣬ע���������
//û��ͷ���
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
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k);
int main()
{
	vector<int> data = { 5, 5, 3, 4, 5 };
	ListNode* head = CreateList(data);
	DispList(head);
	int k;
	while (cin >> k)
	{
		ListNode *result = FindKthToTail(head, k);
		if (result == NULL)
		{
			cout << "error" << endl;
		}
		else
		{
			cout << result->val << endl;
		}
	}
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
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (k <= 0 || pListHead == NULL)
	{
		return NULL;
	}
	ListNode *p1 = pListHead;
	ListNode *p2 = pListHead;
	for (int i = 0; i < k; i++)
	{
		if (p1 == NULL)
		{
			return NULL;
		}
		p1 = p1->next;
	}
	while (p1 != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p2;
}