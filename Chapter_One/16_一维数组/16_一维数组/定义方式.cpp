#include <iostream>
using namespace std;

int main1()
{
	//一维数组  三种方式


	//1. 数据类型  数组名[数组长度];     //无初始化，未显式赋值的元素在debug模式下自动补-858993460
	int arr1[4];

	arr1[0] = 10;
	arr1[1] = 20;
	arr1[2] = 30;

	for (int i = 0; i < 4; i++)
	{
		cout << arr1[i] << endl ;
	}
	cout << endl;


	//2. 数据类型  数组名[数组长度] = { 值1，值2 ... };	//有初始化，未显式赋值的元素自动补 0
	int arr2[5] = { 10,20,30,40 };	//有初始化，未显式赋值的元素自动补 0

	for (int i = 0; i <= 4; i++)
	{
		cout << arr2[i] << endl ;
	}
	cout << endl;


	//3. 数据类型  数组名[] = { 值1，值2 ... };

	int arr3[] = { 90,80,70,60,50 };
	for (int i = 0; i <= 5; i++)	//虽然初始化，但越界访问了依然会返回垃圾值
	{
		cout << arr3[i] << endl;
	}






	system("Pause");
	return 0;
}