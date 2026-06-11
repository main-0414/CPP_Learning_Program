#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// 虚析构和纯虚析构
class Animal_1
{
public:
	Animal_1()
	{
		cout << "Animal构造函数调用" << endl;
	}

	// 利用虚析构可以解决 父类指针释放子类对象时不干净的问题
	virtual ~Animal_1()
	{
		cout << "Animal析构函数调用" << endl;
	}


	// 纯虚析构
	virtual void speak() = 0;
};





class Cat_1 :public Animal_1
{
public:
	
	Cat_1(string name)
	{
		cout << "Cat构造函数调用" << endl;
		m_Name = new string(name);
	}


	void speak()
	{
		cout << *m_Name << "小猫在说话" << endl;
	}


	~Cat_1()
	{
		if (m_Name != nullptr)
		{
			cout << "Cat析构函数调用" << endl;
			delete m_Name;
			m_Name = nullptr;
		}

	}

	string* m_Name;

};






void test0001()
{
	Animal_1* animal = new Cat_1("TOM");
	animal->speak();
	// 父类指针在析构时候(不加virtual时)，不会调用子类中析构函数，
	// 导致子类如果有堆区属性，出现内存泄漏
	delete animal;
}






int main()
{
	test0001();

	system("pause");
	return 0;
}