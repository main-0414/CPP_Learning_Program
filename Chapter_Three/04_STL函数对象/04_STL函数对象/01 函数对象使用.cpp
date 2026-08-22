// 函数对象（仿函数）基本概念：
// 重载函数调用操作符的类，其对象称为函数对象
// 函数对象使用重载的()时，行为类似函数调用，也叫仿函数

// 本质：
// 函数对象(仿函数)是一个类，不是一个函数

// 特点：
// 函数对象在调用的时候，可以像普通函数那样调用，可以有参数，可以有返回值
// 函数对象超出普通函数的概念，函数对象可以有自己的状态
// 函数对象可以作为参数传递


#include <iostream>
#include <string>
using namespace std;


class MyAdd
{
public:
	int operator()(int v1, int v2)	// 灵活，可写参数可写返回值
	{
		return v1 + v2;
	}
};



// 1. 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01()
{
	MyAdd myadd;	// 这里的myadd就称之为函数对象了

	cout << myadd(10, 10) << endl;

}



// 2. 函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint
{
public:
	MyPrint()
	{
		this->count = 0;
	}

	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}

	int count;	// 内部自己状态
};


void test02()
{
	MyPrint myprint;
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");
	myprint("hello world");

	cout << "myPrint 调用次数为：" << myprint.count << endl;

}



// 3. 函数对象可以作为参数传递

void doPrint(MyPrint& mp, string test)
{
	mp(test);
}


void test03()
{
	MyPrint myprint;
	doPrint(myprint, "hello C++");
}





int main()
{
	test01();
	test02();
	test03();

	system("pause");
	return 0;
}