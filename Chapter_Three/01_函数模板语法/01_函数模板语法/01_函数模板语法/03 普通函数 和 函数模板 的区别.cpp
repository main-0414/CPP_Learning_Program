#include <iostream>
using namespace std;

// 普通函数 和 函数模板 的区别

// 1. 普通函数调用可以发生隐式类型转换
// 2. 函数模板 用自动类型推导，不可以发生隐式类型转换
// 3. 函数模板 用指定显示类型，可以发生隐式类型转换



// 普通函数
int myAdd01(int a, int b)
{
	return a + b;
}


// 函数模板
template <class T>
T myAdd02(T a, T b)
{
	return a + b;
}




void test04()
{
	int a = 10;
	int b = 20;
	char c = 'c';	// ascii a = 97	c = 99
	cout << myAdd01(a, c) << endl;


	// 自动类型推导	不会发生隐式类型转换
	//cout << myAdd02(a, c) << endl;	// 产生二义性，编译器不知道要转成Int还是char


	// 显式指定类型	会发生隐式类型转换
	cout << myAdd02<int>(a, c) << endl;

}


// 总结：建议使用 显式指定类型方式 来 调用函数模板，可以自己确定通用T







int main3()
{
	test04();

	system("pause");
	return 0;
}