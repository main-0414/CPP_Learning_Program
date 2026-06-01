#include <iostream>
using namespace std;

class pers
{
public:
	// 传统初始化操作
	//pers(int a, int b, int c)
	//{
	//	m_A = a;
	//	m_B = b;
	//	m_C = c;
	//}


	// 初始化列表初始化属性
	pers(int a, int b, int c) :m_A(a), m_B(b), m_C(c)
	{
		// 可以空
	}



	// 成员变量
	int m_A;
	int m_B;
	int m_C;
};

void t1()
{
	pers p(30,20,10);		// 当我创建对象时，调用构造函数，顺便就把你写的属性赋值了

	cout << "m_A = " << p.m_A << endl;
	cout << "m_B = " << p.m_B << endl;
	cout << "m_C = " << p.m_C << endl;
}




int main6()
{
	t1();

	system("pause");
	return 0;
}