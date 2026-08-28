// copy					// 容器内指定范围的元素拷贝到另一容器中
// replace				// 将容器内指定范围的旧元素修改为新元素
// replace_if			// 容器内指定范围满足条件的元素替换为新元素
// swap					// 互换两个容器的元素

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;


// replace_if(iterator beg, iterator end, _pred, newvalue);
// 按条件替换元素，满足条件的替换成指定元素

// beg 开始迭代器
// end 结束迭代器
// _pred 谓词
// newvalue 替换的新元素



class MyRule
{
public:
	bool operator()(int val)
	{
		return val > 30;	// val > 30 这个表达式本身的结果就是 bool 类型。
	}
};



void test03()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(60);

	cout << "替换前：";
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});cout << endl;


	cout << "替换后：";

	// 将 >30 的数更改为 3000
	replace_if(v.begin(), v.end(), MyRule{}, 3000);


	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});cout << endl;
}






int main3()
{
	test03();

	system("pause");
	return 0;
}