#include <iostream>
using namespace std;

// 构造函数的分类及调用

// 分类
// 按照参数分类：	有参构造 和 无参构造（默认构造）
// 按照类型分类：	普通构造 和 拷贝构造

class person
{
public:
	// 构造函数
	person()
	{
		cout << "无参构造(默认构造)函数的调用" << endl;
	}

	// 有参构造
	person(int a)
	{
		m_age = a;
		cout << "有参构造函数的调用" << endl;
	}

	// 拷贝构造函数（也是有参）：用一个已经存在的 Person 对象，来创建一个新的 Person 对象。
	person(const person &p)		// const限定不可更改 + 引用
	{
		m_age = p.m_age;	// p 是 “已经存在的人”（传入的对象）
		// 将传入的对象身上的age属性，拷贝到新的Person对象上

		cout << "拷贝构造函数的调用" << endl;
	}

	int m_age;


	~person()
	{
		cout << "析构函数的调用" << endl;
	}

};

// 调用
void test1()
{
	// 1.括号法
	person p1;	// 默认构造函数调用
	person p2(10);	// 有参构造函数调用
	person p3(p2);	// 拷贝构造函数调用

	cout << "p2的年龄为：" << p2.m_age << endl;
	cout << "p3的年龄为：" << p2.m_age << endl;	// 拷贝了传入对象p2的数据给了新的p3


		// 注意事项 1
		// 调用默认构造函数的时候，不要加()
		// 因为下面这行代码，编译器会认为这是一个函数的声明，不会认为在创建对象
	person ppp();
	void func();


	cout << endl;


	// 2.显示法
	person pp1;
	person pp2 = person(100);	// 有参构造
	person pp3 = person(p3);	// 拷贝构造

	cout << endl;
	person(100);	// 等号右边的叫做 匿名对象(临时对象)：当前行结束后，系统会立即回收掉匿名对象
					// 创建一个没名字的对象，然后告诉它名字是什么（左边）
	cout << "aaa" << endl;	// 运行可以发现调用完马上就释放，因为没有名字所以马上就析构

		// 注意事项 2
		// 不要利用拷贝构造函数 初始化匿名对象
	//person(p3);	// 报错：重定义 ————> 编译器会把 person(p3) 当成 person p3; 对象声明
									// 创建一个 p3 对象，但是p3已经有了就报错了
	


	cout << endl;



	// 3.隐式转换法
	person ppp1 = 10;	// 相当于写了：person ppp1 = person(10); 或 person ppp1(10);
	person ppp2 = p2;

}


int main2()
{
	test1();
	system("pause");
	return 0;
}