#include <iostream>
using namespace std;

class person
{
	// 用友元可以使你自己写的左移运算符重载 可以访问类内的私有内容
	friend ostream& operator<<(ostream& cout, person& p);

public:
	// 利用成员函数重载 左移运算符		p.operator<<(cout)	简化版本 p << cout
	// 所以不会利用函数重载 << 运算符，因此无法实现 cout 在左侧

	//void operator<<(ostream cout)
	//{

	//}

	person(int a, int b) :m_A(a), m_B(b) {}


private:
	int m_A;
	int m_B;

};





// 只能利用全局函数重载 左移运算符
					// 标准输出流对象cout全局唯一，禁止拷贝，所以要用引用方式传入
ostream& operator<<(ostream& cout, person& p)	// 本质： operator << (cout, p)	 简化  cout << p								
{
	cout << "m_A = " << p.m_A << " m_b = " << p.m_B;
	return cout;	// cout不是一个函数，不是一个工具，也不是一个命令。它是一个"正在写字的笔"。
}
// 写完这个左移运算符重载就和标准库所有的operator<<函数地位完全平等了，
// 遵守同一个 "递笔" 规则，所以就能无缝衔接在一起链式调用






void test()
{
	person p(10, 10);

	cout << p << endl;	// 重载左移运算符配合 友元 可以实现输出自定义数据类型

}



int main2()
{
	test();

	system("pause");
	return 0;
}