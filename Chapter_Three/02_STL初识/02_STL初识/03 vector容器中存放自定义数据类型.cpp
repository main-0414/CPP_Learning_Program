#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

// vector容器中存放自定义数据类型
class Person
{
public:
	Person(string name, int age)
		:m_Name(name), m_Age(age) {
	}

	string m_Name;
	int m_Age;
};

void test02()
{
	vector<Person> v;

	Person p1("aaa", 50);
	Person p2("bbb", 40);
	Person p3("ccc", 30);
	Person p4("ddd", 20);
	Person p5("eee", 10);

	// 向容器中添加数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);


	// 便利容器中的数据
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		// <>里面是什么类型，(*it)解出来的就是什么类型，要属性直接 . 出来
		// 可以把it看成一个指针，那么可以用 -> 来指向属性

		//cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl;
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl;
	}

}


// 存放自定义数据类型的 指针
void test03()
{
	vector<Person*> v;		// 这里类型是 Person* ，相当于保存了p1等对象的地址

	Person p1("aaa", 50);
	Person p2("bbb", 40);
	Person p3("ccc", 30);
	Person p4("ddd", 20);
	Person p5("eee", 10);

	// 向容器中添加数据
	v.push_back(&p1);	// 因为容器中存放的是地址，所以对象要加 & 取址符
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// 遍历容器
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 此时 it 是一个 Person* 的指针（二级指针），那么 (*it) 解引用后出来的是一个指针
		cout << "存放对象指针的容器 姓名：" << (*it)->m_Name << " 年龄：" << (*it)->m_Age << endl;
	}


}




int main()
{
	//test02();
	test03();


	system("pause");
	return 0;
}