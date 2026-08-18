#include <iostream>
#include <set>
using namespace std;
#include "printSet.h"

// 因为set不允许有重复值，所以没有resize（resize --> 多出位0补齐）

// set容器 大小和交换

// 大小
void test02()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);


	// 1. empty 判断是否为空
	if (s1.empty())
	{
		cout << "容器为空" << endl;
	}
	else
	{
		cout << "容器不为空！" << endl;
		cout << "容器的元素个数：" << s1.size() << endl;	// 2. size()查看元素个数
	}
	cout << endl;
}


// 交换
void test03()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "交换前：" << endl;
	printSet(s1);
	printSet(s2);


	cout << "交换后：" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);

}



int main2()
{
	test02();
	test03();

	system("Pause");
	return 0;
}