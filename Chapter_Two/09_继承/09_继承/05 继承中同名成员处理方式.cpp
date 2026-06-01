#include <iostream>
using namespace std;

// 继承中同名成员的处理
class Base
{
public:
	Base() { m_A = 100; }

	void func()
	{
		cout << "Base 下 func() 的调用" << endl;
	}

	void func(int a)	// 重载
	{
		cout << "Base 下 func(int a) 的调用" << endl;
	}


	int m_A;
};

class son1:public Base
{
public:
	son1() { m_A = 200; }

	void func()
	{
		cout << "son1 下 func() 的调用" << endl;
	}

	int m_A;	// 同名
};




// 同名成员属性处理
void tess()
{
	son1 s;
	cout << "Son 下 m_A = " << s.m_A << endl;	// 200，直接点出来是子类自身的

	cout << "Base 下 m_A = " << s.Base::m_A << endl;	
	// 如果想通过子类对象访问到父类中的同名成员，需要加作用域
}



// 同名成员函数处理
void tess2()
{
	son1 s;
	s.func();	// 直接调用 调用的是子类中的同名成员

	// 如何调用到父类中同名成员函数？
	s.Base::func();		// 子访问父类内函数，也需要加作用域

	// !!!如果子类中出现了和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数!!!
	// 如果想访问到父类中被隐藏的同名成员函数，需要加作用域
	s.Base::func(100);
}

// 总结：
// 1. 子类对象可以直接访问到子类中同名成员
// 2. 子类对象加作用域可以访问到父类同名成员
// 3. 当子类与父类拥有同名的成员函数，子类会隐藏父类中所有同名成员函数，加作用域可以访问到父类中同名函数




int main5()
{
	//tess();
	tess2();

	system("pause");
	return 0;
}