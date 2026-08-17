#include <iostream>
#include <list>
#include "printList.h"
//#include <algorithm>
using namespace std;

// list容器反转和排序
void test07()
{
	list<int> L1;
	L1.push_back(30);
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(40);

	cout << "反转前：" << endl;
	Print_list(L1);

	// 1. 反转
	cout << "反转后：" << endl;
	L1.reverse();	// vector里面有个v.reserve()	预留空间

	Print_list(L1);

}


// 改变排序规则
bool myCompare(int v1, int v2)
{
	// 我要降序	就让 第一个数 > 第二个数
	return v1 > v2;
}


// 排序
void test08()
{
	list<int> L1;
	L1.push_back(30);
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(40);

	// 2. 排序
	cout << "排序前：" << endl;
	Print_list(L1);

	// 所有不支持随机访问迭代器的容器，不可以用标准算法
	// 不支持随机访问迭代器的容器，内部会提供对应的一些算法
	
	//sort(L1.begin(), L1.end());
	L1.sort();		// 默认规则，由小到大 升序

	cout << "排序后：" << endl;
	Print_list(L1);

	// 更改降序规则
	L1.sort(myCompare);
	Print_list(L1);

}



int main()
{
	test07();
	test08();

	system("pause");
	return 0;
}