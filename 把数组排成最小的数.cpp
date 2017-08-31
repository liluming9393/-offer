//输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
//则打印出这三个数字能排成的最小数字为321323。
//解题思路：定义两个数若第一个数排在前面第二个数排在后面的方式组成的数较小，则第一个数小于第二个数，按这种排列方式进行从小到大排序组成数即为结果
#include<iostream>
#include<stdint.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;
void Display_1D_Matrix(vector<int> & data);
void Display_2D_Matrix(vector<vector<int>> & data);
string PrintMinNumber(vector<int> numbers);
bool mycompare(int num1, int num2);//判断num1是否小于num2，即（num1num2)<(num2num1)
int main()
{
	vector<int> numbers = { 3, 32, 321 };
	Display_1D_Matrix(numbers);
	string result = PrintMinNumber(numbers);
	cout << result << endl;
	system("pause");
	return 0;
}
void Display_1D_Matrix(vector<int> & data)
{
	if (data.size() == 0)
	{
		return;
	}
	for (int i = 0; i < data.size() - 1; i++)
	{
		cout << data[i] << " ";
	}
	cout << data[data.size() - 1] << endl;
}
void Display_2D_Matrix(vector<vector<int>> & data)
{
	if (data.size() == 0)
	{
		return;
	}
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size() - 1; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << data[i][data[i].size() - 1] << endl;
	}
}
bool mycompare(int num1, int num2)//判断num1是否小于num2，即（num1num2)<(num2num1)
{
	ostringstream s;
	s << num1;
	s << num2;
	string s1 = s.str();
	int temp1 = atoi(s1.c_str());
	s.str("");
	s << num2;
	s << num1;
	string s2 = s.str();
	int temp2 = atoi(s2.c_str());
	if (temp1 < temp2)
	{
		return true;
	}
	return false;
}
string PrintMinNumber(vector<int> numbers) 
{
	if (numbers.size() == 0)
	{
		return "";
	}
	int temp;
	for (int i = 0; i < numbers.size() - 1; i++)
	{
		temp = i;
		for (int j = i + 1; j < numbers.size(); j++)
		{
			if (mycompare(numbers[j], numbers[temp]))
			{
				temp = j;
			}
		}
		if (temp != i)
		{
			swap(numbers[i], numbers[temp]);
		}
	}
	string result;
	for (int i = 0; i < numbers.size(); i++)
	{
		ostringstream s;
		s << numbers[i];
		result += s.str();
	}
	return result;
}