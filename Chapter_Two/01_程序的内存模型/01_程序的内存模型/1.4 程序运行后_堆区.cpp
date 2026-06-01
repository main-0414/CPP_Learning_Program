#include <iostream>
using namespace std;

int* func()
{
	// 利用new关键字 可以将数据开辟在堆区
	// 语法：new 数据类型(数据);		返回的是一个地址，所以要用指针接收

	// 这里的指针本质上也是一个局部变量，放在栈上；但是指针保存的数据放在了堆区

	// 只是把堆区某数据的地址编号用栈上的指针存起来了
	int* p = new int(100);
	return p;
}


int main4()
{
	// 在堆区开辟数据，堆区的数据是由程序员开辟和释放

	int* p = func();

	cout << *p << endl;		// 解引用的时候拿到的是堆区地址编号的数据
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	// 堆区的数据怎么释放？关闭程序 or 代码关键字

	system("Pause");
	return 0;
}