#include <iostream>
#include <set>
#include "printSet.h"
using namespace std;

// set和multiset的区别
void test07()
{
	set<int> s;

	pair<set<int>::iterator, bool> ret = s.insert(10);	// set的insert返回的是一个 pair 对组(一组包含两个元素的数据结构)

	if (ret.second)
	{
		cout << "第一次插入成功" << endl;
	}
	else
	{
		cout << "第一次插入失败" << endl;
	}

	ret = s.insert(10);

	if (ret.second)
	{
		cout << "第二次插入成功" << endl;
	}
	else
	{
		cout << "第二次插入失败" << endl;
	}

	// 这就是为什么set没有重复的值，因为它在插入的时候就会返回是否成功的结果
		

	// multiset允许插入重复的值
	multiset<int> ms;
	ms.insert(10);		// multiset返回的是一个迭代器，不会判断是否成功
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	
	for (multiset<int>::iterator it= ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	 
}



int main5()
{
	test07();


	system("pause");
	return 0;
}