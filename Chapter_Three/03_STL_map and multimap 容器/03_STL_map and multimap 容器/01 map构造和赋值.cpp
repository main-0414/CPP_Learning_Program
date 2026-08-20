// 概念：
// map 中所有元素都是pair
// pair中第一个元素为key（键值），起到索引作用，第二个元素为value（实值）
// 所有元素都会根据元素的key值自动排序

// 本质：
// map / multimap属于 关联式容器 ，底层结构是用二叉树实现。（set 和 multiset也是）

// 优点：
// 可以根据key值快速找到value值


// map和multimap 区别 ：
// map不允许容器中有重复key值元素
// multimap允许容器中有重复key值元素


#include <iostream>
#include <map>
using namespace std;
#include "printMap.h"


void test01()
{
	// 创建map容器
	map<int, int> m;

	m.insert(pair<int, int>(1, 10));	//“pair<int, int>(1, 10)”这个匿名的对组直接放进容器内
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(4, 40));

	printMap(m);
	//key：1  value：10
	//key：2  value：20
	//key：3  value：30
	//key：4  value：40 
	// 会根据key值自动排序


	// 拷贝构造
	map<int, int> m2(m);
	printMap(m2);


	// operator= 赋值
	map<int, int> m3;
	m3 = m2;
	printMap(m3);
}




int main1()
{
	test01();


	system("pause");
	return 0;
}