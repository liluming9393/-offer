//���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����
//����˼·�������С�������ŷţ��ұ�ʣ��2*��n-1������ڷ�f(n-1)�����������С���κ��ŷţ��ұ�ʣ��2*��n-2������ڷ�f(n-2)���������Ϊf(n)������쳲���������
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int rectCover(int number);
int main()
{
	int number;
	while (cin >> number)
	{
		int result = rectCover(number);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int rectCover(int number) 
{
	int temp1 = 0;
	int temp2 = 1;
	int result;
	for (int i = 0; i < number; i++)
	{
		result = temp1 + temp2;
		temp1 = temp2;
		temp2 = result;
	}
	return result;
}