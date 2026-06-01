#include <iostream>
using namespace std;

// 拷贝构造函数的调用时机

// 1.使用一个已经创建完毕的对象来初始化一个新对象

// 2.值传递的方式给函数参数传值

// 3.值方式来返回局部对象

class per
{
public:
	per() { cout << "默认构造函数调用" << endl; }

	int m_age;
	per(int age)	// 有参构造来初始化年龄
	{
		m_age = age;
		cout << "有参构造函数调用" << endl;
	}

	per(const per& p)
	{
		m_age = p.m_age;
		cout << "拷贝构造函数调用" << endl;
	}

	~per() { cout << "析构函数调用" << endl; }

};

// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test001()
{
	per p1(30);
	per p2(p1);		// 此时拷贝
	cout << "p2 的年龄为：" << p2.m_age << endl;
}


// 2.值传递的方式给函数参数传值（进函数时拷贝）
void doWork(per p) {}

void test002()
{
	per p;		// 默认构造函数调用 → 创建本体对象
	doWork(p);	// 把外面的 p 传给 doWork 的形参 p
	//用原对象 复制出一个 全新的副本对象，传给函数当形参。只要创建新对象，必须走构造函数
}

// 3.值方式来返回局部对象（出函数时拷贝）
per doWork2()
{
	per p1;
	cout << (int*)&p1 << endl;
	return per(p1);	// per(p1) → 手动调用拷贝构造，创建一个匿名临时对象
	//return p1;	// 用值方式返回时，根据p1，创建出一个新的对象，然后返回(编译器优化了效果出不来)

}

void test003()
{
	per p = doWork2();
	cout << (int*)&p << endl;
}






int main3()
{
	//test001();
	//test002();
	//test003();






	system("pause");
	return 0;
}