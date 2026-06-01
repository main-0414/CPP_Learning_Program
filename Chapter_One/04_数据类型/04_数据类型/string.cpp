#include <iostream>
#include <string>
using namespace std;

int main4()
{
	//字符串型

	//1.C语言风格
	//添加一个头文件 #include <string>
	//注意事项：字符串名后要加一个中括号[]（字符数组？？）
	char str[] = "Hello World";
	cout << str << endl;



	//2.C++风格
	string str1 = "Hello World1";
	cout << str1 << endl;





	system("pause");
	return 0;
}