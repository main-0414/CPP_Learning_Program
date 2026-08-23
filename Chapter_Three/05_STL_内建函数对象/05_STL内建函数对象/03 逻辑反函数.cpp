// template<class T > bool logical_and<T>			//逻辑与
// `template<class T > bool logical_or<T>			//逻辑或
// template<class T > bool logical_not<T>			//逻辑非

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

// 内建函数对象_逻辑仿函数
// 逻辑非	logical_not

void test04()
{
	vector<bool> v;

	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);

	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;




	// 利用逻辑非 将容器v 搬运到 v2中，并执行取反操作
	vector<bool> v2;
	v2.resize(v.size());	// 必须先扩空间



	// transform  v.  使变形
	transform(v.begin(), v.end(), v2.begin(), logical_not());	// 作用：批量修改容器里的数据，并把结果保存到另一个位置
		// transform( 修改容器起始位置，修改容器结束位置，目标容器起始位置，修改操作(加减乘除取反....) )



	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;


}




int main()
{
	test04();


	system("pause");
	return 0;
}