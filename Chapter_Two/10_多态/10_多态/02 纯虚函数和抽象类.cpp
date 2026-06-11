#include <iostream>
using namespace std;

// 纯虚函数和抽象类

// 纯虚函数的目的就是想让子类重写父类函数

// 抽象类的特点：
// 无法实例化对象
// 子类 ！必须！重写抽象类中的纯虚构函数，否则也属于抽象类


class Base
{
public:
	// 只要有一个纯虚函数，这个类就成为 抽象类
	// 抽象类特点：
	// 1.无法实例化对象
	// 2.抽象类的子类 必须要重写父类中的纯虚函数，否则也属于抽象类

	virtual void func() = 0;	// 纯虚函数

};


class Son :public Base
{
public:
	void func()
	{
		cout << "func() 的调用" << endl;		// 重载一下
	}


};




void Test01()
{
	//Base b;		// 报错，抽象类无法实例化对象
	//new Base;	// 报错，抽象类无法实例化对象

	//Son s;		// 子类不重载会报错，子类中必须重写父类中的纯虚函数，否则无法实例化对象

	Base* base = new Son;
	base->func();

}







int main2()
{
	Test01();

	system("pause");
	return 0;
}