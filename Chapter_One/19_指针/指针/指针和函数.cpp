#include <iostream>
using namespace std;


void swap01(int a, int b);	

void swap01(int a,int b)
{
	int temp = a;
	a = b;
	b = temp;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}

void swap02(int* p1, int* p2);

void swap02(int* p1, int* p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	cout << "*p1=" << *p1 << endl;
	cout << "*p2=" << *p2 << endl;
}

int main7()
{
	//指针和函数
	int a = 10;
	int b = 20;

	// 1.值传递（之前学的）  不会改变实参
	//swap01(a, b);
	//cout << "a=" << a << endl;
	//cout << "b=" << b << endl;

	
	// 2.地址传递
	swap02(&a, &b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	//发现实参也变了：地址传递，可以改变实参

	//如果你不想修改实参，那就用值传递，反之用地址传递。

	






	system("pause");
	return 0;
}