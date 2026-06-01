#include <iostream>
using namespace std;

int main4()
{
	//野指针
	//在程序中，一定避免出现野指针
	int* p = (int*)0x1100;	//这块地址我没有申请，不能去
							//如果没有进行初始化也是一个野指针
	cout << *p << endl;		//引发了异常：读取访问权限冲突


	//空指针和野指针都不是我们申请的空间，因此不要访问


	system("pause");
	return 0;
}