#include <iostream>
using namespace std;

// 栈区(客栈)数据注意事项 ————> 不要返回局部变量的地址
// 栈区的数据由编译器管理开辟和释放

int* func(int b)		// 形参数据也会放在栈上
// int类型的地址返回接收的是一个 int* 类型
{
	int a = 10;	// 局部变量 ————> 存放在栈区，栈区的数据在函数执行完后自动释放
	b = 100;
	return &a;	// 返回局部变量的地址
}



int main2()
{
	int* p = func(1);	// 接收func函数返回的值
	//指针定义语法： 数据类型 * 变量名 = x;

	cout << *p << endl;	//成功是因为编译器保留了数据
	cout << *p << endl;
	cout << *p << endl;
	//第二次乱码，变量a在函数里是局部变量，放在栈上，函数执行完栈上的数据就清空了



	system("pause");
	return 0;
}