//输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。
//解题思路：1、将1与该数相与若得1表明最低位为1否则为0，然后将1左移得到2与该数相与判断倒数第二位，依次类推，不可以将该数右移，因为负数时出错
//2、将该数与其减1的数相与，将最右边的1变成0，不断进行指导所有数都为0，一共循环多少次即有多少个1
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
int  NumberOf1(int n);
int main()
{
	int n;
	while (cin >> n)
	{
		int result = NumberOf1(n);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int  NumberOf1(int n)
{
	//解法一
	/*int result = 0;
	unsigned int flag = 1;
	for (int i = 0; i < 32; i++)
	{
		if ((n & flag) == flag)
		{
			result++;
		}
		flag = flag << 1;
	}
	return result;*/
	//解法2
	int result = 0;
	while (n)
	{
		result++;
		n = n & (n - 1);
	}
	return result;
}