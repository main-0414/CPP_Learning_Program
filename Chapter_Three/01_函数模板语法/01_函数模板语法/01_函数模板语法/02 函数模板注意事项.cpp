#include <iostream>
using namespace std;


// 函数模板注意事项

template<typename T>// typename 可以替换为 class
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


// 1.自动类型推导，必须推导出一致的数据类型 T 才能使用
void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';

	//mySwap(a, b);	// 正确
	//mySwap(a, c);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}



// 2.模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()	// 紧跟模板定义的函数就是函数模板了
{
	cout << "func() 调用" << endl;

}

void test03()
{
	//func();	// 报错了，此时编译器没办法猜出数据类型，只能手动告诉
	func<int>();
}










int main2()
{
	test02();
	test03();


	system("pause");
	return 0;
}