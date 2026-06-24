#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 文本文件的读取
void test02()
{
	// 1.包含头文件

	// 2.创建流对象
	ifstream ifs;

	// 3.打开文件 并且判断是否打开成功
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;	//结束函数，不再往下读取文件
	}




	// 4.读数据
	
	//第一种 
	//char buf[1024] = { 0 };
	//string buf;
	//while (ifs >> buf)
	//{
	//	cout << buf << endl;
	//}

	// 第二种
	//string str;
	//while (getline(ifs,str))
	//{
	//	cout << str << endl;
	//}



	//char str[1024] = { 0 };
	//while (ifs.getline(str, sizeof(str)))
	//{
	//	cout << str << endl;
	//}

	

	// 第三种
	string str;
	while (getline(ifs, str))
	{
		cout << str << endl;
	}

	

	// 第四种（不推荐）
	//char c;
	//while ((c = ifs.get()) != EOF)		//END OF FILE  文件尾
	//{
	//	cout << c;
	//}


	// 5.关闭文件
	ifs.close();

}



int main2()
{
	test02();


	system("pause");
	return 0;
}