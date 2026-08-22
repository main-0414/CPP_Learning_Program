// 概念：
// STL内建了一些函数对象


// 分类：
// 算数仿函数
// 关系仿函数
// 逻辑仿函数


// 用法：
// 这些仿函数所产生的对象，用法和一般函数完全相同
// 使用 内建函数对象，需要引入头文件 #include <functional>


#include <iostream>
#include <algorithm>
using namespace std;

#include <functional>	// 内建的函数对象头文件

// 算数仿函数
// 功能：实现四则运算

// negate是一元运算，其他都是二元运算
void test01()
{
	negate<int> n;	// negate取反

	cout << n(50) << endl;	// 一元


}

// plus	二元仿函数	加法
void test02()
{
	plus<double> p;	// 默认传入同一种类型，所以只用写一个类型

	cout << p(10, 20) << endl;

}


// template<class T > T plus<T>				//加法仿函数
// template<class T > T minus<T>			//减法仿函数
// template<class T > T multiplies<T>		//乘法仿函数
// template<class T > T divides<T>			//除法仿函数
// template<class T > T modulus<T>			//取模仿函数
// template<class T > T negate<T>			//取反仿函数



int main()
{
	test01();
	test02();


	system("Pause");
	return 0;
}