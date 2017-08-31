//写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
//解题思路：两个数异或为求和没进位的结果，两个数相与为进位的结果，再将求和结果与进位结果相加重复该步骤直到进位为0
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