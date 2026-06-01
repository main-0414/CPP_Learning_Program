#include <iostream>
using namespace std;

// 深拷贝与浅拷贝

// 浅拷贝：直接把原对象指针成员的 值+地址 拷贝过来。
	// 共享同一块堆内存，析构时重复释放，程序挂掉

// 深拷贝（自定义拷贝操作）:
	// 重新在堆区申请内存，把原对象堆区数据复制一份。(杜绝重复释放的问题）


// 如果使用编译器提供的拷贝函数，会做浅拷贝操作（拷贝的内存地址相同，会导致堆区的内存重复释放）


class pe
{
public:
	//pe() { cout << "默认构造函数调用" << endl; }	// 写了有参构造就得自己写默认构造，不过没用到 pe p; 就不会触发错误

	pe(int age, int height)		// 创建时直接传值进来
	{
		cout << "有参构造函数调用" << endl;
		m_age = age;
		m_height = new int(height);
	}

	pe(const pe& p)
	{
		cout << "拷贝函数调用" << endl;
		m_age = p.m_age;
		//m_height = p.m_height;	// 编译器写的

		// 自己搞深拷贝
		m_height = new int(*p.m_height);
	}


	~pe()
	{
		// 析构代码，在堆区开辟数据做释放
		if (m_height != NULL)
		{
			delete m_height;
			m_height = NULL;	// 防止野指针出现，置空操作
		}
		cout << "析构函数的调用" << endl;
	}



	int m_age;		// m_age 单纯存值，浅拷贝ok
	int* m_height;	// m_height 是指针！！！所以只能深拷贝
};

void te()
{
	pe p1(18, 180);
	cout << "p1的年龄为：" << p1.m_age << " 身高为：" << *p1.m_height << endl;

	pe p2(p1);
	cout << "p2的年龄为：" << p2.m_age << "  身高为：" << *p2.m_height << endl;
}



int main()
{
	te();

	system("pause");
	return 0;
}