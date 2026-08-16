// list没有 at 方式 和 [] 方式


//* front();        //返回第一个元素。
//* back();         //返回最后一个元素。
#include <iostream>
#include "printList.h"
#include <list>
using namespace std;


void test06()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// L1[0];	//没有与这些操作数匹配的 "[]" 运算符

	//L1.at(0);	//类 "std::list<int, std::allocator<int>>" 没有成员 "at"

	// 原因是list本质链表，不是用连续线性空间存储数据，迭代器也是不支持随机访问的

	cout << "第一个元素：" << L1.front() << endl;
	cout << "最后一个元素：" << L1.back() << endl;

	// 验证迭代器是不支持随机访问的
	list<int>::iterator it = L1.begin();
	// it++;	// 支持双向，移动一个节点（允许）
	// it = it + 1;	// 让迭代器直接跳跃一个位置（不允许）所以不支持随机访问

}

//总结：
// list容器中不可以通过 [] 或者 at 方式访问数据
// 返回第一个元素-- - front
// 返回最后一个元素-- - back


int main5()
{
	test06();

	system("Pause");
	return 0;
}