#include <iostream>
using namespace std;

int main1()
{
	//指针

	int a = 100;
	cout << "a=" << a << endl;


	//定义指针
	//语法：  数据类型 * 变量名
	int* p;

	//让指针记录变量a的地址，建立关系
	p = &a;

	cout << "a的地址为：" << &a << endl;
	cout << "指针p的地址为：" << p << endl;

	//2.使用指针
	//可以通过解引用的方式来找到指针指向的地址
	

	// 指针前面带 * 表示解引用：找到指针指向的内存，获取/修改内存里面的数据
	*p = 1000;		// 解引用指针 p，修改 p 指向的变量的内存值为 1000

	cout << endl << "a=" << a << endl;
	cout << "*p=" << *p << endl;
	// p 指向变量 a 的地址，解引用修改的是同一块内存，所以 a 的值会同步改变

/*	
	指针p 存的是 a 的地址
	*p代表 a 本身
	所以 修改 *p = 修改 a
*/



	system("pause");
	return 0;
}