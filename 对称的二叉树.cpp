//请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
//解题思路：自己定义一个函数用来判断两个树是否对称，将原数的左右子树作为参数传入该函数判断
#include<iostream>
#include <stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<queue>
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
bool isSymmetrical(TreeNode* pRoot);
bool myisSymmertrical(TreeNode *root1, TreeNode *root2);
int left_count = 0;
int main()
{
	vector<string> data = { "8", "6", "6", "5", "7", "7", "5" };
	TreeNode* root = CreateBinaryTree(data);
	bool result = isSymmetrical(root);
	cout << result << endl;
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
bool isSymmetrical(TreeNode* pRoot)
{
	if (pRoot != NULL)
	{
		return myisSymmertrical(pRoot->left, pRoot->right);
	}
	return true;
}
bool myisSymmertrical(TreeNode *root1, TreeNode *root2)
{
	if (root1 == NULL && root2 == NULL)
	{
		return true;
	}
	if (root1 != NULL && root2 != NULL)
	{
		if (root1->val == root2->val)
		{
			return myisSymmertrical(root1->left, root2->right) && myisSymmertrical(root1->right, root2->left);
		}
		else
		{
			return false;
		}
	}
	return false;
}