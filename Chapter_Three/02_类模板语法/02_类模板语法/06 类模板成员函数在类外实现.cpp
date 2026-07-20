#include <iostream>
#include <string>
using namespace std;

template <class T1,class T2>
class Human
{
public:
	Human(T1 name, T2 age);
	//	:m_Name(name),m_Age(age)
	//{}


	void showPerson();
	//{
	//	cout << "姓名：" << m_Name << "年龄：" << m_Age << endl;
	//}


	T1 m_Name;
	T2 m_Age;
};


// 构造函数的类内实现
template <class T1,class T2>	// 1.template	2. 作用域	3. 参数列表
Human<T1,T2>::Human(T1 name, T2 age)
	:m_Name(name), m_Age(age)
{
}

// 成员函数的类外实现
template <class T1,class T2>	// 就算这个函数没有用到T1 T2，也要带template告诉编译器这是类模板的成员函数
void Human<T1,T2>::showPerson()
{
	cout << "姓名：" << m_Name << "  年龄：" << m_Age << endl;
}


void test10()
{
	Human h1("观观王",18);

	h1.showPerson();

}




int main()
{
	test10();



	system("pause");
	return 0;
}