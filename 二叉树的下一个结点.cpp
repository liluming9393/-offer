//����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣
//����˼·:��������ۣ�������������ǿ�����Ϊ����������߽�㣬���������Ϊ�գ��ý�����丸����������Ϊ�丸�ڵ㣬���ý�����丸���Һ�����׷�ݵ�һ���ڵ�ĸ��ڵ���������䱾���ø��ڵ�Ϊ���
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<string>
using namespace std;
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
	}
};
TreeLinkNode* CreateBinaryTree(vector<string> data);//����������
void PreOrder(TreeLinkNode* root);//ǰ�����
void InOrder(TreeLinkNode* root);//�������
void PostOrder(TreeLinkNode* root);//�������
void LayerOrder(TreeLinkNode* root);//���ȱ���
void Leaf(TreeLinkNode* root);//ͳ��Ҷ�ڵ���Ŀ�����Ҷ�ڵ�
TreeLinkNode* GetNext(TreeLinkNode* pNode);
int left_count = 0;
int main()
{
	vector<string> data = { "1", "2", "3", ".", "4", ".", "5", "6", "7", ".", "8" };
	TreeLinkNode* root = CreateBinaryTree(data);
	InOrder(root);
	cout << endl;
	TreeLinkNode *pNode = root;
	pNode = root->right->right->right;
	pNode = root->left->right->left;
	pNode = root->left->right->right;
	TreeLinkNode *result = GetNext(pNode);
	if (result != NULL)
	{
		cout << pNode->val << " " << result->val << endl;
	}
	else
	{
		cout << pNode->val << " NULL" << endl;
	}
	system("pause");
	return 0;
}
//����������
TreeLinkNode* CreateBinaryTree(vector<string> data)
{
	queue<TreeLinkNode*> q;
	if (data.size() == 0)
	{
		return NULL;
	}
	int temp;
	temp = atoi(data[0].c_str());
	TreeLinkNode* root = new TreeLinkNode(temp);
	TreeLinkNode* parent = new TreeLinkNode(0);
	q.push(root);
	for (int i = 1; i < data.size();)
	{
		parent = q.front();
		q.pop();
		if (data[i] != ".")
		{
			temp = atoi(data[i].c_str());
			TreeLinkNode *left = new TreeLinkNode(temp);
			parent->left = left;
			left->next = parent;
			q.push(left);
		}
		i = i + 1;
		if (i == data.size())
		{
			break;
		}
		if (data[i] != ".")
		{
			temp = atoi(data[i].c_str());
			TreeLinkNode *right = new TreeLinkNode(temp);
			parent->right = right;
			right->next = parent;
			q.push(right);
		}
		i = i + 1;
	}
	return root;
}
//ǰ�����
void PreOrder(TreeLinkNode* root)
{
	if (root != NULL)
	{
		cout << root->val << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//�������
void InOrder(TreeLinkNode* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->val << " ";
		InOrder(root->right);
	}
}
//�������
void PostOrder(TreeLinkNode* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->val << " ";
	}
}
//���ȱ���
void LayerOrder(TreeLinkNode* root)
{
	queue<TreeLinkNode*> q;
	TreeLinkNode* temp = new TreeLinkNode(0);
	q.push(root);
	while (q.empty() != true)
	{
		temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left != NULL)
		{
			q.push(temp->left);
		}
		if (temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
}
//ͳ��Ҷ�ڵ���Ŀ�����Ҷ�ڵ�
void Leaf(TreeLinkNode* root)
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
		{
			cout << root->val << " ";
			left_count++;
		}
		Leaf(root->left);
		Leaf(root->right);
	}
}
TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode==NULL)
	{
		return NULL;
	}
	TreeLinkNode *result = NULL;
	if (pNode->right != NULL)
	{
		result = pNode->right;
		while (result->left != NULL)
		{
			result = result->left;
		}
	}
	else if (pNode->next != NULL && pNode->right == NULL)
	{
		if (pNode->next->left == pNode)
		{
			result = pNode->next;
		}
		else if (pNode->next->right == pNode)
		{
			result = pNode;
			while (result->next != NULL && result->next->right == result)
			{
				result = result->next;
			}
			if (result->next == NULL)
			{
				result = NULL;
			}
			else
			{
				result = result->next;
			}
		}
	}
	else if (pNode->next == NULL && pNode->right == NULL)
	{
		result = NULL;
	}
	return result;
}