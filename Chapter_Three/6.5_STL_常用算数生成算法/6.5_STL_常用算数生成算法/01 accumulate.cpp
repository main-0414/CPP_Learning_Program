// accumulate			// 计算容器元素累计总和
// fill					// 向容器中添加元素

#include <iostream>
#include <vector>
using namespace std;

#include <numeric>	// 小型算法头文件


// accumulate(iterator beg, iterator end, value);
// 计算容器元素累计总和

// beg 开始迭代器
// end 结束迭代器
// value 起始值



void test01()
{
	vector<int> v;

	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int total = accumulate(v.begin(), v.end(), 0);	// 第三个参数 ————> 累加从什么值开始。

	cout << "total = " << total << endl;

}



int main1()
{
	test01();

	system("pause");
	return 0;
}