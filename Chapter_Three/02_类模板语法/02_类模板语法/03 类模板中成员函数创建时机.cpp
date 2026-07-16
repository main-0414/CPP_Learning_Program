#include <iostream>
using namespace std;

// 类模板中成员函数创建时机：
// 类模板中成员函数 在调用时 才创建

class PERSON1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};


class PERSON2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};



template<class T>
class myClass
{
public:

	T obj;
	
	// 类模板中的成员函数
	void func1()
	{
		obj.showPerson1();	// obj是个不知道类型的对象
	}

	void func2()
	{
		obj.showPerson2();
	}

	// 但此时直接编译却可以成功，因为类模板中成员函数一开始不会创建，只有你调用它才会创建
};




void test04()
{
	myClass<PERSON1> M;
	M.func1();
	//M.func2();	// 因为指定了obj的类型为person1，而person1没有func2()，所以不能成功运行

}



int main3()
{
	test04();


	system("pause");
	return 0;
}