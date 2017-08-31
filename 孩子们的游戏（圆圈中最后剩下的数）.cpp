//ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�HF��Ϊţ�͵�����Ԫ��,��ȻҲ׼����һЩС��Ϸ��
//����,�и���Ϸ��������:����,��С������Χ��һ����Ȧ��Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������
//ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,��������һ��С���ѿ�ʼ,
//����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,���Բ��ñ���,�����õ�ţ������ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��
//������������,�ĸ�С���ѻ�õ������Ʒ�أ�(ע��С���ѵı���Ǵ�0��n-1)
//����˼·��ʹ��list����ɾ�����㣬ֱ��ʣ��һ����
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<list>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
int LastRemaining_Solution(int n, int m);
int main()
{
	int n = 10;
	int m = 2;
	int result = LastRemaining_Solution(n, m);
	cout << result << endl;
	system("pause");
	return 0;
}
void Display_1D_Matrix(vector<int> & data)
{
	if (data.size() == 0)
	{
		return;
	}
	for (int i = 0; i < data.size() - 1; i++)
	{
		cout << data[i] << " ";
	}
	cout << data[data.size() - 1] << endl;
}
void Display_2D_Matrix(vector<vector<int>> & data)
{
	if (data.size() == 0)
	{
		return;
	}
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size() - 1; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << data[i][data[i].size() - 1] << endl;
	}
}
int LastRemaining_Solution(int n, int m)
{
	if (n < 1 || m < 1)
	{
		return -1;
	}
	list<int> num;
	for (int i = 0; i < n; i++)
	{
		num.push_back(i);
	}
	list<int>::iterator it;
	it = num.begin();
	while (num.size() > 1)
	{
		for (int i = 1; i < m; i++)
		{
			it++;
			if (it == num.end())
			{
				it = num.begin();
			}
		}
		list<int>::iterator temp;
		temp = ++it;
		if (temp == num.end())
		{
			temp = num.begin();
		}
		it--;
		num.erase(it);
		it = temp;
	}
	return (*it);
}