// find(key);                 //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
// count(key);                //统计key的元素个数


#include <iostream>
#include <set>
#include "printSet.h"
using namespace std;

// set 容器 查找和统计

// 查找
void test05()
{
	
	set<int> s1;

	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(10);

	// 查找
	set<int>::iterator pos = s1.find(30);	// 查到了会返回一个迭代器
	
	//*pos = 100;	// 不能更改。因为 set 会自动排序，如果允许更改，树结构会乱。所以 set 的迭代器实际上类似：const_iterator
	

	if (pos != s1.end())
	{
		cout << "找到元素：" << *pos << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

}


// 统计
void test06()
{
	set<int> s1;

	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(30);
	s1.insert(30);
	s1.insert(10);

	int num = s1.count(30);	// 统计30的个数

	cout << "num = " << num << endl;	
	// set容器每个元素只允许有一个，所以实际上结果只有1 or 0


}







int main4()
{
	test05();
	test06();


	system("pause");
	return 0;
}