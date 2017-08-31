//LL���������ر��,��Ϊ��ȥ����һ���˿���,���������Ȼ��2������,2��С��(һ����ԭ����54��^_^)...��������г����5����,�����Լ�������,
//�����ܲ��ܳ鵽˳��,����鵽�Ļ�,������ȥ��������Ʊ,�ٺ٣���������A,����3,С��,����,��Ƭ5��,��Oh My God!������˳��.....LL��������,
//��������,������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����
//LL����ȥ��������Ʊ���� ����,Ҫ����ʹ�������ģ������Ĺ���,Ȼ���������LL��������Ρ�Ϊ�˷������,�������Ϊ��С����0��
//����˼·��������������򣬼���0�ĸ�������ͷ��ʼ�ҳ���Ҫ��յĸ�������0�ĸ����Ƚ�
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
bool IsContinuous(vector<int> numbers);
int main()
{
	vector<int> numbers = { 1, 2, 3, 0, 0 };
	Display_1D_Matrix(numbers);
	bool result = IsContinuous(numbers);
	if (result)
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
bool IsContinuous(vector<int> numbers) 
{
	if (numbers.size() != 5)
	{
		return false;
	}
	sort(numbers.begin(), numbers.end());
	int count_zero = 0;
	int i = 0;
	while (numbers[i] == 0)
	{
		count_zero++;
		i++;
	}
	if (count_zero > 4)
	{
		return false;
	}
	int count_gap = 0;
	for (int k = i; k < numbers.size() - 1; k++)
	{
		if (numbers[k + 1] == numbers[k])
		{
			return false;
		}
		count_gap = count_gap + (numbers[k + 1] - numbers[k]) - 1;
	}
	if (count_gap <= count_zero)
	{
		return true;
	}
	return false;
}
