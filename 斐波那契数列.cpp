//��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�n <= 39
//����˼·���Ե����ϵ������㣬�ݹ鸴�Ӷȹ���
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
using namespace std;
int Fibonacci(int n);
int main()
{
	int n;
	while (cin >> n)
	{
		int result = Fibonacci(n);
		cout << result << endl;
	}
	system("pause");
	return 0;
}
int Fibonacci(int n) 
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	int result = 0;
	int temp1 = 0;
	int temp2 = 1;
	for (int i = 1; i < n; i++)
	{
		result = temp1 + temp2;
		temp1 = temp2;
		temp2 = result;
	}
	return result;
}