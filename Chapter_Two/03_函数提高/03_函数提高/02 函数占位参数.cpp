#include <iostream>
using namespace std;

// 占位参数
// 返回值类型	函数名(数据类型){ }

// 目前阶段的占位参数 我们还用不到，后面课程中会用到
// 占位参数 还可以有默认参数
void func(int a = 10, int = 11)
{
	cout << "this is func" << endl;
}

int main2()
{
	func(11111, 10);	// 第二个10是拿不到的
	// 占位参数必须填补


	system("pause");
	return 0;
}