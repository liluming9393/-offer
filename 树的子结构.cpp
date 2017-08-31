//输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
//解题思路：遍历A树每一个结点，对每个结点为根的树与B树进行比较
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
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
bool compare(TreeNode *root1, TreeNode* root2);
int left_count = 0;
int main()
{
	vector<string> data1 = { "8", "8", "7", "9", "2", ".", ".", ".", ".", "4", "7" };
	TreeNode* root1 = CreateBinaryTree(data1);
	vector<string> data2 = { "8", "9", "2" };
	TreeNode *root2 = CreateBinaryTree(data2);
	bool result = HasSubtree(root1, root2);
	if (result == true)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
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
bool compare(TreeNode *root1, TreeNode* root2)
{
	if (root2 == NULL)
	{
		return true;
	}
	if (root1 == NULL && root2 != NULL)
	{
		return false;
	}
	if (root1->val != root2->val)
	{
		return false;
	}
	return compare(root1->left, root2->left) && compare(root1->right, root2->right);
}
bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
	if (pRoot1 == NULL || pRoot2 == NULL)
	{
		return false;
	}
	bool result = false;
	if (pRoot1->val == pRoot2->val)
	{
		result = compare(pRoot1, pRoot2);
	}
	if (result == false)
	{
		result = HasSubtree(pRoot1->left, pRoot2);
	}
	if (result == false)
	{
		result = HasSubtree(pRoot1->right, pRoot2);
	}
	return result;
}