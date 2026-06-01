#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	//冒泡排序
	srand(time(NULL));

	int a[10] = { 0 };

	cout << "排序前：";
	for (int i = 0; i < 10; i++)
	{
		a[i] = rand() % 90 + 10;
		cout << a[i] << "  ";
	}



	/*	for (int i = sizeof(a) / sizeof(a[0]) - 1; i >= 0; i--)
		{
			for (int j = i; j < sizeof(a) / sizeof(a[0]) - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					int t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}
		}*/

	for (int i = 0; i < (sizeof(a) / sizeof(a[0])) - 1; i++)
						//排序总轮数 = 元素个数-1
	{
		for (int j = 0; j < (sizeof(a) / sizeof(a[0])) - i - 1; j++)
						//每次对比轮数 = 元素个数-排序当前轮数-1
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}











	cout << endl << "排序后：";
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << "  ";
	}







	system("pause");
	return 0;
}