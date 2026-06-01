#include <iostream>
using namespace std;

int main2()
{
	//%取余

	int a1 = 10;
	int b1 = 3;
	
	cout << a1 % b1 << endl;

	int a2 = 11;
	int b2 = 20;
	cout << a2 % b2 << endl;	//除不尽结果还是原来的被除数


	int a3 = 10;
	int b3 = 0;
	cout << a3 % b3 << endl;	//Integer division by zero.除数不能为0


	double bb1 = 3.14;
	double bb2 = 5.1;
	//cout << bb1 % bb2 << endl;	//小数不能取模






	system("pause");
	return 0;
}