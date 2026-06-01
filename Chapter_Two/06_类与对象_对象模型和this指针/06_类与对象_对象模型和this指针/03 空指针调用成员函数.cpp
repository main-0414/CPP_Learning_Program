#include <iostream>
using namespace std;

// 空指针调用成员函数

class pers
{
public:
	void showClassName()
	{
		cout << "this is person class." << endl;
	}

	void showPersonAge()
	{
		// 预防传入一个空指针
		if (this == NULL)
		{
			return;
		}

					// 这里 m_Age 其实是 this->m_Age
		cout << "age=" << m_Age << endl;	// 没有一个确定的对象怎么调用属性？

	}




	int m_Age;
};

void TEST01()
{
	pers* p = NULL;

	p->showClassName();	// 不报错，空指针是可以调用成员的
	p->showPersonAge();	// 报错：传入指针为空



}


int main3()
{
	TEST01();



	system("pause");
	return 0;
}