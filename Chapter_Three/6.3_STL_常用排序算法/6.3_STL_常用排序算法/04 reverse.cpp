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

// reverse(iterator beg, iterator end);

// 反转指定范围的元素
// beg 开始迭代器
// end 结束迭代器

void myPrint(int val)
{
	cout << val << " ";
}


void test04()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "反转前：" << endl;
	for_each(v.begin(), v.end(), myPrint);cout << endl;


	reverse(v.begin(), v.end());

	cout << "反转后：" << endl;
	for_each(v.begin(), v.end(), myPrint);cout << endl;




}



int main()
{
	test04();

	system("pause");
	return 0;
}