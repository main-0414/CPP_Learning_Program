#include <iostream>
using namespace std;

// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量

class Hum
{
public:
	// 静态成员函数
	static void func()
	{
		m_A = 1000;		// 静态成员函数可以访问 静态成员变量（它不属于某一个对象，共享的）
		//m_B = 1000;		// 静态成员函数不可以访问 非静态成员变量，无法区分到底是哪个对象的m_B属性
		cout << "static void func() 的调用" << endl;
	}

	static int m_A;	// 静态成员变量
	int m_B;	// 非静态成员变量



	// 静态成员函数也是有访问权限的
private:
	static void func2()
	{
		cout << "static void func2() 的调用" << endl;
	}


};

int Hum::m_A = 0;	// 类外初始化



// 也有两种访问方式
void tess()
{
	// 1.通过对象访问
	Hum h;
	h.func();

	// 2.通过类名来访问
	Hum::func();

	//Hum::func2();	// 类外不可访问到静态成员函数
}





int main9()
{
	tess();
	

	system("pause");
	return 0;
}