#include <iostream>
#include <string>
using namespace std;


// 类模板 和 函数模板的区别

template<class NameType, class AgeType = int>		// 尖括号里面的是模板参数列表
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		m_Name = name;
		m_Age = age;
	}

	void showPerson()
	{
		cout << "name：" << this->m_Name << " age：" << this->m_Age << endl;
	}



	NameType m_Name;
	AgeType m_Age;
};




// 1. 类模板没有自动类型推导使用方式(新版本可以)
void test02()
{
	Person p1("孙悟空", 1000);
	p1.showPerson();		// 实则新版本可以

	Person<string, int> p2("观观王", 10000);
	p2.showPerson();


}


// 2. 类模板在模板参数列表
void test03()
{
	Person<string> p("猪八戒", 9999);		// 我只指定了第一个，第二个是使用了默认参数的类型
	p.showPerson();









}



int main()
{
	test02();
	test03();


	system("pause");
	return 0;
}