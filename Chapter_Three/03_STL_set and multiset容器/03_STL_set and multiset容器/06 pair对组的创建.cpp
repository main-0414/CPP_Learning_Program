//pair<type, type > p(value1, value2);					// 默认构造
//pair<type, type > p = make_pair(value1, value2);		// make_pair


#include <iostream>
#include <set>
using namespace std;



void test08()
{
	// 第一种方式
	pair<string, int> p("Tom", 18);

	cout << "姓名：" << p.first << "  年龄：" << p.second << endl;

	// 第二种方式
	pair<string, int>p2 = make_pair("Jerry", 90);
	cout << "姓名：" << p2.first << "  年龄：" << p2.second << endl;

}






int main6()
{
	test08();


	system("pause");
	return 0;
}