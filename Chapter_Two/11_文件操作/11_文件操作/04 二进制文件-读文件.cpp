#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class person
{
public:
	char m_Name[64];	// 姓名
	int m_Age;			// 年龄

};






// 二进制 读文件
void test04()
{
	// 1.包含头文件

	// 2.创建流对象
	ifstream ifs;
		


	// 3.打开文件 判断文件打开成功
	ifs.open("person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}

	// 4.读文件
	person p;
	ifs.read((char*)&p, sizeof(p));
	//	read(存到哪里, 读多少字节);
	//	从文件读取相同数量的字节，原封不动覆盖到对象 p 的内存中。

	cout << "姓名：" << p.m_Name << endl << "年龄：" << p.m_Age << endl;

	// 5.关闭文件
	ifs.close();

}




int main()
{
	test04();


	system("pause");
	return 0;
}