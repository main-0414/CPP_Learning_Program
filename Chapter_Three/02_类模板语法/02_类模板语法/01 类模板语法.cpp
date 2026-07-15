#include <iostream>
#include <string>
using namespace std;


// 类模板
template<class NameType, class AgeType>

class Person
{
public:
	Person(NameType name, AgeType age)
	{
		m_Name = name;
		m_age = age;
	}

	void showPerson()
	{
		cout << "name：" << this->m_Name << " age：" << this->m_age << endl;
	}



	NameType m_Name;
	AgeType m_age;
};





void test01()
{
	Person<string, int> p1("孙悟空", 999);

	p1.showPerson();

}


// 总结：类模板和函数模板语法极其相似，在声明模板template后面加类，此类成为类模板



int main1()
{
	test01();


	system("pause");
	return 0;
}