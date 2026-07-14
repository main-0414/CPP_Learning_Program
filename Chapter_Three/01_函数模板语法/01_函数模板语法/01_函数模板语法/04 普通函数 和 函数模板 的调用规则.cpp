#include <iostream>
using namespace std;

// 普通函数 和 函数模板 的调用规则
// 1. 如果函数模板 和 普通函数都可以匹配，优先调用普通函数
// 2. 可以通过 空模板参数列表 来 强制调用 函数模板
// 3. 函数模板也可以发生重载
// 4. 如果 函数模板 可以 产生更好的匹配，优先调用 函数模板


void myPrint(int a, int b)
{
	cout << "普通函数" << endl;
}

template<class T>
void myPrint(T a, T b)		// 允许函数重载
{
	cout << "函数模板" << endl;
}

template<class T>
void myPrint(T a, T b,T c)		// 允许函数重载
{
	cout << "重载的函数模板" << endl;
}





void test05()
{
	int a = 10;
	int b = 20;

	//myPrint(a, b);	// 都可以调，但优先 普通函数


	// 通过空模板参数列表，强制调用模板函数
	myPrint<>(a, b);


	// 调用重载的函数模板
	myPrint(a, b, 100);



	// 如果函数模板产生更好的匹配，优先函数模板
	char c1 = 'c1';
	char c2 = 'c2';

	myPrint(c1, c2);	// 调用了函数模板，走普通函数还需要进行一次转换，而函数模板可以直接猜出来类型直接用
}


// 总结：既然提供了函数模板，那就不要再用普通函数了，避免产生二义性




int main4()
{
	test05();


	system("pause");
	return 0;
}