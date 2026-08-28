// set_intersection				// 求两个容器的交集
// set_union					// 求两个容器的并集
// set_difference				// 求两个容器的差集

#include <iostream>
#include <vector>
#include <algorithm>	// 需要的头文件
using namespace std;

// set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

// 求两个集合的差集

// **注意:两个集合必须是有序序列**

// beg1 容器1开始迭代器
// end1 容器1结束迭代器
// beg2 容器2开始迭代器
// end2 容器2结束迭代器
// dest 目标容器开始迭代器


void test03()
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
	// 最特殊的情况：两个集合没有任何公共元素，此时差集就是第一个集合的全部元素。
	vTarget.resize(max(v1.size(), v2.size()));



	// V1 与 V2 的差集：V1 中有而 V2 中没有的元素。
	cout << "V1 与 V2 的差集：";
	
	vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " ";});cout << endl;




	// V2 与 V1 的差集：V2 中有而 V1 中没有的元素。
	cout << "V2 与 V1 的差集：";
	
	itEnd = set_difference(v2.begin(), v2.end(), v1.begin(), v1.end(), vTarget.begin());

	for_each(vTarget.begin(), itEnd, [](int val) {cout << val << " ";});cout << endl;

}




int main()
{
	test03();

	system("pause");
	return 0;
}