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
using namespace std;


// find_if(iterator beg, iterator end, _Pred);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

// beg 开始迭代器
// end 结束迭代器
// _Pred 函数或者谓词（返回bool类型的仿函数）


// 1. 查找内置数据类型
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};


void test03()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}


	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());

	if (it == v.end())
	{
		cout << "没有找到！" << endl;
	}
	else
	{
		cout << "找到大于 5 的数为：" << *it << endl;
	}

}



// 2. 查找自定义数据类型
class person
{
public:
	person(string name, int age)
	{
		this->age = age;
		this->name = name;
	}

	string name;
	int age;
};

class Greater20
{
public:
	bool operator()(const person& p)
	{
		return p.age > 20;
	}
};



void test04()
{
	vector<person> v;

	person p1("AAA", 55);
	person p2("BBB", 19);
	person p3("CCC", 30);
	person p4("DDD", 5);
	person p5("EEE", 80);
	person p6("FFF", 5);


	// 插入
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	v.push_back(p6);


	// 年龄大于 20 的人

	//vector<person>::iterator it = find_if(v.begin(), v.end(), Greater20());

	// 打印所有>20岁的人：
	vector<person>::iterator it = v.begin();

	while (true)
	{
		it = find_if(it, v.end(), Greater20());

		if (it == v.end())
		{
			break;
		}
		else
		{
			cout << "姓名：" << it->name
				<< "  年龄：" << it->age << endl;
		}

		it++;
	}

}



int main2()
{
	//test03();
	test04();

	system("pause");
	return 0;
}