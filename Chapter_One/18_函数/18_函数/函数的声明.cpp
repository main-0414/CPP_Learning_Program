#include <iostream>
using namespace std;

//函数的声明

//写一个比较函数，实现两个整型数字进行比较，返回较大的值

//声明：提前告诉编译器函数的存在，让计算机去找，声明后main函数无需放在最后。
//声明可以有很多次，但定义只能有一次

int max(int a, int b);
int max(int a, int b);

int main4()
{
	int b = 90;
	int a = 100;
	cout << max(b, a) << endl;

	system("pause");
	return 0;
}


//定义
int max(int a, int b)
{
	return a > b ? a : b;
}