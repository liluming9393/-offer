//����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
//����˼·��1����1�������������1�������λΪ1����Ϊ0��Ȼ��1���Ƶõ�2����������жϵ����ڶ�λ���������ƣ������Խ��������ƣ���Ϊ����ʱ����
//2�������������1�������룬�����ұߵ�1���0�����Ͻ���ָ����������Ϊ0��һ��ѭ�����ٴμ��ж��ٸ�1
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
	//�ⷨһ
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
	//�ⷨ2
	int result = 0;
	while (n)
	{
		result++;
		n = n & (n - 1);
	}
	return result;
}