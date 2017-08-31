//给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
//解题思路:分情况讨论，如果右子树不是空则结果为右子树最左边结点，如果右子树为空，该结点是其父亲左孩子则结果为其父节点，若该结点是其父亲右孩子则追溯到一个节点的父节点的左孩子是其本身，该父节点为结果
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
TreeLinkNode* CreateBinaryTree(vector<string> data);//创建二叉树
void PreOrder(TreeLinkNode* root);//前序遍历
void InOrder(TreeLinkNode* root);//中序遍历
void PostOrder(TreeLinkNode* root);//后序遍历
void LayerOrder(TreeLinkNode* root);//层先遍历
void Leaf(TreeLinkNode* root);//统计叶节点数目，输出叶节点
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
//建立二叉树
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
//前序遍历
void PreOrder(TreeLinkNode* root)
{
	if (root != NULL)
	{
		cout << root->val << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//中序遍历
void InOrder(TreeLinkNode* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->val << " ";
		InOrder(root->right);
	}
}
//后序遍历
void PostOrder(TreeLinkNode* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->val << " ";
	}
}
//层先遍历
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
//统计叶节点数目，输出叶节点
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