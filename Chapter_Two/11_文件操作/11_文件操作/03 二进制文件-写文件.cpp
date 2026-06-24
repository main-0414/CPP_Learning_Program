#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// 二进制文件 写文件
class Person
{
public:

	char m_Name[64];	// 姓名
	int m_Age;			// 年龄

};


void test03()
{
	// 1.包含头文件

	// 2.创建流对象
	ofstream ofs("person.txt", ios::out | ios::binary);

	// 3.打开文件
	//ofs.open("person.txt", ios::out | ios::binary);


	// 4.写文件
	Person p = { "张三",18 };
	// 函数原型 ：ostream& write(const char * buffer,int len);
	// 从 p 这个对象所占内存的起始位置开始，取出 sizeof(Person) 个字节，原样写入文件流 ofs。
	ofs.write((const char*)&p, sizeof(Person));


	// 5.关闭文件
	ofs.close();
}






int main()
{
	test03();



	system("pause");
	return 0;
}