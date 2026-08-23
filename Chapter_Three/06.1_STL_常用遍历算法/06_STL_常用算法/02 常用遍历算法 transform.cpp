// transform(iterator beg1, iterator end1, iterator beg2, _func);

//beg1 源容器开始迭代器
//end1 源容器结束迭代器
//beg2 目标容器开始迭代器
//_func 函数或者函数对象


#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

// 仿函数
class Transform
{
public:
	int operator()(int val)	// 先取到，逻辑运算后返回
	{
		return val + 100;	// 灵活，如果想要原封不动搬运就直接返回，如果在过程中想有一些不同，允许操作
	}
};

// 普通函数
int TransformFunc(int val)
{
	return val + 100;
}



class print
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};



void test02()
{
	vector<int> v;	// 原容器

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> vTarget;	// 目标容器
	vTarget.resize(10);		// 目标容器需要提前开辟空间

	//transform(v.begin(), v.end(), vTarget.begin(), Transform());
	//transform(v.begin(), v.end(), vTarget.begin(), TransformFunc);
	transform(v.begin(), 
		v.end(), 
		vTarget.begin(), 
		[](int val)
		{
			return val + 100;
		}
		);

	for_each(vTarget.begin(), vTarget.end(),print());

	cout << endl;

}





int main()
{
	test02();

	system("pause");
	return 0;
}