//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//解题思路：求出递归式f(n)=2^(n-1)
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