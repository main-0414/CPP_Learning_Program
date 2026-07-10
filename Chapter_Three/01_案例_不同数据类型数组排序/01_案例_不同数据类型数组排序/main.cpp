#include <iostream>
using namespace std;

/*
案例描述：
	利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
	排序规则 从大到小，排序算法为 选择排序
	分别用 char数组 和 int数组 进行测试
*/


// 排序算法
template<class T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int MAX = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[MAX] < arr[j])
			{
				MAX = j;
			}
		}

		if (MAX != i)
		{
			int temp = arr[i];
			arr[i] = arr[MAX];
			arr[MAX] = temp;
		}

	}
}

// 提供打印数组模板
template<class T>
void printArr(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " " ;
	}
	cout << endl;
}




// 测试char数组
void test01()
{
	char charArr[] = "badcfe";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArr(charArr, num);
}

// 测试int数组
void test02()
{
	int intArr[] = {5,9,6,3,2,7,1,8};
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArr(intArr, num);
}







int main()
{
	test01();
	test02();



	system("pause");
	return 0;
}