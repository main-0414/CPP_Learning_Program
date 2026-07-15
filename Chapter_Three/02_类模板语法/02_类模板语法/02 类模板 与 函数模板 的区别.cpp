#include <iostream>
#include <string>
using namespace std;


// 类模板 和 函数模板的区别

template<class NameType,class AgeType>
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
		cout << "name：" << this->m_Name << " age：" << this->m_age << endl;
	}
	


	NameType m_Name;
	AgeType m_Age;
};




// 1. 类模板没有自动类型推导使用方式
// 2. 类模板在模板参数列表


void test02()
{
	






}





int main()
{




	system("pause");
	return 0;
}