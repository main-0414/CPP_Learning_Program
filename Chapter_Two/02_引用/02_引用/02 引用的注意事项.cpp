#include <iostream>
using namespace std;

int main2()
{
	// 引用的注意事项


	int a = 10;
	// 1.引用必须初始化
	//int& b;		// 报错，必须有初始值
	int& b = a;

	// 2.引用初始化后，就不可以发生改变了
	int c = 20;
	b = c;	// 这只是单纯的赋值操作，而不是改变引用

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;





	system("pause");
	return 0;
}