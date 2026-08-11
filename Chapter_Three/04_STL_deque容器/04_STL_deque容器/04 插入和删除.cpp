#include <iostream>
#include <deque>
using namespace std;


void printDeque04(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end() ; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



// deque容器的插入和删除
void test04()
{
	deque<int> d1;

	// 尾插
	d1.push_back(10);
	d1.push_back(20);
	printDeque04(d1);
	//10 20

	// 头插
	d1.push_front(100);
	d1.push_front(200);
	printDeque04(d1);
	// 200 100 10 20

	// 尾删
	d1.pop_back();
	printDeque04(d1);
	// 200 100 10

	// 头删
	d1.pop_front();
	printDeque04(d1);
	// 100 10


cout << endl;
}


void test05()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);

	printDeque04(d1);
	// 200 100 10 20



	// insert插入
	d1.insert(d1.begin(), 1000);
	printDeque04(d1);
	//1000 200 100 10 20


	// insert 插入 重载
	d1.insert(d1.begin(), 2, 9999);
	printDeque04(d1);
	//9999 9999 1000 200 100 10 20



	// 按区间插入
	deque<int> d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);


	d1.insert(d1.begin(), d2.begin(), d2.end());	// 在d1的begin()上插入d2.begin()到d2.end()

	printDeque04(d1);
	//1 2 3 9999 9999 1000 200 100 10 20



cout << endl;
}


void test06()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printDeque04(d1);
	//200 100 10 20


	// 删除
	deque<int>::iterator it = d1.begin();
	it++;	// 迭代器往后偏移一个，那现在指向的是第二个数值（它不是简单地通过地址加减来移动，而是由 deque 的迭代器内部帮你跨越不同缓冲区。）
	d1.erase(it);
	printDeque04(d1);
	//200 10 20


	// erase() 按区间方式删除
	d1.erase(d1.begin(), d1.end());	// 清空
	printDeque04(d1);
	// 空行


	// clear() 清空
	d1.clear();
	printDeque04(d1);
	// 空行


}



int main4()
{
	//test04();
	//test05();
	test06();

	system("pause");
	return 0;
}