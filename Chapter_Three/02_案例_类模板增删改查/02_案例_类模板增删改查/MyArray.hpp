// 自己的通用的数组类
#pragma once
#include <iostream>
using namespace std;


template <class T>
class MyArray
{
public:
	// 有参构造 参数：容量
	MyArray(int capacity)
		:m_Capacity(capacity),
		m_Size(0),
		arrayPoint(new T[m_Capacity])
	{
		//cout << "MyArray有参构造调用！" << endl;
	}



	// 拷贝构造
	MyArray(const MyArray& arr)
		:m_Capacity(arr.m_Capacity), m_Size(arr.m_Size)	// 不能直接浅拷贝数组
	{
		//cout << "MyArray拷贝构造调用！" << endl;
		// 深拷贝，重新在堆区开辟数据
		arrayPoint = new T[arr.m_Capacity];

		// 将arr中的数据都拷贝过来
		for (int i = 0; i < m_Size; i++)
		{
			arrayPoint[i] = arr.arrayPoint[i];
			// 如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
			// 普通类型可以直接= 但是指针类型需要深拷贝
		}

	}



	// operator= 防止浅拷贝问题	要链式编程得返回自身
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray operator=调用！" << endl;


		// 防止 arr1=arr1 自己赋值自己，然后把自己清空的问题
		if (this == &arr)	// 如果 自己地址 == 传入数组地址 那么 返回自己，什么都不做
		{
			return *this;
		}



		// 先判断原来堆区是否有数据，如果有先释放
		if (arrayPoint != nullptr)
		{
			delete[] arrayPoint;
			arrayPoint = nullptr;
			m_Capacity = 0;
			m_Size = 0;
		}

		// 深拷贝
		m_Capacity = arr.m_Capacity;
		m_Size = arr.m_Size;

		arrayPoint = new T[arr.m_Capacity];


		for (int i = 0; i < m_Size; i++)
		{
			arrayPoint[i] = arr.arrayPoint[i];
		}

		return *this;	// 返回自身
	}




	// 析构函数
	~MyArray()
	{
		if (arrayPoint != nullptr)
		{
			//cout << "MyArray析构调用！" << endl;
			delete[] arrayPoint;
			arrayPoint = nullptr;
		}
	}




private:
	T* arrayPoint;	// 指针指向堆区开辟的真实数组

	int m_Capacity;	// 数组最多能放多少个元素

	int m_Size;		// 数组当前已经放了多少个元素

};



