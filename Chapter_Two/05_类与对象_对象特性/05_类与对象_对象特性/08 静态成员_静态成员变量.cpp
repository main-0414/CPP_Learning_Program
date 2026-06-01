#include <iostream>
using namespace std;

// 静态成员变量
class Human
{
public:
	// 1.所有对象都共享同一份数据
	// 2.编译阶段就分配内存
	// 3.类内声明，类外初始化操作

	static int m_A;

	// 静态成员变量也是有访问权限的
private:
	static int m_B;

};

int Human::m_A = 100;	// 类外初始化
int Human::m_B = 200;

void tt1()
{
	Human h;	//100
	cout << h.m_A << endl;	// 没有类外初始化运行会报错：无法解析的外部命令。

	Human h2;
	h2.m_A = 200;
	cout << h.m_A << endl;	//200
	// 说明m_A是两人共享的数据
}

void tt2()
{
	// 静态成员变量 不属于某个对象上，所有对象都共享同一份数据
	// 因此静态成员变量有 两种访问方式

	// 1.通过对象进行访问
	//Human h;
	//cout << h.m_A << endl;


	// 2.通过类名进行访问
	cout << Human::m_A << endl;
	//cout << Human::m_B << endl;		// 类外访问不到私有静态变量
}






int main8()
{
	//tt1();
	tt2();



	system("pause");
	return 0;
}