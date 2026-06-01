#include <iostream>
using namespace std;



// 赋值运算符重载
class person
{
public:
	person(int age)
	{
		m_Age = new int(age);	// 开辟在堆区
	}


	~person()
	{
		if (m_Age != nullptr)
		{
			delete m_Age;
			m_Age = nullptr;
		}
	}



	// 重载赋值运算符
	person& operator=(person &p)
	{
		// 编译器提供的浅拷贝
		//m_Age = p.m_Age;

		// 应该先判断是否有属性在堆区，如果有要先释放干净，然后再深拷贝
		// 这里需要判断判断是因为对象有旧值，如果是“新建的时机”不用
		if (m_Age != nullptr)
		{
			delete m_Age;
			m_Age = nullptr;

		}

		// 深拷贝
		m_Age = new int(*p.m_Age);	// 传入的要复制的对象的m_Age赋值到我自身

		return *this;
	}


	int* m_Age;
};


void test1()
{
	person p1(10);
	person p2(20);
	person p3(30);
	
	p3 = p2 = p1;	// 默认赋值操作：浅拷贝（指向的内存一致，堆区内存重复释放，报错！）
	
	cout << "p1的年龄为：" << *p1.m_Age << endl;
	cout << "p2的年龄为：" << *p2.m_Age << endl;
	cout << "p3的年龄为：" << *p3.m_Age << endl;


}



int main4()
{
	test1();

	//int a = 10;
	//int b = 20;
	//int c = 30;

	//c = b = a;

	//cout << "a=" << a <<endl<< "b=" << b <<endl<< "c=" << c << endl;
	// 默认数据类型支持连等







	system("pause");
	return 0;
}