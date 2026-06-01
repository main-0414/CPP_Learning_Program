#include <iostream>
using namespace std;

//函数常见样式

//1.无参无返
void test01()
{
	cout << "This is test01 !!!" << endl << endl;
}

//2.有参无返
void test02(int a)
{
	cout << "This is test02 !!!" << endl << "a=" << a << endl;
}


//3.无参有返
int	 test03()
{
	cout << endl;
	return 1000;
}

//4.有参有返
int test04(int a)
{
	cout << endl;
	int answer = a - 11;
	return answer;
}




int main3()
{
	//无参无返的函数调用
	test01();
	
	//有参无返的函数调用
	test02(100);

	//无参有返的函数调用
	cout << test03() << endl;	//或者可以用一个变量存值 Num=test03();

	//有参有返的函数调用
	cout << test04(111) << endl;


	system("pause");
	return 0;
}



