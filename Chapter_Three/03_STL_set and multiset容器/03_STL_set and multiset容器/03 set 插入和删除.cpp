#include <iostream>
#include <set>
using namespace std;
#include "printSet.h"

// set 插入和删除

void test04()
{
	set<int> s1;

	// 1. insert 插入数据
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	printSet(s1);

	// 2. erase(迭代器)  删除数据
	s1.erase(s1.begin());	// 把 10 删除了
	printSet(s1);


	// 2.1 erase(数字)	和list容器的remove()一样，删除 容器中(数字)值
	s1.erase(30);
	printSet(s1);


	// 清空
	s1.erase(s1.begin(), s1.end());	// 2.2 erase(迭代器区间)  删除区间范围内数据
	printSet(s1);

	s1.clear();
	printSet(s1);

}



int main3()
{
	test04();


	system("pause");
	return 0;
}