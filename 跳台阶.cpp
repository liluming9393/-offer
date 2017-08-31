//一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
//解题思路：动态规划，满足斐波那契数列递归式，自底向上迭代计算
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