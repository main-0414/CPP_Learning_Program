// push_back(elem);			//在容器尾部加入一个元素
// pop_back();				//删除容器中最后一个元素
// push_front(elem);		//在容器开头插入一个元素
// pop_front();				//从容器开头移除第一个元素
// insert(pos, elem);		//在pos位置插elem元素的拷贝，返回新数据的位置。
// insert(pos, n, elem);	//在pos位置插入n个elem数据，无返回值。
// insert(pos, beg, end);	//在pos位置插入[beg,end)区间的数据，无返回值。
// clear();					//移除容器的所有数据
// erase(beg, end);			//删除[beg,end)区间的数据，返回下一个数据的位置。
// erase(pos);				//删除pos位置的数据，返回下一个数据的位置。
// remove(elem);			//删除容器中所有与elem值匹配的元素。

#include <iostream>
#include <list>
#include "printList.h"
using namespace std;


void test05()
{
	list<int> L1;

	// 1. 尾插
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);


	// 2. 头插
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);


	Print_list(L1);
	// 300 200 100 10 20 30



	// 3. 尾删
	L1.pop_back();

	Print_list(L1);	// 300 200 100 10 20
	

	// 4. 头删
	L1.pop_front();

	Print_list(L1);	// 200 100 10 20


	// 5. insert 插入
	L1.insert(L1.begin(), 1000);

	Print_list(L1);	// 1000 200 100 10 20

	// 5.1 insert 插入别处
	list<int>::iterator it = L1.end();
	L1.insert(--it, 123);
	Print_list(L1);	// 1000 200 100 10 123 20



	// 6. erase 删除
	it = L1.begin();
	++it;
	L1.erase(it);
	Print_list(L1);
	// 1000 100 10 123 20



	// 7. remove 移除
	L1.push_back(10000);
	it = L1.begin();
	++++it;
	L1.insert(++it, 10000);	// 一共三次自增
	Print_list(L1);
	// 1000 100 10 10000 123 20 10000

	
	L1.remove(10000);	// remove(数字)，不用提供迭代器，目的删除容器中所有与(数字)匹配的值
	Print_list(L1);
	// 1000 100 10 123 20	所有 10000 消失




	// 8. 清空
	L1.clear();
	Print_list(L1);
	// 空行

}







int main4()
{
	test05();

	system("pause");
	return 0;
}