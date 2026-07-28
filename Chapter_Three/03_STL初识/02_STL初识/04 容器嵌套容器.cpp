#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

// 容器嵌套容器
void test04()
{
	vector<vector<int>> v; // 里面的vector不是一个变量，而是一个“类型”
	// 里面 vector<int>：一个存 int 的小容器
	// 外面的 vector：一个存 vector<int> 类型数据的大容器

	// 创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	// 向小容器里添加数据
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);	// 从 1 开始累加
		v2.push_back(i + 2);	// 从 2 开始累加
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}


	// 将小容器插入大容器中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);


	// 通过大容器把所有数据遍历
	// 因为 v 里面存的是 vector<int>，所以 it 指向的是 一个小vector的位置
	for (vector< vector<int> >::iterator it = v.begin(); it != v.end(); it++)
	{
		// 此时 (*it) 外层迭代器解引用以后，拿到的是一个 小容器 vector<int> 。
		// 所以还需要做一次for循环才能拿到小容器里面的数字
		for (vector<int>::iterator vit = (*it).begin(); vit < (*it).end(); vit++)
		{
			cout << *vit << " ";
		}

		cout << endl;
	}


}













int main()
{
	test04();






	system("pause");
	return 0;
}