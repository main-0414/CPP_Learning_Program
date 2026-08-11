#include <iostream>
#include <vector>
using namespace std;

// 打印函数
void printVector06(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


void test06()
{
	vector<int> v1;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	cout << "交换前：" << endl;
	printVector06(v1);


	vector<int> v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector06(v2);



	// swap() 交换
	v1.swap(v2);

	cout << "交换后：" << endl;
	printVector06(v1);
	printVector06(v2);

}



// swap 实际用途
// 巧用 swap 可以收缩内存空间
void test07()
{

	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}

	cout << "v 的容量为：" << v.capacity() << endl;
	cout << "v 的大小为：" << v.size() << endl;
	//v 的容量为：138255
	//v 的大小为：100000


	v.resize(3);	// 重新指定大小
	cout << "v 的容量为：" << v.capacity() << endl;	// resize后容量并不会减少，剩下的空间浪费了
	cout << "v 的大小为：" << v.size() << endl;
	//v 的容量为：138255
	//v 的大小为：3



	// 巧用 swap 收缩
	vector<int>(v).swap(v);

	// vector<int>(v) ———— 匿名对象（调用了拷贝构造来创建了一个新的对象）
	// 它会根据 v 当前的 size 来构建容量
	// 
	// .swap(v) ———— 交换容器（本质上交换指针）
	// 匿名容器 和 容器v 交换，于是 v 交换后 size 和 capacity 都为 3
	// 编译器会自动回收匿名对象的空间

	cout << endl << "swap 收缩后：" << endl;
	cout << "v 的容量为：" << v.capacity() << endl;
	cout << "v 的大小为：" << v.size() << endl;
}




int main6()
{
	test06();
	test07();


	system("pause");
	return 0;
}