#include <iostream>
#include <deque>
using namespace std;
// double ended queue（双端队列）

// 可以从头部插入和删除
// 可以从尾部插入和删除
// 支持随机访问（可以 operator[]）
// 底层不是一块连续内存

// deque：
// 不是一整块，是分段数组
// 它采用：中控器 + 多个缓冲区



// deque构造函数

void printDeque(const deque<int>& d)	// 加个 const
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)	// 只读的迭代器
	{
		//*it = 100;	// 只读，不允许修改
		cout << *it << " ";
	}
	cout << endl;
}



void test01()
{
	deque<int> d;	// 无参构造

	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printDeque(d);


	// 区间方式
	deque<int> d2(d.begin(), d.end());
	printDeque(d2);


	// n个elm
	deque<int> d3(10,100);
	printDeque(d3);


	// 拷贝构造
	deque<int> d4(d3);
	printDeque(d4);
}




int main1()
{
	test01();



	system("pause");
	return 0;
}