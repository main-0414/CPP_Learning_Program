// sort					// 对容器内元素进行排序
// shuffle				// 洗牌   指定范围内的元素随机调整次序
// merge				// 容器元素合并，并存储到另一容器中
// reverse				// 反转指定范围的元素


#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <random>
using namespace std;

// merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);
// 容器元素合并，并存储到另一容器中

// 注意: 两个容器必须是**有序的且同个顺序**

// beg1   容器1开始迭代器
// end1   容器1结束迭代器
// beg2   容器2开始迭代器
// end2   容器2结束迭代器
// dest    目标容器开始迭代器


void Myprint(int val)
{
	cout << val << " ";
}



void test03()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);	// 两个容器都是有序的
	}

	// 目标容器
	vector<int>vTarget;

	vTarget.resize(v1.size() + v2.size());	// 分配内存

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());


	for_each(vTarget.begin(), vTarget.end(), Myprint);
	// 0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10 

}






int main3()
{
	test03();

	system("pause");
	return 0;
}