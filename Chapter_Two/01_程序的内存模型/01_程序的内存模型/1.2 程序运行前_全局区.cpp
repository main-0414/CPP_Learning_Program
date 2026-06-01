#include <iostream>
using namespace std;


//全局变量
int g_a = 10;
int g_b = 10;

//const修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 10;



int main1()
{
	//全局区
	//全局变量、静态变量、常量




	//创建普通局部变量
	int a = 10;
	int b = 10;

	cout << "局部变量 a 的地址为：" << (int)&a << endl;
	cout << "局部变量 b 的地址为：" << (int)&b << endl << endl;
	//局部变量 存放在 栈区

	cout << "全局变量 a 的地址为：" << (int)&g_a << endl;
	cout << "全局变量 b 的地址为：" << (int)&g_b << endl;
	//全局变量 存放在 全局区

	// 生成发现局部变量和全局变量内存不在同一段里


	// 静态变量（在普通变量前面加static就是静态变量）
	static int s_a = 10;
	static int s_b = 10;

	cout << "静态变量 s_a 的地址为：" << (int)&s_a << endl;
	cout << "静态变量 s_b 的地址为：" << (int)&s_b << endl;
	// 运行发现全局变量和静态变量很近，他们都在一个区域段中
	// 全局变量和静态变量 存放在 全局区



	//常量
	// 1.字符串常量(双引号引起来的)
	cout << "字符串常量的内存地址是：" << (int)&"hello world" << endl;
	//运行发现 字符串常量 与 全局变量 和 静态变量 很近，他们都在全局区

	 

	// 2.const修饰的变量

	// 2.1const修饰的全局变量（全局常量）
	cout << "全局常量 c_g_a 的内存地址是：" << (int)&c_g_a << endl;
	cout << "全局常量 c_g_b 的内存地址是：" << (int)&c_g_b << endl;
	//运行发现常量与常量挨得更近，都在全局区

	// 2.2cosnt修饰的局部变量（局部常量）
	const int c_l_a = 10;	// l == local 局部
	const int c_l_b = 10;
	cout << "局部常量 c_l_a 的内存地址是：" << (int)c_l_a << endl;
	cout << "局部常量 c_l_b 的内存地址是：" << (int)c_l_b << endl;
	//运行发现，只要是局部修饰的，都不在全局区！

/*
	局部变量、const修饰的局部变量（局部常量）——>不在全局区
	全局变量、static静态变量、const修饰的全局变量（全局常量）、字符串常量——>全局区
*/

	
/*
	总结：
	全局区存放：
	全局变量、静态变量、全局常量（const 全局）、字符串常量

	栈区存放：
	局部变量、局部常量（const 局部）
*/


	system("pause");
	return 0;
}