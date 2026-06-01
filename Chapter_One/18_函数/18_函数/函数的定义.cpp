#include <iostream>
using namespace std;

	//函数
	//实现一个加法函数，功能是：传入两个整型数据，计算数据相加的结果，并且返回。

	//1.返回值类型		int
	//2.函数名			add
	//3.参数列表			(int num1, int num2)
	//4.函数体语句		int sum = num1 + num2;
	//5.return表达式		return sum;

/*	返回值类型 函数名 （参数列表）
	{

		   函数体语句

		   return表达式

	}
*/

	//返回值类型 ：一个函数可以返回一个值。在函数定义中
	//函数名：给函数起个名称
	//参数列表：使用该函数时，传入的数据
	//函数体语句：花括号内的代码，函数内需要执行的语句
	//return表达式： 和返回值类型挂钩，函数执行完后，返回相应的数据

int test(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}