#include <iostream>
using namespace std;

// 函数默认参数

// 如果我们自己传入参数，就用自己的数据，如果没有，就用默认值
// 语法：返回值类型 函数名（形参 = 默认值）{ ...... }

int func(int a, int b = 20, int c = 30)
{
	return a + b + c;
}



// !!!注意事项!!!

// 1.如func2()，如果某个位置已经有了默认参数，那么从这个位置往后，都必须得有默认值

//int func2(int a, int b = 10, int c)	// 报错：缺少形参3的默认实参
//{
//	return a + b + c;
//}


// 2.如果函数声明有默认参数，函数实现就不能有默认参数
// 声明和实现只能有一个有默认参数（声明 or 实现只能有一个有默认参数）
//int func3(int a = 10, int b = 10);
//int func3(int a = 10, int b = 10)	// 报错：重定义默认参数：参数1、参数2（有二义性）
//{
//	return a + b;
//}



int main1()
{
	cout << func(10) << endl;
	//cout << func3() << endl;



	system("pause");
	return 0;
}