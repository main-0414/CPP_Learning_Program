#include <iostream>
using namespace std;

// 函数重载的注意事项

// 1.引用作为重载的条件
void func(int& a)	// int& a=10; 不合法
{
	cout << "func(int &a)调用" << endl;
}

// 第二种写法，属于类型不同
void func(const int& a)		// cosnt int& a=10; 合法
{
	cout << "func(cosnt int &a)调用" << endl;
}

// 2.函数重载碰到默认参数

void func2(int a)
{
	cout << "func2(int a)的调用" << endl;
}

void func2(int a, int b = 10)	// 编译器不知道要调哪一个
{
	cout << "func2(int a, int b=10)的调用" << endl;
}


int main()
{

	int a = 10;	// 如果是一个变量传进一个函数中，那么他会走“可读可写”这种状态的版本
	func(a);

	// 如果我想调用const的版本
	func(10);	// 直接写一个常量

	// 为什么？因为这样写传入参数相当于 cosnt int& a=10;
	// 而不加const只能接收 栈区 或者 堆区数据，直接写一个常量区数据是不合法的
	// 加了 const 版本 就是 const int& a=10; 合法。ide自动创建一个临时temp，令 int& a=temp



	// 函数重载碰到默认参数
	func2(10);	// 当函数重载碰到默认参数，出现二义性，报错，尽量避免出现这种情况




	system("pause");
	return 0;
}