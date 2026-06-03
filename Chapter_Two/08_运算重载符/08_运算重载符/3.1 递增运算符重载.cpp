#include <iostream>
using namespace std;

// 重载递增运算符

// 自定义的整型变量
class MyInteger
{
	friend ostream& operator<<(ostream& cout, const MyInteger& myint);

public:
	MyInteger()
	{
		m_Num = 0;
	}

	// 重载前置++运算符		返回引用是为了一直对一个数据进行递增操作
	MyInteger& operator++()
	{
		// 先进行++运算，再将自身进行返回
		++m_Num;
		return *this;
	}


	// 重载后置++运算符
	// void operator++(int)		int 代表占位参数，可以用于区分前置和后置递增，且参数只能为 int
	// 后置运算符（a++ / a--）不能返回引用！
	// 因为它必须返回自增 / 自减前的旧值，而这个旧值只能保存在函数内部的临时对象里。
	// 局部临时对象在函数结束后会立即销毁，返回它的引用会产生「悬空引用（野引用）」，触发未定义行为（程序崩溃、随机值、数据损坏）。
	
	// 加const是为了发生链式调用，因为c++标准后置递增是没办法链式。
	// 加了 const 会返回一个const 类型的类，返回的 temp 被标记为 const，外界拿到这个副本后只能读，不能改。

	const MyInteger operator++(int)
	{
		// 先 记录当时结果
		MyInteger temp = *this;
		// 后 递增
		m_Num++;
		// 最后将记录结果做返回
		return temp;	// 如果返回的是引用的话，局部对象temp在函数执行完会自动释放
	}



private:
	int m_Num;
};



// 左移运算符重载
ostream& operator<<(ostream& cout, const MyInteger& myint)
{
	cout << myint.m_Num;
	return cout;
}


void Test01()	// 前置递增测试案例
{
	MyInteger Myint;

	cout << ++(++Myint) << endl;	// 不写递增运算符重载会报错：没有与这些操作数匹配的 "++" 运算符
	// 不知道如何对我们自己写的数据类型做++运算
	cout << Myint << endl;
}

void Test02()	// 后置递增测试案例
{
	MyInteger Myint2;

	cout << Myint2++ << endl;	// 返回0，Myint + 1 = 1

	cout << (Myint2++)++ << endl;	// 无意义，原生 int 的 (a++)++ 会报错
	// 内层Myint2++：返回值为1，原对象自身数值自增为2
	// 外层++：作用于返回的临时副本，并非原对象，最终输出旧值1，仅副本数值加1

	cout << Myint2 << endl;	// 2

}




int main31()
{
	//Test01();


	//int a = 0;

	//cout << ++(++a) << endl;
	//cout << a << endl;

	Test02();

	// 前置递增返回引用，后置递增返回值


	system("pause");
	return 0;
}