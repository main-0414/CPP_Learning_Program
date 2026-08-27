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
#include <functional>
using namespace std;

// bool binary_search(iterator beg, iterator end, value);

// 查找指定的元素，查到 返回true  否则false

// 注意!!! 在**无序序列中不可用**

// beg 开始迭代器
// end 结束迭代器
// value 查找的元素


void test06()
{
	vector<int> v;
	for (int i = 10; i >0; i--)
	{
		v.push_back(i);
	}

	//v.push_back(2);

	// 查找容器中是否有9元素
	// 注意：容器中必须是有序的序列（默认情况下还得是升序）

	bool res = binary_search(v.begin(), v.end(), 9, greater<int>());	// 最后可以搞一个函数对象，使得降序也能查找


	if (res)
	{
		cout << "找到了元素" << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}

}




int main4()
{
	test06();

	system("pause");
	return 0;
}