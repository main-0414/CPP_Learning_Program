#include <iostream>
using namespace std;

int main2()
{
	//指针所占的内存空间
	int a = 10;
	//int* p;
	//p = &a;

	int* p = &a;

	cout << "sizeof(int *) =" << sizeof(int *) << endl;
	cout << "sizeof(float *) =" << sizeof(float *)<< endl;
	cout << "sizeof(double *) =" << sizeof(double *)<< endl;
	cout << "sizeof(char *) =" << sizeof(char *)<< endl;
	//指针变量在x64位操作系统下是8字节，32位操作系统4字节








	system("pause");
	return 0;
}