#include <iostream>
using namespace std;

int main1()
{
	// 引用：给变量起名
	// 语法：数据类型 &别名 = 原名

	int a = 10;
	int& b = a;	// 不同名字但是指向同一块内存
	cout << a << endl;
	cout << b << endl;


	b = 20;
	cout << a << endl;
	cout << b << endl;







	system("pause");
	return 0;
}