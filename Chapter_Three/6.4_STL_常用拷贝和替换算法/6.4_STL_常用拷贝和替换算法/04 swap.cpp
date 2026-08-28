// copy					// 容器内指定范围的元素拷贝到另一容器中
// replace				// 将容器内指定范围的旧元素修改为新元素
// replace_if			// 容器内指定范围满足条件的元素替换为新元素
// swap					// 互换两个容器的元素

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

// swap(container c1, container c2);
// 互换两个容器的元素（同种类型的容器）

// c1容器1
// c2容器2

void test04()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 100);
	}

	cout << "交换前：" << endl;

	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " ";});cout << endl;
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " ";});cout << endl;


	cout << "---------------------" << endl;


	swap(v1, v2);	// 只要传进容器就行，不用迭代器


	cout << "交换后：" << endl;

	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " ";});cout << endl;
	for_each(v2.begin(), v2.end(), [](int val) {cout << val << " ";});cout << endl;
}




int main()
{
	test04();

	system("pause");
	return 0;
}