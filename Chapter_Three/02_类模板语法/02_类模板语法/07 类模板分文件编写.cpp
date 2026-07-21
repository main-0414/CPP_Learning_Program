#include <iostream>
#include <string>
using namespace std;

// 第一种方法，直接包含源文件（但一般很少这么做）
#include "HUMAN.cpp"

// 第二种方法，将 .h 和 .cpp 中的内容写到一起，将后缀名改为 .hpp 文件
#include "HUMAN.hpp"

// 类模板的分文件编写问题以及解决
//template<class T1, class T2>
//class HUMAN
//{
//public:
//	HUMAN(T1 name, T2 age);
//
//	void showHuman();
//
//
//	T1 m_Name;
//	T2 m_Age;
//
//};


//template<class T1, class T2>
//HUMAN<T1, T2>::HUMAN(T1 name, T2 age)
//	:m_Name(name),m_Age(age)
//{}
//
//template<class T1, class T2>
//void HUMAN<T1, T2>::showHuman()
//{
//	cout << "姓名：" << m_Name << "  年龄：" << m_Age << endl;
//}


void test11()
{
	HUMAN<string,int> h1("观观王", 18);
	h1.showHuman();

}

// 为什么改成 HUMAN.cpp 就可以？
// 因为类模板中成员函数只会在调用的时候创建，所以一开始包含HUMAN.h文件不会生成那两个函数，也没有见过。
// 所以在链接阶段就会报错：无法解析的外部命令
// 但如果改成包含 HUMAN.cpp 文件，编译器不仅会看到.h文件内容，也能看到函数实现，所以ok



int main()
{
	test11();

	system("pause");
	return 0;
}