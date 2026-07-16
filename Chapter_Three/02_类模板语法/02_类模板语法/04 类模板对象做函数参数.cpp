#include <iostream>
using namespace std;

// 类模板对象 做 函数参数
template<class T1, class T2>
class person
{
public:

	person(T1 name, T2 age)
	{
		this->m_Age = age;
		this->m_Name = name;
	}

	void showPerson()
	{
		cout << "name：" << this->m_Name << " age：" << this->m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};



// 1. 指定传入的类型（最常用）
void printPerson1(person<string, int>& p)
{
	p.showPerson();		// 目的：类模板的对象 做 函数中的参数 怎么传

}

void test05()
{
	person<string, int> p("孙悟空", 100);

	printPerson1(p);
	cout << endl;
}



// 后面两种算是函数模板配合类模板了，少用
// 2. 参数模板化
template<class T1, class T2>
void printPerson2(person<T1, T2>& p)	// 本质模板函数，具体的类型自动推导
{
	p.showPerson();
	cout << "T1的类型为：" << typeid(T1).name() << endl;
	cout << "T2的类型为：" << typeid(T2).name() << endl;
}


void test06()
{
	person<string, int> p("猪八戒", 90);

	printPerson2(p);
	cout << endl;
}





// 3. 整个类模板化
template<class T>
void printPerson3(T &p)		// 具体的类型自动推导
{
	p.showPerson();
	cout << typeid(T).name() << endl;
}


void test07()
{
	person<string, int> p("沙僧", 900);

	printPerson3(p);
	cout << endl;
}






int main4()
{
	cout << "" << endl; // 或 cout << "输出内容" << endl;

	test05();
	test06();
	test07();

	system("pause");
	return 0;
}