//��ʵ�������������ֱ��������л��ͷ����л�������

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
#include<sstream>
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
char* Serialize(TreeNode *root);
TreeNode* Deserialize(char *str);
void mySerialize(TreeNode *root, string &s);
TreeNode *myDeserialize(stringstream &ss);
int left_count = 0;
int main()
{
	vector<string> data = { "1", "2", "3", ".", "4", ".", "5", "6", "7", ".", "8" };
	TreeNode* root = CreateBinaryTree(data);
	char *result = Serialize(root);
	cout << result << endl;
	TreeNode *result_root = Deserialize(result);
	LayerOrder(result_root);
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
	if (root == NULL)
	{
		return;
	}
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
char* Serialize(TreeNode *root) 
{
	if (root == NULL)
	{
		return "$";
	}
	string res;
	mySerialize(root, res);
	char *result = new char[res.size()];
	strcpy(result, res.c_str());
	result[res.size() - 1] = '\0';
	return result;
}
void mySerialize(TreeNode *root, string &res)
{
	if (root == NULL)
	{
		res = res + "$,";
		return;
	}
	ostringstream s;
	s << root->val;
	res = res + s.str() + ",";
	mySerialize(root->left, res);
	mySerialize(root->right, res);
}
TreeNode* Deserialize(char *str) 
{
	stringstream ss(str);
	return myDeserialize(ss);
}
TreeNode *myDeserialize(stringstream &ss)
{
	string str;
	getline(ss, str, ',');
	if (str == "$")
		return NULL;
	else
	{
		TreeNode *node = new TreeNode(stoi(str));
		node->left = myDeserialize(ss);
		node->right = myDeserialize(ss);
		return node;
	}
}