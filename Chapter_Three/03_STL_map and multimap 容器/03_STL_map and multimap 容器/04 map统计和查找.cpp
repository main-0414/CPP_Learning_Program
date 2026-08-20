// find(key);		//查找key是否存在，若存在，返回该键的元素的迭代器；若不存在，返回set.end();
// count(key);		//统计key的元素个数


#include <iostream>
#include <map>
using namespace std;



void test05()
{
	map<int, int> m;

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(3, 30));

	map<int, int>::iterator pos = m.find(3);	// find返回的是一个迭代器！！！！！！

	if (pos != m.end())
	{
		cout << "查到了元素  key = " << pos->first << "  value = " << pos->second << endl;
	}
	else
	{
		cout << "未查找到元素！" << endl;
	}


	// count统计
	int num = m.count(3);
	cout << "num = " << num << endl;	// 对于map容器来说，结果要么是 1 要么买是0
	// map不允许插入重复的key元素
	// multimap结果可能大于 1

}

// 总结：
// 查找-- - find    （返回的是迭代器）
// 统计-- - count  （对于map，结果为0或者1）



int main4()
{
	test05();

	system("pause");
	return 0;
}