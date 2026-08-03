#include <iostream>
using namespace std;

// string 字符串存取

// 1. []
// 2. at()

void test07()
{
	string str = "hello";

	// 1. 通过 [] 访问单个字符
	for (int i = 0; i < str.size(); i++)	// .size()可以获取字符串长度
	{
		cout << str[i] << " ";
	}
	cout << endl;

	// 2. 通过 at 方式访问单个字符
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;


	// 修改单个字符
	str[5] = 'x';		// 越界没事
	// xello
	cout << "str = " << str << endl;

	str.at(4) = 'x';	// 越界报错
	cout << "str = " << str << endl;

}








int main()
{
	test07();



	system("pause");
	return 0;
}
