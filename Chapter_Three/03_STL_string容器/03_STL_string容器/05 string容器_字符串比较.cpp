#include <iostream>
using namespace std;

// 比较方式：字符串比较是按字符的ASCII码进行对比
// 从第一个字符开始逐个比较，遇到第一个不同的字符就停止。

// = 返回 0
// > 返回 1
// < 返回 -1

void test06()
{
	string str1 = "xella";
	string str2 = "hello";

	//compare()最大用途是判断两个字符串是否相等，ASCII码判断出大于小于没有啥意义
	if (str1.compare(str2) == 0)
	{
		cout << "str1 等于 str2" << endl;
	}
	else if (str1.compare(str2) > 0)
	{
		cout << "str1 大于 str2" << endl;
	}
	else if (str1.compare(str2) < 0)
	{
		cout << "str1 小于 str2" << endl;
	}


}




int main5()
{
	test06();


	system("pause");
	return 0;
}