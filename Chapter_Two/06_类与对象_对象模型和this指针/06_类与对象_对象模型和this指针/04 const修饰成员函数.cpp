#include <iostream>
using namespace std;

// 常函数、常变量专门用来存放一旦初始化就永远不能变的数据。

class Pers
{
public:
	// this 指针本质上是 指针常量		指针常量是不可以修改的	
	//			本质 Pers * const this;		值可改指向不可改
	// 那我想要指向不可改值也不可改怎么搞？在成员函数名后加 const
	//			本质 const Pers * const this;
	


	// !!结论：在成员函数后加const，修饰的是this指向，让指针指向的值也不可以修改



	// 这种函数叫常函数
	void showPerson() const
	{
	// 这里 m_A == this->m_A
		//m_A = 100;	// 报错：表达式必须是可修改的左值
		//this = NULL;	// 报错：this指针是不可以修改指针指向的

		m_B = 100;
	}

	void func()
	{

	}

	int m_A;
	mutable int m_B;	// 特殊变量，即使在常函数中，也可以修改这个值，加关键字mutable
};

void Test01()
{
	Pers p1;
	p1.showPerson();
}





// 常对象
void Test02()
{
	const Pers p2;	// 在对象前加const，变为常对象
	//p2.m_A = 100;	// 改m_A报错
	p2.m_B = 100;	// m_B是特殊值，在常对象下也可以修改(加了mutable不管是常函数还是常对象都可改)

	// 常对象只能调用常函数
	p2.showPerson();
	//p2.func();	// 报错，对象的类型是：const Pers
	// 常对象 不可以调用普通成员函数，因为普通成员函数可以修改属性
	// 常对象本身不能被修改，普通成员函数可能会修改数据，因此禁止常对象调用普通函数

}



int main()
{
	Test01();
	Test02();

	system("pause");
	return 0;
}