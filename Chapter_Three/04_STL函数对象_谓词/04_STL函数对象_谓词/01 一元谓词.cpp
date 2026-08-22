// 谓词概念：
// 返回bool类型的仿函数称为 谓词(Pred)
// 如果operator()接收一个参数，那么叫做一元谓词
// 如果operator()接收两个参数，那么叫做二元谓词


#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


// 仿函数 返回值类型是bool数据类型，称为谓词
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}

};


void test01()
{
	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	// 查找容器中 有没有大于5的数字
	// GreaterFive()	匿名函数对象		// 第三个参数：Pred 谓词（函数对象）
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());	// 找到了返回该数迭代器，没找到返回end()迭代器

	if (it == v.end())
	{
		cout << "未找到！" << endl;
	}
	else
	{
		cout << "找到了大于 5 的数字为 " << *it << endl;
	}

}



int main1()
{
	test01();



	system("Pause");
	return 0;
}