#include <iostream>	
using namespace std;

int main()
{
	//三目运算符

	int a, b, c;
	
	a = 10;
	b = 20;

	c=(a > b ? a: b);	// ？前面判断，如果判断为真 那么返回前面的a，为假返回后面的b
	cout << "c=" << c << endl;


	//在三目运算符中，返回的值是变量，可以赋一个值给它
	a = 10;
	b = 20;

	(a > b ? b : a) = 100;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;









	system("pause");
	return 0;
}