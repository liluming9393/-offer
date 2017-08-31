//����һ�Ŷ�������һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����
//����˼·��ǰ�����ÿ���ڵ㣬��¼ÿ���ڵ㿪ʼ��·������ֵ�ͣ���Ŀ��ֵ�Ƚ�������
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
vector<vector<int> > FindPath(TreeNode* root, int expectNumber);
void mypath(TreeNode *root, int expectNumber, vector<vector<int>> &result, vector<int> path);
int left_count = 0;
int main()
{
	vector<string> data = { "10", "5", "12", "4", "7", ".", "." };
	//vector<string> data = { "10", "5", "-3", "3", "2", ".", "11", "3", "2", ".", "1", ".", "." };
	TreeNode* root = CreateBinaryTree(data);
	vector<vector<int>> result;
	result = FindPath(root, 22);
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size() - 1; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << result[i][result[i].size() - 1] << endl;
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
void mypath(TreeNode *root, int expectNumber, vector<vector<int>> &result, vector<int> path)
{
	if (root == NULL)
	{
		return;
	}
	if (root->val == expectNumber && root->left==NULL && root->right==NULL)
	{
		path.push_back(root->val);
		int level = result.size();
		result.resize(level + 1);
		for (int i = 0; i < path.size(); i++)
		{
			result[level].push_back(path[i]);
		}
	}
	else
	{
		path.push_back(root->val);
	}
	mypath(root->left, expectNumber - root->val, result, path);
	mypath(root->right, expectNumber - root->val, result, path);
}
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) 
{
	vector<vector<int>> result;
	if (root == NULL)
	{
		return result;
	}
	vector<int> path;
	mypath(root, expectNumber, result, path);
	return result;
}