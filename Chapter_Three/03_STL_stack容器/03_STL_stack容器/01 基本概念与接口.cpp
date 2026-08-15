// stack (栈) 基本概念
// stack是一种"先进后出"的数据结构，只有一个出口
// stack 不允许随机访问，只能操作栈顶元素。(不允许遍历行为)

// 存数据 ———— push (入栈)
// 取数据 ———— pop  (出栈)

#include <iostream>
#include <stack>
using namespace std;

void test01()
{
	// 特点：符合先进后出的数据结构
	stack<int> s;


	// 入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);


	// 查看大小
	cout << "栈的大小" << s.size() << endl;



	// 只要栈不为空，我们就查看栈顶，并执行出栈
	while (!s.empty())
	{
		// 查看栈顶元素
		cout << "查看栈顶元素：" << s.top() << endl;

		// 出栈
		s.pop();
	}

	// 查看大小
	cout << "栈的大小" << s.size() << endl;
}


// 总结：
// 入栈 ———— push
// 出栈 ———— pop
// 返回栈顶 ———— top
// 判断栈是否为空 ———— empty
// 返回栈大小 ———— size


int main()
{
	test01();



	system("pause");
	return 0;
}