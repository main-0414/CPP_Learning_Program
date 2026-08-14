#include <iostream>
#include <deque>
using namespace std;

// deque查看大小与容量
// deque是没有容量限制的（没有capacity）

void printDeque03(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end() ; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test03()
{
	deque<int> d1;
	
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}

	printDeque03(d1);


	if (d1.empty()==true)
	{
		cout << "d1 为空" << endl;
	}
	else
	{
		cout<< "d1 不为空" << endl;
		cout << "d1 的大小：" << d1.size() << endl;
		// deque容器没有capacity
	}


	// resize() 重新指定大小
	d1.resize(15);	// 比原来长，用0补齐
	printDeque03(d1);


	// resize() 重载，手动输入补齐的值
	d1.resize(20, 999);
	printDeque03(d1);


	// resize() 比原来短，删除多余
	d1.resize(5);
	printDeque03(d1);

}


// 判断是否为空 ———— empty
// 返回元素个数 ———— size
// 重新指定元素个数 ———— resize



int main3()
{
	test03();



	system("pause");
	return 0;
}