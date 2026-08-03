#include <iostream>
#include <string>
using namespace std;

// string& insert(int pos, const char* s);            //插入字符串
// string& insert(int pos, const string& str);        //插入字符串
// string& insert(int pos, int n, char c);            //在指定位置插入n个字符c
// string& erase(int pos, int n = npos);              //删除从Pos开始的n个字符 



// 字符串的插入和删除
void test08()
{
	string str = "hello";


	// 插入
	str.insert(1, "111");	// h111ello

	cout << "str = " << str << endl;


	// 删除
	str.erase(1, 3);	// 从1下标擦除三个字符
	// hello
	cout << "str = " << str << endl;
}


// 总结：插入和删除的起始下标都是从0开始






int main()
{
	test08();


	system("pause");
	return 0;
}