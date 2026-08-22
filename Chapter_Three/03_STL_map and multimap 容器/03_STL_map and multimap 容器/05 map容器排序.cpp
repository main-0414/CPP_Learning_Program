#include <iostream>
#include <map>
using namespace std;

class myCompare
{
public:
	bool operator()(int v1, int v2) const	//STL容器保存比较器对象时，为了保证比较过程不会修改比较器，通常会以const方式调用它；而const对象只能调用const成员函数，所以仿函数的 operator() 通常必须加 const。
	{
		// 降序
		return v1 > v2;
	}
};


void test06()
{
	map<int, int, myCompare> m;	// 把规则放进来就行

	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	

	for (map<int, int, myCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key：" << it->first << "  value：" << it->second << endl;
	}
	cout << endl;


}

//总结：

// 利用仿函数可以指定map容器的排序规则
// 对于自定义数据类型，map必须要指定排序规则, 同set容器


int main()
{
	test06();

	system("pause");
	return 0;
}