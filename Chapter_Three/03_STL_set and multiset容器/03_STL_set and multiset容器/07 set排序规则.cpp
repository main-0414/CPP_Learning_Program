#include <iostream>
#include <set>
using namespace std;
#include "printSet.h"

// 利用仿函数，可以改变排序规则
// 仿函数：一个重载了 operator() 的类对象。
class myCompare
{
public:
	bool operator()(int v1,int v2) const		// 仿函数本质上是一种类型	
	{
		return v1 > v2;	// 降序，前一个数大于后一个数
	}
};





void test09()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(30);
	s1.insert(20);
	s1.insert(50);
	
	printSet(s1);	// 默认升序


	// 指定排序规则从大到小（在创建容器的时候就告诉它排序规则是什么）
	 
	set<int, myCompare> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(30);
	s2.insert(20);
	s2.insert(50);

	for (set<int, myCompare>::iterator it = s2.begin();it != s2.end();it++)	
	{
		cout << *it << " ";
	}
	cout << endl;

}



int main7()
{
	test09();



	system("pause");
	return 0;
}