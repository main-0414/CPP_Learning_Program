#include <iostream>
using namespace std;

class MyInt
{
	friend ostream& operator<<(ostream& cout, const MyInt& myint);
	// 常量引用传递的特点：可以接受所有类型的值（左值、右值、常量对象）。
	// C++ 有一条特殊规则：临时对象可以绑定到常量左值引用
public:
	MyInt();
	MyInt& operator--();	// 前置
	MyInt operator--(int);	// 后置

private:
	int m_Num;
};

MyInt::MyInt()
{
	m_Num = 10;
}

// 前置递减
MyInt& MyInt:: operator--()
{
	--m_Num;
	return *this;
}

// 后置递减
MyInt MyInt:: operator--(int)
{
	MyInt temp = *this;
	m_Num--;
	return temp;
}

// 左移运算符重载
ostream& operator<<(ostream& cout, const MyInt& myint)
{
	cout << myint.m_Num;
	return cout;
}

// 测试案例
void tes1()
{
	MyInt m_int;

	cout << m_int-- << endl;
	cout << m_int << endl;

	cout << --m_int << endl;
	cout << m_int << endl;
}





int main32()
{
	tes1();


	system("pause");
	return 0;
}