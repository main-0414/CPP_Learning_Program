#include <iostream>
using namespace std;

//string& operator+=(const char* str);                //重载+=操作符
//string& operator+=(const char c);                   //重载+=操作符
//string& operator+=(const string& str);              //重载+=操作符
//string& append(const char* s);                      //把字符串s连接到当前字符串结尾
//string& append(const char* s, int n);               //把字符串s的前n个字符连接到当前字符串结尾
//string& append(const string& s);                    //同operator+=(const string& str)
//string& append(const string& s, int pos, int n);`	// 字符串s中从pos开始的n个字符连接到字符串结尾

void test03()
{
	string str1 = "我爱";
	str1 += "玩游戏";
	cout << "str1 = " << str1 << endl;

	str1 += ':';
	cout << "str1 = " << str1 << endl;


	string str2 = "PUBG LOL";
	str1 += str2;
	cout << "str1 = " << str1 << endl;


	// str3.append("n")把引号内字符拼接到str3中
	string str3 = "I";
	str3.append(" Love ");
	cout << "str3 = " << str3 << endl;


	// 取前 4 个字符拼接到 str3 后面
	str3.append("game abcde", 4);
	cout << "str3 = " << str3 << endl;


	// 同+=的append用法
	str3.append(str2);
	// I Love gamePUBG LOL
	cout << "str3 = " << str3 << endl;




	// str2截取第0到第4个字符，拼接到str4后面
	string str4 = "I Love game:";
	str4.append(str2, 0, 4);	// 只截取"PUBG"
	cout << "str4 = " << str4 << endl;
}




int main3()
{
	test03();


	system("pause");
	return 0;
}