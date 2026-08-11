#include <iostream>
#include <vector>
using namespace std;

// 打印函数
void printVector3(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}







// vector容器的容量大小和操作
void test03()
{
	vector<int> v1;

	for (int i = 0;i < 10;i++)
	{
		v1.push_back(i);
	}

	printVector3(v1);



	// 1. v.empty()		判断是否为空
	if (v1.empty())		// 为 真 代表容器为空
	{
		cout << "容器为空！" << endl;
	}
	else
	{
		cout << "容器不为空！" << endl;
		cout << "v1的容量为：" << v1.capacity() << endl;   // 2. v.capacity()	判断容器 最大容量
		cout << "v1的大小为：" << v1.size() << endl;		  // 3. v.size()	判断 当前容器数据所占大小
	}

	// 4. v.resize()	重新指定容器大小 （超出部分补 0）
	v1.resize(15);
	printVector3(v1);	// 如果重新指定比原来长了，默认用 0 补齐
	//0 1 2 3 4 5 6 7 8 9 0 0 0 0 0
	cout << "v1的容量为：" << v1.capacity() << endl;
	


	// 5. 重载 v.resize(长度，超出部分补的数值)
	v1.resize(20, 100);		// 利用重载版本，可以指定默认填充值
	printVector3(v1);
	//0 1 2 3 4 5 6 7 8 9 0 0 0 0 0 100 100 100 100 100


	// 如果指定短了，那么超出部分删除
	v1.resize(5);
	printVector3(v1);
	cout << v1.size() << endl		// 0 1 2 3 4
		<< v1.capacity() << endl;	// 28 (跟编译器策略有关)

}







int main3()
{
	test03();


	system("pause");
	return 0;
}





