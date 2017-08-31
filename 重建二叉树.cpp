//输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
//例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
//解题思路：前序遍历序列第一个数为根，从中序遍历序列找到这个数，左边的数为左子树，右边的数为右子树，递归建立左右子树
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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* CreateBinaryTree(vector<string> data);//创建二叉树
void PreOrder(TreeNode* root);//前序遍历
void InOrder(TreeNode* root);//中序遍历
void PostOrder(TreeNode* root);//后序遍历
void LayerOrder(TreeNode* root);//层先遍历
void Leaf(TreeNode* root);//统计叶节点数目，输出叶节点
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin);
int left_count = 0;
int main()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode *result = reConstructBinaryTree(pre, vin);
	PreOrder(result);
	cout << endl;
	InOrder(result);
	cout << endl;
	system("pause");
	return 0;
}
//建立二叉树
TreeNode* CreateBinaryTree(vector<string> data)
{
	queue<TreeNode*> q;
	if (data.size() == 0)
	{
		return NULL;
	}
	int temp;
	temp = atoi(data[0].c_str());
	TreeNode* root = new TreeNode(temp);
	TreeNode* parent = new TreeNode(0);
	q.push(root);
	for (int i = 1; i < data.size();)
	{
		parent = q.front();
		q.pop();
		if (data[i] != ".")
		{
			temp = atoi(data[i].c_str());
			TreeNode *left = new TreeNode(temp);
			parent->left = left;
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
			TreeNode *right = new TreeNode(temp);
			parent->right = right;
			q.push(right);
		}
		i = i + 1;
	}
	return root;
}
//前序遍历
void PreOrder(TreeNode* root)
{
	if (root != NULL)
	{
		cout << root->val << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//中序遍历
void InOrder(TreeNode* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->val << " ";
		InOrder(root->right);
	}
}
//后序遍历
void PostOrder(TreeNode* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->val << " ";
	}
}
//层先遍历
void LayerOrder(TreeNode* root)
{
	queue<TreeNode*> q;
	TreeNode* temp = new TreeNode(0);
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
void Leaf(TreeNode* root)
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
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
{
	if (pre.size() == 0)
	{
		return NULL;
	}
	TreeNode *root = new TreeNode(pre[0]);
	int i = 0;
	for (i = 0; i < vin.size(); i++)
	{
		if (vin[i] == pre[0])
		{
			break;
		}
	}
	if (i != 0)//构建左子树
	{
		vector<int> pre_left;
		vector<int> vin_left;
		for (int k = 0; k < i; k++)
		{
			pre_left.push_back(pre[k + 1]);
			vin_left.push_back(vin[k]);
		}
		TreeNode *left_root = reConstructBinaryTree(pre_left, vin_left);
		root->left = left_root;
	}
	else if (i == 0)//无左子树
	{
		root->left = NULL;
	}
	if (i != vin.size() - 1)//构建右子树
	{
		vector<int> pre_right;
		vector<int> vin_right;
		for (int k = 0; k < (vin.size() - 1 - i); k++)
		{
			pre_right.push_back(pre[k + i + 1]);
			vin_right.push_back(vin[k + i + 1]);
		}
		TreeNode *right_root = reConstructBinaryTree(pre_right, vin_right);
		root->right = right_root;
	}
	else if (i == vin.size() - 1)//无右子树
	{
		root->right = NULL;
	}
	return root;
}