// 由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于** 双向迭代器**

// vecter、deque迭代器是 随机访问迭代器
// vector、deque 的迭代器不仅支持前移和后移，还支持随机访问。
// list 的迭代器只能前移和后移，不能随机访问。

// list的 优点：
//* 采用动态存储分配，不会造成内存浪费和溢出
//* 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素

// list的 缺点：
//* 链表灵活，但是空间(指针域) 和 时间（遍历）额外耗费较大


// List有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。
// 迭代器失效：假如 it 指向 10，如果这个位置发生变化，it 可能就不能用了，这叫 迭代器失效

// 总结：STL中** List和vector是两个最常被使用的容器** ，各有优缺点


#include <iostream>
#include <list>
using namespace std;

// list的构造函数


// 打印函数
void printList(const list<int>& l)
{
	for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



void test01()
{
	// 创建 list 容器
	list<int> L1;	// 1. 默认构造


	// 添加数据
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	// 遍历容器
	printList(L1);



	// 2. 区间方式构造
	list<int> L2(L1.begin(), L1.end());
	printList(L2);


	// 3. 拷贝构造
	list<int> L3(L2);
	printList(L3);


	// 4. n个elem
	list<int> L4(10, 5000);
	printList(L4);

}



int main()
{
	test01();


	system("pause");
	return 0;
}