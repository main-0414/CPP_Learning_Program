#include <iostream>
#include <set>
using namespace std;

class Person
{
public:
	Person(string name, int age)
		:m_Name(name), 
		m_Age(age)
	{}

	string m_Name;
	int m_Age;
};


// 指定排序规则，用仿函数
class compare
{
public:
	bool operator()(const Person& p1, const Person& p2) const
	{
		// 按照年龄降序
		return p1.m_Age > p2.m_Age;
	}

};



void test10()
{
	// 自定义的数据都会指定排序规则
	set<Person, compare> s;

	// 创建Person对象
	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (set<Person, compare>::iterator it = s.begin();it != s.end();it++)
	{
		cout << "姓名：" << it->m_Name << "  年龄" << it->m_Age << endl;
	}

}



int main()
{
	test10();

	system("pause");
	return 0;
}