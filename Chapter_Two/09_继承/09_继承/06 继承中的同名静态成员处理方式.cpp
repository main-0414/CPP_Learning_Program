#include <iostream>
using namespace std;

// 静态中的的同名成员处理方式
class Base
{
public:
	static void func()
	{
		cout << "Base static void func()" << endl;
	}

	static void func(int a)
	{
		cout << "Base static void func(int a)" << endl;
	}




	static int m_A;
};

int Base::m_A = 100;



class sonson:public Base
{
public:
	static void func()
	{
		cout << "sonson static void func()" << endl;
	}

	static int m_A;

};

int sonson::m_A = 200;






//同名静态成员属性
void Tes()
{
	// 1.通过对象来访问
	cout << "通过对象来访问:" << endl;
	sonson s;
	cout << "sonson 下的 m_A = " << s.m_A << endl;
	cout << "Base 下的 m_A = " << s.Base::m_A << endl << endl;


	// 2.通过类名来访问
	cout << "通过类名来访问:" << endl;
	cout << "sonson 下的 m_A = " << sonson::m_A << endl;
	cout << "Base 下的 m_A = " << Base::m_A << endl;

	// 第一个::代表通过类名方式访问	第二个::代表访问父类作用域下

	// sonson::Base::m_A 等价于：
	// 先进入 sonson 类，找到它的父类 Base；
	// 再进入 Base 类，访问它的静态成员 m_A。
	cout << "Base 下的 m_A = " << sonson::Base::m_A << endl;
	// 两者调用的函数完全相同，都可以用
}




void Tes2()
{
	// 1.通过对象访问
	cout << "通过对象访问：" << endl;
	sonson s;
	s.func();	// 调子类自己
	s.Base::func();	// 调父类


	// 2.通过类名访问
	cout << endl << "通过类名访问：" << endl;
	sonson::func();
	sonson::Base::func();

	// 和同名成员重载一样，当子类与父类拥有同名的成员函数，子类会隐藏父类中所有同名成员函数
	// 想访问父类中被隐藏的同名成员，加作用域可以访问到父类中同名函数
	sonson::Base::func(100);


}


// 总结：同名静态承欢处理方式和非静态处理方式一样，只不过有两种访问的方式（通过对象 和 通过类名）







int main6()
{
	//Tes();
	Tes2();

	system("pause");
	return 0;
}