//һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������
//����˼·������ݹ�ʽf(n)=2^(n-1)
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<stack>
using namespace std;
int jumpFloorII(int number);
int main()
{
	int number;
	while (cin >> number)
	{
		int result = jumpFloorII(number);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int jumpFloorII(int number) 
{
	int result = 1;
	for (int i = 1; i < number; i++)
	{
		result = result * 2;
	}
	return result;
}