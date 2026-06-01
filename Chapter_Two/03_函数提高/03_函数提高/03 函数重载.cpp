#include <iostream>
using namespace std;

// 函数重载：函数名可以相同，提高复用性

// 满足条件：
// 1.同一个作用域下，全局作用域下
// 2.函数名称相同
// 3.函数参数 类型不同 or 个数不同 or 顺序不同




void func()
{
	cout << "func()的调用" << endl;
}

void func(int a)	// 个数不同
{
	cout << "func(int a)的调用" << endl;
}

void func(double a)	// 类型不同
{
	cout << "func(double a)的调用" << endl;
}



void func(int a, double b)
{
	cout << "func(int a, double b)的调用" << endl;
}

void func(double b, int a)	// 顺序不同
{
	cout << "func(double b, int a)的调用" << endl;
}

// 注意！函数的返回值不可以作为函数重载的条件
//int func(double b, int a)
//{
//	cout << "func(double b, int a)的调用" << endl;
//}



int main3()
{
	func();
	func(1111);
	func(3.14);

	func(10, 3.14);
	func(3.14, 10);	// 36与42两个函数都可以走，他不知道走哪一个（二义性）



	system("pause");
	return 0;
}