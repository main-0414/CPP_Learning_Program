// copy					// 容器内指定范围的元素拷贝到另一容器中
// replace				// 将容器内指定范围的旧元素修改为新元素
// replace_if			// 容器内指定范围满足条件的元素替换为新元素
// swap					// 互换两个容器的元素

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;


// replace(iterator beg, iterator end, oldvalue, newvalue);
// 将区间内旧元素 替换成 新元素

// beg 开始迭代器
// end 结束迭代器
// oldvalue 旧元素
// newvalue 新元素


void test02()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(10);

	cout << "替换前：";
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});

	replace(v.begin(), v.end(), 10, 1000);

	cout <<endl<< "替换后：";
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});cout << endl;

	// 替换前：10 30 10 40 20 10
	// 替换后：1000 30 1000 40 20 1000


}


int main2()
{
	test02();

	system("pause");
	return 0;
}