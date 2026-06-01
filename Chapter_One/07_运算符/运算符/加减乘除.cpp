#include <iostream>
using namespace std;

int main1()
{
	//算术运算符

	int a1 = 10;
	int a2 = 3;

	cout << a1 + a2 << endl;
	cout << a1 - a2 << endl;
	cout << a1 * a2 << endl;
	cout << a1 / a2 << endl;	//两个整数相除，结果依然是整数，将小数部分去除


	int b1 = 10;
	int b2 = 20;
	cout << b1 / b2 << endl;	//结果小数，但去除小数部分 为0

	
	//两个小数也可以相除
	float f1 = 3.3;
	float f2 = 2.235;
	cout << f1 / f2 << endl;


	system("pause");
	return 0;
}

	