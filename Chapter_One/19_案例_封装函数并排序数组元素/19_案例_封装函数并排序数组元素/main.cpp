#include <iostream>
using namespace std;

//冒泡排序函数
void BubbleSort(int* F_local, int len);
//int* F_local 也可以写为int F_local[]，在函数参数列表里，int arr[] 不是数组，是一个指针！

void BubbleSort(int* F_local, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (F_local[j] > F_local[j + 1])  //F_local[j] 在C++里，本质就是 *(F_local+j)
			{
				int temp = F_local[j];
				F_local[j] = F_local[j + 1];
				F_local[j + 1] = temp;
			}
		}
	}
}

void PrintArray(int F_local[], int len);

void PrintArray(int F_local[], int len)
{
	for (int i = 0;i < len; i++)
	{
		cout << *(F_local + i) << " ";	// 等于 cout << F_local[i] << " ";
	}
}

int main()
{
	// 1.创建数组arr
	int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };

	int len = sizeof(arr) / sizeof(arr[0]); //数组长度

	// 2.创建函数，实现冒泡排序
	BubbleSort(arr, len);	//传入数组首地址和数组长度

	// 3.打印数组
	PrintArray(arr, len);

	system("pause");
	return 0;
}
