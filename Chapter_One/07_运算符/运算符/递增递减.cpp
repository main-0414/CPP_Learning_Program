#include <iostream>
using namespace std;

int main3()
{
	//前置递增
	int a = 1;
	++a;
	cout << a << endl;

	//后置递增
	int b = 10;
	b++;
	cout << b << endl;

	//区别
	//前置递增：先让变量+1，再进行表达式运算
	int a1 = 10;
	int b1 = ++a1 * 10;
	cout << "a1=" << a1 << endl;
	cout << "b1=" << b1 << endl;

	//后置递增：先进行表达式运算，再让变量+1
	int a2 = 10;
	int b2 = a2++ * 10;
	cout << "a2=" << a2 << endl;
	cout << "b2=" << b2 << endl;


	//前置递减
	int a3 = 20;
	int b3 = --a3*100;
	cout << "a3=" << a3 << endl;
	cout << "b3=" << b3 << endl;

	//后置递减
	int a4 = 20;
	int b4 = a4-- * 100;
	cout << "a4=" << a4 << endl;
	cout << "b4=" << b4 << endl;







	system("pause");
	return 0;
}