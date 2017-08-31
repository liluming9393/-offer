//我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
//解题思路：最左边小矩形竖着放，右边剩余2*（n-1）区域摆法f(n-1)，最左边两个小矩形横着放，右边剩余2*（n-2）区域摆法f(n-2)，两者相加为f(n)，满足斐波那契数列
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