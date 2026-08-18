#include <iostream>
#include <set>
using namespace std;
#include "printSet.h"


// set/multiset基本概念
// 所有元素都会在插入时自动被排序
// 本质：属于关联式容器，底层结构是用 二叉树 实现。



// set容器构造和赋值
void test01()
{
	set<int> s1;

	s1.insert(10);	// set插入没有pushback，用insert
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(30);

	// 遍历容器
	// set 容器特点：所有容器插入时候自动背排序
	// set 容器不允许插入重复值
	printSet(s1);	// 10 20 30 40


	// 拷贝构造
	set<int> s2(s1);
	printSet(s2);


	// 赋值
	set<int> s3;
	s3 = s2;
	printSet(s3);
}

//总结：
// set容器插入数据时用insert
// set容器插入数据的数据会自动排序


int main1()
{
	test01();


	system("pause");
	return 0;
}