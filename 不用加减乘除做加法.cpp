//дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�
//����˼·�����������Ϊ���û��λ�Ľ��������������Ϊ��λ�Ľ�����ٽ���ͽ�����λ�������ظ��ò���ֱ����λΪ0
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
int Add(int num1, int num2);
int main()
{
	int num1 = -2;
	int num2 = 13;
	int result = Add(num1, num2);
	cout << result << endl;
	system("pause");
	return 0;
}
int Add(int num1, int num2)
{
	int sum, carry;
	do
	{
		sum = num1^num2;
		carry = (num1&num2) << 1;
		num1 = sum;
		num2 = carry;
	} while (carry != 0);
	return num1;
}