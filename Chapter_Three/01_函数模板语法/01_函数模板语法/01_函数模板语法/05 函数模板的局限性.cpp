#include <iostream>
#include <string>
using namespace std;

// 函数模板的局限性
// 模板并不是万能的，有些特定数据类型，需要用具体化方式做特殊实现

class Person
{
public:
	
	Person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}

	string name;

	int age;

};



// 对比两个数是否相等的函数
template<class T>
bool myCompare(T &a,T &b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}



// 利用具体化的Person版本实现代码，具体优先调用
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.age==p2.age and p1.name==p2.name)
	{
		return true;
	}
	else
	{
		return false;
	}
}



void test06()
{
	int a = 10;
	int b = 20;

	bool result = myCompare(a, b);

	if (result)
	{
		cout << "a==b" << endl;
	}
	else
	{
		cout << "a!=b" << endl;
	}
}


void test07()
{
	Person p1("Tom", 10);
	Person p2("Tom", 11);

	bool result = myCompare(p1, p2);

	if (result)
	{
		cout << "p1==p2" << endl;
	}
	else
	{
		cout << "p1!=p2" << endl;
	}

}



// 总结：
// 利用具体化的模板，可以解决自定义类型的通用化
// 学习模板不是为了写模板，而是在STL能够运用系统提供的模板






int main()
{
	//test06();
	test07();

	system("pause");
	return 0;
}