#include <iostream>
using namespace std;

//变量
int a = 10;	//数据类型 变量名=值


/*
常量的定义方式
1. #define宏常量
2. const修饰的变量
*/

//#define 宏常量，通常定义在文件上方，全局生效（无类型、无作用域、无检查，仅适合简单文本替换）
#define Day 7

//const 修饰变量，局部生效（编译期只读变量，有类型、有作用域，首选）
const int Month = 12;


int main()
{
	//Day = 14;		不可以更改，因为Day是常量
	cout << "一周有：" << Day << "天" << endl;

	//	Month = 24;	 不可以更改，因为Month是常量
	cout << "一年有：" << Month << "月" << endl;




	//标识符的命令规则
	//1.标识符不可以是关键字
	// int int =10; 错误

	//2.标识符可以由字母、数字、下划线构成
	int abc = 10;
	int _abc = 20;
	int _123abc = 30;

	//3.标识符第一个字符只能是字母或下划线
	//int 123abc=10; 错误 

	//4.标识符区分大小写
	int aaa = 100;
	cout << aaa << endl;
	//cout << AAA << endl;		"AAA"未声名的标识符

	//建议：给变量名起名字时，尽量做到见名知意
	int num1 = 10;
	int num2 = 20;
	int sum = num1 + num2;
	cout << "num1 + num2=" << sum << endl ;








	system("pause");
	return 0;
}
