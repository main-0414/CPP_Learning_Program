// set_intersection				// 求两个容器的交集
// set_union					// 求两个容器的并集
// set_difference				// 求两个容器的差集

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

// 求两个集合的交集

// **注意:两个集合必须是有序序列（默认升序，需要降序还得再写一个pred参数）**

// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器


void test01()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);		// 0-9
		v2.push_back(i + 5);	// 5-14
	}

	// 目标容器
	vector<int> vTarget;

	// 目标容器需要开辟空间
	// 最特殊的情况是：大容器完全包含小容器，那么交集就是小容器
	vTarget.resize(min(v1.size(), v2.size()));

	// 获取交集
	// 它返回的是 目标容器中，最后一个写入元素的下一个位置（end iterator）。
	vector<int>::iterator itEnd = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());


	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " ";});cout << endl;
	// 我们无需把容器中所有元素都遍历出来，只需要遍历交集部分就可以了，所以参数二：itEnd

}




int main1()
{
	test01();

	system("pause");
	return 0;
}