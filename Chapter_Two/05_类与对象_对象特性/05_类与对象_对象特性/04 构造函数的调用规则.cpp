#include <iostream>
using namespace std;

// 构造函数的调用规则

// 1.创建一个类，C++编译器会至少给每个类添加至少三个函数
// 默认构造（空实现）
// 析构函数（空实现）
// 拷贝构造（值拷贝）

// 2.如果我们写了有参构造函数，编译器就不再提供默认构造函数，但依然提供拷贝构造 
	 //如果我们写了拷贝构造函数，那么编译器就不再提供其他普通构造函数了

class Per
{
public:
	//Per() { cout << "默认构造函数调用" << endl; }
	// 写了有参构造就一定要写默认构造

	//Per(int age)
	//{
	//	m_age = age;
	//	cout << "有参构造函数调用" << endl;
	//}

	Per(const Per& p)
	{
		m_age = p.m_age;
		cout << "拷贝构造函数调用" << endl;
	}

	//~Per() { cout << "析构函数调用" << endl; }


	int m_age;
};

//void tes1()
//{
//	Per p1;
//	p1.m_age = 18;
//
//	Per p2(p1);
//	cout << "p2的年龄为：" << p2.m_age << endl;
//}

//void tes2()
//{
//	Per p(28);
//	Per p3(p);		// 把默认构造注释，且有 有参构造，此时编译器依然提供拷贝构造
//}

//void tes3()
//{
//	Per p4;		// 如果只自定义了一个拷贝构造函数，那么其他普通构造函数就不再提供
//	// 报错: 没有合适的默认构造函数可用
//}



int main4()
{
	//tes1();
	//tes2();
	//tes3();

	system("pause");
	return 0;
}