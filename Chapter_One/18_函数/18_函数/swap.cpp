#include "swap.h"	//关联一下头文件
#include <iostream>
using namespace std;

void swap(int a, int b)
{
	cout << "调换前：" << endl << "a=" << a << "  " << "b=" << b << endl;

	int temp = a;
	a = b;
	b = temp;

	cout << "调换后：" << endl << "a=" << a << "  " << "b=" << b << endl;
}