#include <iostream>
using namespace std;

int main()
{
	//1.创建布尔类型(Bool)
	bool flag = true;	//true表示真
	cout << flag << endl;
	
	flag = false;
	cout << flag << endl;
	

	//本质上 1代表真 0代表假

	//2.查看bool类型所占的内存空间

	cout << "Bool类型所占的内存空间：" << sizeof(flag) << endl;






	system("pause");
	return 0;
}