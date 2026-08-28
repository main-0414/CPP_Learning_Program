// sort					// 对容器内元素进行排序
// shuffle				// 洗牌   指定范围内的元素随机调整次序
// merge				// 容器元素合并，并存储到另一容器中
// reverse				// 反转指定范围的元素


#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <random>
using namespace std;


// shuffle(iterator beg, iterator end, _UGenerator)
//
// beg        起始迭代器
// end        结束迭代器
// _UGenerator 随机数生成器
//
// 功能：
//      随机打乱容器中的元素顺序
//
// 注意：
//      shuffle需要传入随机数生成器
//      常用：
//      random_device rd;      // 创建随机种子
//      mt19937 g(rd());       // 根据种子生成随机数
//
//      shuffle(v.begin(), v.end(), g);


void test02()
{
	random_device rd;	// 创建随机种子生成器

	mt19937 g(rd());	// 创建梅森旋转随机数生成器，使用 rd() 产生的随机种子初始化


	vector<int> v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);	// 0-9
	}
	cout << "洗牌前：" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});cout << endl;




	// 利用 洗牌算法 打乱顺序
	shuffle(v.begin(), v.end(), g);
	

	cout << "洗牌后：" << endl;
	for_each(v.begin(),v.end(),[](int val){cout << val << " ";});cout << endl;





	// 使用匿名函数对象方式
	shuffle(v.begin(), v.end(), mt19937(random_device{}()));


	cout << "洗牌后：" << endl;
	for_each(v.begin(), v.end(), [](int val) {cout << val << " ";});cout << endl;




	// 生成一个 1-100的随机数
	mt19937 gen(random_device{}());

	uniform_int_distribution<int> dist{ 1,100 };

	cout << "生成一个1-100的随机数：" << dist(gen) << endl;

	//	std::uniform_int_distribution<int> 是一个函数对象（functor），它内部重载了 operator()。
	//	这个运算符接受一个随机数引擎（URBG），返回一个符合均匀分布的整数。

	//	所以 dist(gen) 相当于调用了 dist.operator()(gen)。它的工作流程是：
	//	1. 从引擎 gen 获取一个原始随机数（通常是一个很大的无符号整数）；
	//	2. 将该原始随机数通过数学变换映射到区间[1, 100]（或你构造时指定的范围）；
	//	3. 返回映射后的整数。
}



int main2()
{
	test02();

	system("pause");
	return 0;
}