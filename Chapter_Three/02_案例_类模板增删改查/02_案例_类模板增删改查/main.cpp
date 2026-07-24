#include <iostream>
using namespace std;
#include "MyArray.hpp"

// 实现一个通用的数组类：

// 可以对 内置数据类型 以及 自定义数据类型 的数据进行存储
// 将 数组中的数据 存储到 堆区
// 构造函数 中可以传入 数组的容量
// 提供对应的 拷贝构造函数 以及 operator = 防止浅拷贝问题
// 提供 尾插法 和 尾删法 对数组中的数据进行 增加和删除
// 可以通过 下标的方式 访问 数组中的元素
// 可以 获取 数组中当前 元素个数 和 数组的容量


// 打印函数
void printIntArr(MyArray<int>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << " ";
	}
}



// 测试Int数组
void test01()
{
	MyArray<int> arr1(5);

	for (int i = 0; i < 4; i++)
	{
		arr1.Push_Back(i);	// 利用尾插法向数组中插入数据
	}

	cout << "arr1的打印输出为：" << endl;
	printIntArr(arr1);

	cout << endl << "arr1的容量为：" << arr1.getCapacity() << endl;
	cout << "arr1的容量为：" << arr1.getSize() << endl;


	MyArray<int> arr2(arr1);

	cout << endl << "arr2的打印输出为：" << endl;
	printIntArr(arr2);

	// 尾删
	arr2.Pop_Back();
	cout << endl << "arr2尾删后：" << endl;
	printIntArr(arr2);
	cout << endl << "arr2的容量为：" << arr2.getCapacity() << endl;
	cout << "arr2的容量为：" << arr2.getSize() << endl;


	//MyArray<int>arr3(100);
	//arr3 = arr1;
}







// 测试自定义数据类型
class Person
{
public:
	Person() {}

	Person(string name, int age)
		:m_name(name), m_age(age)
	{
	}

	string m_name;
	int m_age;

};




// 重载 << 操作符
ostream& operator<<(ostream& cout, const Person& p)
{
	cout << "姓名：" << p.m_name << " 年龄：" << p.m_age;

	return cout;
}



//打印 Person 类型数组
void printPersonArr(MyArray<Person>& arr)
{
	for (int i = 0; i < arr.getSize(); i++)
	{
		cout << arr[i] << endl;
	}
}



void test02()
{
	MyArray<Person> arr(100);

	Person p1("孙悟空", 999);
	Person p2("杨戬", 888);
	Person p3("赵云", 30);
	Person p4("妲己", 20);
	Person p5("观观王", 18);

	// 将数据尾插进数组中
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	// 打印数组
	printPersonArr(arr);

	// 打印数组容量
	cout << "arr容量为：" << arr.getCapacity() << endl;

	// 打印数组大小
	cout << "arr大小为：" << arr.getSize() << endl;

}


int main()
{
	test01();
	cout << endl;
	test02();

	system("pause");
	return 0;
}