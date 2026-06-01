#include <iostream>
using namespace std;

//值传递
//定义函数，实现两个数字进行交换

//如果函数不需要返回值，声明的时候可以写void

/*void change(int num1, int num2)
{
	cout << "交换前a=" << num1 << endl;
	cout << "交换前b=" << num2 << endl;

	int temp = num1;
	num1 = num2;
	num2 = temp;

	cout << "交换后a=" << num1 << endl;
	cout << "交换后b=" << num2 << endl;

	//	return;	返回值不需要的时候，可以不要return。
}*/
void change1(int a, int b)
{
	cout << "交换前a=" << a << endl;
	cout << "交换前b=" << b << endl;

	int temp = a;
	a = b;
	b = temp;

	cout << "交换后a=" << a << endl;
	cout << "交换后b=" << b << endl;

	//	return;	返回值不需要的时候，可以不要return。
}

int main2()
{
	int a = 10;
	int b = 20;

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	//当我们做值传递的时候，函数的形参发生变化，并不会影响实参。 
	//形参和实参名字一模一样，它们也是两个完全独立、互不干扰的变量。
	//change(a, b);
	change1(a, b);

	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	//实参不会改变

	system("pause");
	return 0;
}
