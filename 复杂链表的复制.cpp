//����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩�����ؽ��Ϊ���ƺ��������head��
//��ע�⣬���������벻Ҫ���ز����еĽڵ����ã�������������ֱ�ӷ��ؿգ�
//����˼·����ÿ�����������ͬ��㣬����randomָ��ָ����ȷλ�ã�Ȼ�����������
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