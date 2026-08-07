#include <iostream>
#include <vector>
using namespace std;

// vector基本概念
// 功能：vector数据结构和数组非常相似，也成为单端数组
// vector容器的迭代器是支持随机访问的迭代器

// vector与普通数组的区别：
// 不同之处在于数组是静态空间，而vector可以动态扩展

// 动态扩展：
// 并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间



// 写一个打印函数方便测试打印
void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}






// vector 的构造
void test01()
{
	vector<int> v1;	// 默认构造 无参构造

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);	// 0 - 9
	}

	printVector(v1);



	// 通过区间的方式进行构造
	vector<int> v2(v1.begin(), v1.end());		// 左闭右开 ———— begin()指向第一个数，end()指向最后一个数的的后一个
	printVector(v2);


	// n个elem方式构造
	vector<int> v3(10, 100);	// v(个数，值)
	printVector(v3);


	// 拷贝构造
	vector<int> v4(v3);
	printVector(v4);
}






int main1()
{
	test01();



	system("Pause");
	return 0;
}