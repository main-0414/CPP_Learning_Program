#include <iostream>
using namespace std;

int main3()
{
	//1.字符型(1字节)
	char ch = 'a';	//单引号内只能写一个字符
	cout << "ch=" << ch << endl;
	cout << "char类型占用空间为：" << sizeof(ch) << endl;

	//2.常见错误
	//char ch2 = "b"	//创建字符型变量时，要用单引号
	//char ch2 = 'abcdef';	//创建字符型变量时，单引号内只能写一个字符


	//3.字符对应的ASCII码
	cout << (int)ch << endl;
	//  a —— 97	  A —— 65









	system("pause");
	return 0;
}