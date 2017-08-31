//�������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��
//����˼·������A��ÿһ����㣬��ÿ�����Ϊ��������B�����бȽ�
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
TreeNode* CreateBinaryTree(vector<string> data);//����������
void PreOrder(TreeNode* root);//ǰ�����
void InOrder(TreeNode* root);//�������
void PostOrder(TreeNode* root);//�������
void LayerOrder(TreeNode* root);//���ȱ���
void Leaf(TreeNode* root);//ͳ��Ҷ�ڵ���Ŀ�����Ҷ�ڵ�
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
//����������
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
//ǰ�����
void PreOrder(TreeNode* root)
{
	if (root != NULL)
	{
		cout << root->val << " ";
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//�������
void InOrder(TreeNode* root)
{
	if (root != NULL)
	{
		InOrder(root->left);
		cout << root->val << " ";
		InOrder(root->right);
	}
}
//�������
void PostOrder(TreeNode* root)
{
	if (root != NULL)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		cout << root->val << " ";
	}
}
//���ȱ���
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
//ͳ��Ҷ�ڵ���Ŀ�����Ҷ�ڵ�
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