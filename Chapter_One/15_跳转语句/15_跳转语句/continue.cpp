#include <iostream>
using namespace std;

int main2()
{
	//continue语句
	//在循环语句中，跳过本次循环中余下尚未执行的语句，继续执行下一次循环

	//遍历0~100的奇数
	for (int i = 0; i <=100; i++)
	{
		if (i%2==0)
		{
			continue;	//跳过本次循环
			//break 则是直接退出循环
		}
		cout << i << endl;
	}













	system("pause");
	return 0;
}