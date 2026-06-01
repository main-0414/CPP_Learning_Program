#include <iostream>
using namespace std;

class person
{
public:
	person(int age)
	{
		// this指针指向 被调用的成员函数 所属的对象
		// 谁调用this 就指向谁
		this->age = age;

	}

	person& personAddAge(person &p)		// 返回值类型一定是引用，才可以链式
	{
		this->age += p.age;

		return* this;
	}


	int age;


};

// 1.解决名称冲突
void tes01()
{
	person p1(18);
	cout << "p的年龄为：" << p1.age << endl;
}




// 2.返回对象本身用 *this
void tes02()
{
	person p1(10);
	person p2(10);

	// 链式编程思想
	p2.personAddAge(p1).personAddAge(p1).personAddAge(p1);
	cout << "p2的年龄是：" << p2.age << endl;
}




int main2()
{
	//tes01();
	tes02();



	system("pause");
	return 0;
}