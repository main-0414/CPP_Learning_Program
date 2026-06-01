#include <iostream>
using namespace std;

int main6()
{
	//指针与数组
	//利用指针来访问数组中的元素

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "数组中第一个元素是：" << arr[0] << endl;

	int* p = arr;	//arr就是数组的首地址
	cout << "利用指针访问数组第一个元素：" << *p << endl;

	p++;  //偏移步长由指针的基类型决定：int* 步长是4字节,
			//所以往后偏移4字节后解引用后四个字节，就是取出第2个元素
	cout << "利用指针访问数组第二个元素：" << *p << endl;
	



	cout << endl;


	int* p2 = arr;
	//利用指针遍历数组
	cout << "利用指针遍历数组:" << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << *p2 << " ";
		p2++;
	}




	system("pause");
	return 0;
}