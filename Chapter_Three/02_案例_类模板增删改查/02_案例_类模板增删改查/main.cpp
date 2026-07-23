#include <iostream>
using namespace std;

// 实现一个通用的数组类：

// 可以对 内置数据类型 以及 自定义数据类型 的数据进行存储
// 将 数组中的数据 存储到 堆区
// 构造函数 中可以传入 数组的容量
// 提供对应的 拷贝构造函数 以及 operator = 防止浅拷贝问题
// 提供 尾插法 和 尾删法 对数组中的数据进行 增加和删除
// 可以通过 下标的方式 访问 数组中的元素
// 可以 获取 数组中当前 元素个数 和 数组的容量


#include "MyArray.hpp"

void test01()
{
	MyArray <int>arr1(5);
	arr1 = arr1;

	MyArray<int>arr2(arr1);

	MyArray<int>arr3(100);
	arr3 = arr1;
}






int main()
{
	test01();



	system("pause");
	return 0;
}