//����ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
//��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�
//����˼·��ǰ��������е�һ����Ϊ������������������ҵ����������ߵ���Ϊ���������ұߵ���Ϊ���������ݹ齨����������
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
	if (i != 0)//����������
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
	else if (i == 0)//��������
	{
		root->left = NULL;
	}
	if (i != vin.size() - 1)//����������
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
	else if (i == vin.size() - 1)//��������
	{
		root->right = NULL;
	}
	return root;
}