#include <iostream>
using namespace std;

int main5()
{
	// 1.const修饰指针 ———— 常量指针
	int a = 10;
	int b = 20;

	const int * p = &a;		//把*翻译成指针，就为常量指针
	
	//指针指向的 值 不可以改，指针的 指向 可以改
	// *p = 20;	 // “表达式必须是可修改的左值。”
	p = &b;		



	// 2.const修饰指针 ———— 指针常量
	int * const p2 = &a;	//常量锁定的是指针，所以指针指向不可改
	
	*p2 = 12345;	//值可改
	//p2 = &b;		// “表达式必须是可修改的左值。”



	// 3.const修饰指针和常量
	const int * const p3 = &a;
	//指向和指向的值都不可改

/*
	p3 = &b;		//错误
	*p3 = 54321;	//错误
*/





	system("pause");
	return 0;
}