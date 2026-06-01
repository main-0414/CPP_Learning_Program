#include <iostream>
using namespace std;

int main1()
{
	//整型：
	//short(2字节)    int(4字节)    long(4)    longlong(8)
	//可利用 sizeof() 来查看数据类型所占的内存空间大小

	short num1 = 10;
	cout << "short占用的内存空间大小是：" << sizeof(short) << endl;
	cout << "short占用的内存空间大小是：" << sizeof(num1) << endl;

	int num2 = 10;
	cout << "int占用的内存空间大小是：" << sizeof(num2) << endl;

	long num3 = 10;
	cout << "long占用的内存空间大小是：" << sizeof(num3) << endl;

	long long num4 = 10;
	cout << "long long占用的内存空间大小是：" << sizeof(num4) << endl << endl;

	system("pause");
	return 0;
}