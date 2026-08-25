// find					//查找元素
// find_if				//按条件查找元素
// adjacent_find		//查找相邻重复元素
// binary_search		//二分查找法
// count				//统计元素个数
// count_if				//按条件统计元素个数

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


//find(iterator beg, iterator end, value);
// find：查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

// beg 开始迭代器
// end 结束迭代器
// value 查找的元素



// 1. 查找 内置数据类型
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}


	// 查找 容器中是否有 5 这个元素
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it != v.end())
	{
		cout << "找到！" << endl;
	}
	else
	{
		cout << "未找到！" << endl;
	}

}



// 2. 查找自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->age = age;
		this->name = name;
	}

	// 重载 == 让底层find知道如何对比Person数据类型
	bool operator==(const Person& p)
	{
		if (this->age==p.age && this->name==p.name)	// 只要 name 和 age 都一样，就认为它们相等
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	string name;
	int age;

};


void test02()
{
	vector<Person> v;

	// 创建数据
	Person p1("AAA", 10);
	Person p2("BBB", 20);
	Person p3("CCC", 30);
	Person p4("DDD", 40);


	// 插入
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);


	Person ppp("BBB", 20);




	// 接收返回的迭代器
	vector<Person>::iterator it = find(v.begin(), v.end(), ppp);



	if (it == v.end())
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "找到！" << endl 
			<< "姓名：" << it->name 
			<< "  年龄：" << it->age << endl;
	}
}


int main1()
{
	//test01();

	test02();

	system("pause");
	return 0;
}