#include <iostream>
using namespace std;

int main()
{
	//逻辑运算符
	int a = 10;		//在C++中，除了0都为真

	// !   非not	
	cout << !a << endl;		//进行取反 由真变假
	cout << !!a << endl;	//再次取反 由假变真

	cout << "\n";


	// &&  与and
	//同真为真，其余为假(有一个为假就直接为假)
	a = 10;
	int b = 10;
	cout << (a && b) << endl;
	
	a = 5;
	b = 0;
	cout << (a && b) << endl;

	a = 0;
	b = 0;
	cout << (a && b) << endl;
	

	printf("\n");

	// ||  或or
	//同假为假，其余为真
	a = 10;
	b = 10;
	cout << (a || b) << endl;

	a = 5;
	b = 0;
	cout << (a || b) << endl;

	a = 0;
	b = 0;
	cout << (a || b) << endl;


	system("pause");
	return 0;
}