//HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:
//�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
//����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
//����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����᲻�ᱻ������ס��(�������ĳ���������1)
//����˼·�����������Ե�i��Ϊ��β�����ͣ����ú�Ϊ��������һ�������Ϊ�䱾��������һ�������Ϊǰһ�����ͼ����䱾��ÿһ���β�����ͽ��бȽϵĳ��ܵ�����
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
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
int FindGreatestSumOfSubArray(vector<int> array);
int main()
{
	vector<int> array = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int result = FindGreatestSumOfSubArray(array);
	cout << result << endl;
	system("pause");
	return 0;
}
void Display_1D_Matrix(vector<int> & data)
{
	for (int i = 0; i < data.size() - 1; i++)
	{
		cout << data[i] << " ";
	}
	cout << data[data.size() - 1] << endl;
}
void Display_2D_Matrix(vector<vector<int>> & data)
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size() - 1; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << data[i][data[i].size() - 1] << endl;
	}
}
int FindGreatestSumOfSubArray(vector<int> array) 
{
	if (array.size() == 0)
	{
		return 0;
	}
	int result = array[0];
	int temp = array[0];
	for (int i = 1; i < array.size(); i++)
	{
		if (temp <= 0)
		{
			temp = array[i];
		}
		else
		{
			temp = temp + array[i];
		}
		if (temp > result)
		{
			result = temp;
		}
	}
	return result;
}