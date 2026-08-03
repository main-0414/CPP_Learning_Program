#include <iostream>
using namespace std;

// string求子串

// string substr(int pos = 0, int n = npos) const;	//返回由pos开始的n个字符组成的字符串


void test09()
{
	string str = "abcdef";

	string subStr = str.substr(1, 3);

	cout << "subStr = " << subStr << endl;

}

// 实用操作
void test10()
{
	string email = "aaa@sina.com";

	// 从邮件名 获取 用户名信息
	// 1. 找到 @ 的位置
	int index = email.find("@");

	// 2. 截取
	string userName = email.substr(0, index);

	cout << "userName = " << userName << endl;


	// 截取 sina.com
	int sum = email.size();
	string host = email.substr(index + 1, sum);
	cout << "host = " << host << endl;
}







int main()
{
	test09();
	test10();


	system("pause");
	return 0;
}