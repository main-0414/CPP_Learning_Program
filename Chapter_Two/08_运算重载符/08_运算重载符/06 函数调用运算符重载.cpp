#include <iostream>
using namespace std;

// 函数调用运算符重载（仿函数）


// 打印输出类
class myPrint
{
public:
	// 重载函数调用运算符
	void operator()(string test)
	{
		cout << test << endl;
	}

};

// 正常函数
void myprint2(string test)
{
	cout << test << endl;
}



void te()
{
	myPrint myprint;
	myprint("HelloWorld");	// 使用起来类似函数调用，因此称为仿函数
	myprint2("HelloWorld");
}

// 仿函数非常灵活，没有固定的写法

// 加法类
class myAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}
};


void te2()
{
	myAdd myadd;
	int res = myadd(100, 100);
	cout << "res = " << res << endl;

	// 匿名函数对象
	cout << myAdd()(100, 100) << endl;	// class() 是匿名对象，用完立即释放
}




int main()
{
	te();
	te2();


	system("pause");
	return 0;
}