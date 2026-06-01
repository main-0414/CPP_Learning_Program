#include <iostream>
using namespace std;

// 打印数据函数
void showValue(const int& val)
{
	//val = 1000;	  // ！这里不小心多写了一行修改了数据，我要怎么才能避免数据被篡改？在形参加个const
	cout << "val=" << val << endl;
}

int main()
{
	// 使用场景：常量引用主要用来修饰形参，防止误操作

	int a = 10;

	// int& ref = 10;	// 引用必须引一块合法的内存空间

	// ↑ 这里报错！！引用的本质是变量的别名，它必须绑定到一个左值（即具有持久内存地址的对象）。
	// 而字面量 10 是一个纯右值，它没有可寻址的内存位置（通常存储在寄存器或作为指令的立即数），
	// 因此无法直接绑定到非常量左值引用。


	// 但是加上cosnt之后，可以直接 = 10
	// 这里编译器将代码优化 int temp = 10;  const int & ref = temp; 自动建了一块内存存放临时数据
	const int& ref = 10;
	//ref = 20;			// 加入const后变为只读，不可修改


	// 主要目的：
	int v = 100;
	showValue(v);	// 此时a=1000

	cout << "v=" << v << endl;


	system("pause");
	return 0;
}