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


// count_if(iterator beg, iterator end, _Pred);
// 按条件统计元素出现次数

// beg 开始迭代器
// end 结束迭代器
// _Pred 谓词


// 1. 统计内置数据类型
class greater20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};


void test09()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(31);
	v.push_back(30);
	v.push_back(20);
	v.push_back(10);


	int num = count_if(v.begin(), v.end(), greater20());

	cout << "容器中有 " << num << " 个大于 20 的数" << endl;
}


// 2. 统计自定义数据类型
class juicy
{
public:
	juicy(string name, int age)
	{
		this->name = name;
		this->age = age;
	}


	string name;
	int age;
};



// 谓词
class AgeGreater20
{
public:
	bool operator()(const juicy& j) const
	{
		return j.age > 20;
	}
};



void test10()
{
	vector<juicy> v;

	juicy j1("刘备", 35);
	juicy j2("关羽", 35);
	juicy j3("张飞", 35);
	juicy j4("赵云", 40);
	juicy j5("曹操", 20);



	v.push_back(j1);
	v.push_back(j2);
	v.push_back(j3);
	v.push_back(j4);
	v.push_back(j5);



	// 统计大于20岁的人员个数
	int num = count_if(v.begin(), v.end(), AgeGreater20());

	cout << "大于20的人员个数有：" << num << endl;


}




int main()
{
	test09();
	test10();


	system("Pause");
	return 0;
}