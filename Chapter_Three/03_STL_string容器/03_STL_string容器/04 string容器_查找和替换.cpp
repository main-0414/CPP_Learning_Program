#include <iostream>
using namespace std;

// 字符串的查找和替换

// 1. 查找
void test04()
{
	string str1 = "abcdefgde";

	// find完会返回一个int类型下标，如果没有那就返回 -1
	int pos = str1.find("de");

	if (pos == -1)
	{
		cout << "未找到字符串" << endl;
	}
	else
	{
		cout << "找到字符串，pos = " << pos << endl;
	}

	// rfind 和 find 区别
	// rfind:从右往左 查找	find:从左往右 查找
	pos = str1.rfind("de");
	
	cout << "rfind pos = " << pos << endl;

}


void test05()
{
	string str1 = "abcdefg";

	// 从1号位置起 3个字符 替换成“1111”，超出的不会去除
	str1.replace(1, 3, "1111");

	cout << "str1 = " << str1 << endl;	// a1111efg

	str1 = "abcdefg";
	str1.replace(1, 3, "1");
	cout << "str1 = " << str1 << endl;	// a1efg

}


int main4()
{
	test04();
	test05();

	system("pause");
	return 0;
}