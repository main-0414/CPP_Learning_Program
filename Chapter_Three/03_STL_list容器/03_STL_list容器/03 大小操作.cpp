#include <iostream>
#include <list>
#include "printList.h"
using namespace std;

// list容器大小操作
void test04()
{
	list<int> L1;

	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	Print_list(L1);

	// 判断容器是否为空
	// 1. L.empty()	判断是否为空
	if (L1.empty())
	{
		cout << "L1 为空！" << endl;
	}
	else
	{
		cout << "L1 不为空！" << endl;
		cout << "L1的元素个数为：" << L1.size() << endl;		// 2. L1.size()查看容器元素个数
	}


	// 3. 重新指定大小
	L1.resize(10);
	Print_list(L1);	// 如果扩大容器，那么余位默认补 0
	// 10 20 30 40 0 0 0 0 0 0


	L1.resize(3);
	Print_list(L1);	// 如果缩小容器，那么余位删除
	// 10 20 30



	// 3.1 重载，指定补齐的数
	L1.resize(8, 1000);	// 指定1000
	Print_list(L1);	
	// 10 20 30 1000 1000 1000 1000 1000 1000 1000


}


// 总结：
//- 判断是否为空-- - empty
//- 返回元素个数-- - size
//- 重新指定个数-- - resize






int main3()
{
	test04();



	system("pause");
	return 0;
}