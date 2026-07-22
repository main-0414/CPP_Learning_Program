#include <iostream>
using namespace std;

// 通过全局函数 打印Human信息



// 提前让编译器直到Human存在
template<class T1, class T2>
class Human;



// 弄到前面来，让编译器直到有一个printHuman2的存在。但弄到前面来了 Human 类编译器又不知道了，所以还得再在前面做一个Human类声明
// 2. 全局函数在类外实现
template<class A, class B>
void printHuman2(Human<A, B> h)		// 类内是T1、T2，但没问题，T1、T2 和 A、B 只是模板参数的名字不同，它们不是类型本身
{
	cout << "类外实现 ———— 姓名：" << h.m_Name << "  年龄：" << h.m_Age << endl;
}




template <class T1,class T2>
class Human
{

	// 1. 全局函数 类内实现
	friend void printHuman(Human<T1,T2> h) //必须写<>，因为这里的 T1、T2 是当前这个Human对象自己的模板参数，不是函数调用时推导出来的参数。
	{
		cout << "姓名：" << h.m_Name << "  年龄：" << h.m_Age << endl;
	}




	// 2. 全局函数 类外实现
	// 加空模板参数列表
	// 如果全局函数 是 类外实现，需要让编译器提前直到这个函数的存在，声明实现写在此类前面
	friend void printHuman2<>(Human<T1, T2> h);	// 不加“<>”是一个普通函数声明，但上面template后的函数是一个函数模板




public:
	Human(T1 name, T2 age)
		:m_Name(name),m_Age(age)
	{ }


private:
	T1 m_Name;
	T2 m_Age;
};


// 1. 全局函数在类内实现
void test12()
{
	Human<string, int> h("观观王", 18);

	printHuman(h);

}





// 2. 全局函数在类外实现
void test13()
{
	Human<string, int> h("Tom", 18);

	printHuman2(h);

}

// 总结：如果不是闲出屁那就老老实实把全局函数做类内实现，简单啊且可识别





int main()
{
	test12();
	test13();

	system("pause");
	return 0;
}