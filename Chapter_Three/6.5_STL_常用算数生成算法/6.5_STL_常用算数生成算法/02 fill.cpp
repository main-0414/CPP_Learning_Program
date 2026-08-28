// accumulate			// 计算容器元素累计总和
// fill					// 向容器中添加元素

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <numeric>	// 小型算法头文件


// fill(iterator beg, iterator end, value);
// 向容器中填充元素

// beg 开始迭代器
// end 结束迭代器
// value 填充的值


void test02()
{
	vector<int> v;

	v.resize(10);	// 现在容器里有 10 个 0
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});cout << endl;
	//0 0 0 0 0 0 0 0 0 0



	// 后期重新填充
	fill(v.begin(), v.end(), 100);	// 无条件地把指定范围内的每一个元素都赋值为第三个参数。

	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});cout << endl;
	//100 100 100 100 100 100 100 100 100 100


	// 清空重新输入数据
	v.clear();
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});cout << endl;
	// 0 1 2 3 4 5 6 7 8 9



	// 再一次填充
	fill(v.begin(), v.end(), 999);	// 无条件地把指定范围内的每一个元素都赋值为第三个参数。




	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});cout << endl;
	//999 999 999 999 999 999 999 999 999 999
}

int main()
{
	test02();

	system("pause");
	return 0;
}