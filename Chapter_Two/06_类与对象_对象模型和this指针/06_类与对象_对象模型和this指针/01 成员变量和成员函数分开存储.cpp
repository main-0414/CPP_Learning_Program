#include <iostream>
using namespace std;

// 成员函数 和 成员变量 分开存储

class Person
{
public:
	int m_A;	// 非静态成员变量		属于类的对象上

	static int m_B;	// 静态成员变量	不属于类对象上，不占对象空间

	void func(){}	// 非静态成员函数		不属于类对象上，不占对象空间
	// 运行发现还是4，表明 成员函数 和 成员变量 分开存储

	static void func2(){}	// 静态成员函数	不属于类对象上，不占对象空间
	// 还是4

	// 所以只有非静态成员变量属于类的对象上，其他都不属于
};
int Person::m_B = 0;



void test01()
{
	Person p;
	// 空对象占用的内存空间是：1字节
	// 因为c++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
	// 每个空对象也应该有一个独一无二的内存地址
	cout << "sizeof(p) 大小 = " << sizeof(p) << endl;
}

void test02()
{
	Person p;
	// 有一个非静态成员变量时候占用4字节（int4字节）
	cout << "sizeof(p) 大小 = " << sizeof(p) << endl;

}


int main1()
{
	//test01();
	test02();



	system("pause");
	return 0;
}