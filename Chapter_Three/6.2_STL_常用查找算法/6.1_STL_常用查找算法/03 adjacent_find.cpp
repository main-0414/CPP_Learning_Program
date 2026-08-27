// find					//查找元素
// find_if				//按条件查找元素
// adjacent_find		//查找相邻重复元素
// binary_search		//二分查找法
// count				//统计元素个数
// count_if				//按条件统计元素个数

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// adjacent_find(iterator beg, iterator end);
// 查找 相邻重复 元素，返回相邻元素的第一个位置的迭代器

// beg 开始迭代器
// end 结束迭代器


// 常用查找算法 adjacent_find
void test05()
{
	vector<int> v;

	v.push_back(0);
	v.push_back(2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(4);
	v.push_back(3);
	v.push_back(3);		// 3 相邻且重复


	vector<int>::iterator it = adjacent_find(v.begin(), v.end());

	if (it == v.end())
	{
		cout << "未找到相邻重复元素" << endl;
	}
	else
	{
		cout << "找到相邻重复元素：" << *it << endl;
	}


}







int main3()
{
	test05();

	system("pause");
	return 0;
}
