//һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������
//����˼·����̬�滮������쳲��������еݹ�ʽ���Ե����ϵ�������
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int jumpFloor(int number);
int main()
{
	int number;
	while (cin >> number)
	{
		int result = jumpFloor(number);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int jumpFloor(int number) 
{
	int result;
	int temp1 = 0;
	int temp2 = 1;
	for (int i = 1; i <= number; i++)
	{
		result = temp1 + temp2;
		temp1 = temp2;
		temp2 = result;
	}
	return result;
}