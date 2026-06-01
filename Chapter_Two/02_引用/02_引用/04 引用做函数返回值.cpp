#include <iostream>
using namespace std;

// 引用做函数返回值
// 1.不要返回局部变量的引用
int& test01()		// 返回的数据类型是一个引用变量
{
	int a = 10;		// 局部变量存在内存四区中的 栈区
	return a;		// 返回局部变量的引用 → 悬空引用
}



// 2.函数的调用可以作为左值
int& test02()
{
	static int a = 10;	//用静态变量存储在全局区，全局区的数据在程序结束后由系统释放
	return a;
}


int main7()
{
	int& ref = test01();
	
	cout << "ref=" << ref << endl;	// 乱码


	int& ref2 = test02();
	cout << "ref2=" << ref2 << endl;


	test02() = 1000;  // 如果函数返回值是引用，那这个函数可以调用可以作为 左值 进行继续赋值
	// test02()返回的是a的本身，所以这是一个赋值操作a=1000
		
	cout << "ref2=" << ref2 << endl;	// ref2是a的别名，用的是别名来访问这块内存，ref2——>a=1000



	system("pause");
	return 0;
}