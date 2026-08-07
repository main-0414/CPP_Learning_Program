#include <iostream>
#include <vector>
using namespace std;

// 打印函数
void printVector2(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



// vector 容器的赋值操作
void test02()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector2(v1);


	// 1. =赋值		operator=
	vector<int> v2;
	v2 = v1;
	printVector2(v2);


	// 2. assign区间
	vector<int> v3;
	v3.assign(v1.begin(), v1.end());	// 左闭右开
	printVector2(v3);


	// 3. n个elem方式	构造和赋值都有这种方式
	vector<int> v4;			// 构造
	v4.assign(10, 100);		// 赋值

	//push_back() → 尾部添加
	//assign() → 替换全部内容		如果v4已经有数据，那么assign()后会删除所有数据再新赋值


}







int main2()
{
	test02();


	system("pause");
	return 0;
}