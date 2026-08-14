#include <iostream>
#include <deque>
using namespace std;

// 打印函数
void printDeque02(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


// deque 赋值操作
void test02()
{
	deque<int> d;
	for (int i = 0; i < 10; i++)
	{
		d.push_back(i);
	}
	printDeque02(d);

	// 1. operator= 等号赋值
	deque<int> d2;
	d2 = d;
	printDeque02(d2);


	// 2. assign区间 
	deque<int> d3;
	d3.assign(d.begin(), d.end());
	printDeque02(d3);


	// 3. assign  n个elem方式
	deque<int> d4;
	d4.assign(5, 100);
	printDeque02(d4);


}





int main2()
{
	test02();


	system("pause");
	return 0;
}