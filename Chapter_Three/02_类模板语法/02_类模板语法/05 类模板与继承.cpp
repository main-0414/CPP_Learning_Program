#include <iostream>
using namespace std;

// 类模板与继承
template<class T>
class Base
{
public:

	T m;

};


//class Son :public Base		// 错误：必须要知道父类中T的类型，才能继承给子类
class Son:public Base<int>		// 要写<>告诉类型
{
	
};


void test08()
{
	Son s1;		// 没有报错

}





// 如果想灵活指定父类中的数据类型，子类 也需要变 类模板
template<class T1,class T2>
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "T1的类型为：" << typeid(T1).name() << endl;
		cout << "T2的类型为：" << typeid(T2).name() << endl;
	}


	T1 obj;
};


void test09()
{

	Son2<int, char> s2;

}





int main5()
{
	test08();
	test09();


	system("pause");
	return 0;
}