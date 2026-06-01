#include <iostream>
using namespace std;


void func(int& ref)
{
	ref = 100;	// ref是引用，转换为 *ref = 100;
}


int main9()
{
	// 本质：引用的本质在c++内部实现是一个 指针常量
	// 可以理解为 引用 是一个封装好的 指针常量

	int a = 10;

	// 自动转换为 int* const = &a; 指针 指向不可以改，值 可以更改
	// 指针的一个特点也是：指针一旦初始化后，就不可以发生改变
	int& ref = a;
	ref = 20;	// 内部发现ref是引用，自动帮我们转换为：*ref = 20;

	cout << "a:" << a << endl;
	cout << "ref:" << ref << endl;

	func(a);

	cout << "func() 后的 a:" << a << endl;

	// C++推荐使用引用技术，因为语法方便，引用本质是常量指针，但所有的指针操作编译器都帮我们做了

	system("pause");
	return 0;
}