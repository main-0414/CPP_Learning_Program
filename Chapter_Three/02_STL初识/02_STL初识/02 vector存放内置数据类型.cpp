#include <iostream>
using namespace std;

#include <vector>		// 容器头文件
#include <algorithm>	// 算法头文件

// vector存放内置数据类型
// 容器：vector
// 算法：for_each
// 迭代器：vector<int>::iterator

//vector<int>		这代表：	一个存放 int 类型数据的 vector 容器。
//vector<int>::iterator   意思是：vector<int> 这个类里面定义的一种类型，叫 iterator。这里的 :: 是作用域运算符。
//iterator	中文叫 迭代器。你可以暂时理解成：类似指针一样，用来访问容器元素的东西。

void myPrint(int val)
{
	cout << val << endl;
}





void test01()
{
	// 创建了一个vector容器，数组
	vector<int> v;


	// 向容器中插入数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);


	// 通过迭代器访问容器中的数据
	vector<int>::iterator itBegin = v.begin();	// 起始迭代器	指向容器中第一个元素位置
	vector<int>::iterator itEnd = v.end();	// 结束迭代器	指向容器中最后一个元素的下一个位置
	


	// itBegin/itEnd 不是元素的值，也不是数组下标，它本质上是一个“类似指针的对象”，保存了当前元素的位置。
	// 迭代器（iterator）是一种封装后的指针。
	//迭代器 itBegin/itEnd 像一个“智能指针”，它不保存数据本身，而是保存访问数据的位置；加 * 才能拿到数据。




	//// 第一种遍历方式
	//while (itBegin != itEnd)
	//{
	//	cout << *itBegin << endl;
	//	itBegin++;
	//}

	//cout << endl;



	// 第二种遍历方式
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	cout << endl;



	// 第三种遍历方式(利用STL提供的遍历算法)
	for_each(v.begin(), v.end(), myPrint);			// 三个参数 for_each(起始，结束，函数名)


	// 以下是for_each()底层		运用回调函数的技术
	//_EXPORT_STD template <class _InIt, class _Fn>
	//	_CONSTEXPR20 _Fn for_each(_InIt _First, _InIt _Last, _Fn _Func) { // perform function for each element [_First, _Last)
	//	_STD _Adl_verify_range(_First, _Last);
	//	auto _UFirst = _STD _Get_unwrapped(_First);
	//	const auto _ULast = _STD _Get_unwrapped(_Last);
	//	for (; _UFirst != _ULast; ++_UFirst) {
	//		_Func(*_UFirst);
	//	}

	//	return _Func;
	//}



}











int main()
{
	test01();

	system("pause");
	return 0;
}


