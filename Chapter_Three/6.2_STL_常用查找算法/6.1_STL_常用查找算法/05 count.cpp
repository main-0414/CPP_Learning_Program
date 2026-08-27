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

// count(iterator beg, iterator end, value);
// 统计元素出现次数

// beg 开始迭代器
// end 结束迭代器
// value 统计的元素


// 1. 统计内置数据类型
void test07()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(40);
	v.push_back(20);
	v.push_back(40);


	int num = count(v.begin(), v.end(), 40);

	cout << "40 的个数：" << num << endl;

}

// 2. 统计自定义数据类型
class Juicy
{
public:
	Juicy(string name,int age)
	{
		this->name = name;
		this->age = age;
	}

	bool operator==(const Juicy& j)
	{
		if (this->age == j.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	string name;
	int age;
};



void test08()
{
	vector<Juicy> v;

	Juicy j1("刘备", 35);
	Juicy j2("关羽", 30);
	Juicy j3("张飞", 35);
	Juicy j4("赵云", 31);
	Juicy j5("曹操", 35);

	Juicy j("诸葛亮", 35);

	v.push_back(j1);
	v.push_back(j2);
	v.push_back(j3);
	v.push_back(j4);
	v.push_back(j5);



	int num = count(v.begin(), v.end(), j);

	cout << "和诸葛亮同岁数的人员个数为：" << num << endl;

}



int main5()
{
	test07();
	test08();

	system("pause");
	return 0;
}