#include <iostream>
#include <map>
#include "printMap.h"
using namespace std;

void test04()
{
	map<int, int> m;

	// 第一种
	m.insert(pair<int, int>(1, 10));

	// 第二种
	m.insert(make_pair(2, 20));	// 自动类型

	// 第三种
	m.insert(map<int, int>::value_type(3, 30));	// 值类型方式

	// 第四种
	m[4] = 40;	// 如果插错了，不会报错，会自动创建，比较危险
	// 所以[]不适合插入数据，而适合通过key访问value
	cout << m[3] << endl;


	cout << m[5] << endl;	// 如果没有key为5的对组，那么自动创建出来一个key=5,value=0的对组

	printMap(m);


	// erase(迭代器)  删除
	m.erase(m.begin());
	printMap(m);	

	// erase(key值)  删除
	m.erase(30);	// 没有key为30的，不做动作
	printMap(m);

	// erase(迭代器区间)  删除
	m.erase(m.begin(), m.end());	// 清空
	printMap(m);

	// clear()  清空
	m.clear();
	printMap(m);

}



int main3()
{
	test04();


	system("pause");
	return 0;
}