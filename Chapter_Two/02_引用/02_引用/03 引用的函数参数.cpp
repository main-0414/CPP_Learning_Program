#include <iostream>
using namespace std;

// 交换函数
// 1.值传递
void swap01(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01 a=" << a << endl;
	cout << "swap01 b=" << b << endl;
}


// 2.地址传递
void swap02(int *a,int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	cout << "swap02 a=" << *a << endl;
	cout << "swap02 b=" << *b << endl;
}

// 3.引用传递
void swap03(int &x, int &y)		//和值传递差不多，形参加一个&
		  // 形参的x和y 是 实参a和b的别名
{
	int temp = x;
	x = y;
	y = temp;
	cout << "swap03 x=" << x << endl;
	cout << "swap03 y=" << y << endl;
}




int main4()
{
	int a = 10;int b = 20;
	//swap01(a, b);	// 值传递，形参不会修饰实参
	//swap02(&a, &b);	// 地址传递，形参会修饰实参
	swap03(a, b);	// 引用传递，形参会修饰实参
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	



	system("pause");
	return 0;
}