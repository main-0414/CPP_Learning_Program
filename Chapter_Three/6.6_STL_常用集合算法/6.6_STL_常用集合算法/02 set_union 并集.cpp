// set_intersection				// 求两个容器的交集
// set_union					// 求两个容器的并集
// set_difference				// 求两个容器的差集

#include <iostream>
#include <vector>
#include <algorithm>	// 需要的头文件
using namespace std;


// set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

// 求两个集合的并集

// **注意:两个集合必须是有序序列**

// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器


void test02()
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


	// 提前开辟空间
	// 最特殊的情况：两集合一点相交都没有，并集就是两容器size相加
	vTarget.resize(v1.size() + v2.size());

	vector<int>::iterator itEnd = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " ";});cout << endl;


}



int main2()
{
	test02();

	system("pause");
	return 0;
}