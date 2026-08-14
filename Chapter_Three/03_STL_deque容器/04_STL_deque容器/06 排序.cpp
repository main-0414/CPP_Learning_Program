#include <iostream>
#include <deque>
#include <algorithm>	// 标准算法头文件
using namespace std;

void printDeque06(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



// deque容器排序
void test08()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);
	printDeque06(d1);
	// 300 200 100 10 20 30

	// 排序(升序)
	sort(d1.begin(), d1.end());	// 要头文件
	// 对于支持随机访问的迭代器容器，都可以利用sort算法直接对其进行排序（vector也可以）
	cout << "排序后：" << endl;
	printDeque06(d1);

}





int main()
{
	test08();


	system("pause");
	return 0;
}