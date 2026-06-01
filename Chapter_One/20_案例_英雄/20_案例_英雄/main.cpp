#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

// 1.创建英雄结构体
struct Hero
{
	string name;
	int age;
	string gender;
};

// 排序函数
void BubbleSort(struct Hero H_array[], int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (H_array[j].age > H_array[j + 1].age)
			{
				struct Hero temp = H_array[j];	
				H_array[j] = H_array[j + 1];
				H_array[j + 1] = temp;
				//temp是个结构体变量，进行的是结构体的存储
			}
		}
	}
}

// 打印结果函数
void PrintHero(struct Hero H_Array[], int len)
{
	cout << "按年龄升序排序后：" << endl;
	for (int i = 0;i < len; i++)
	{
		cout << "姓名：" << H_Array[i].name
			<< "  年龄：" << H_Array[i].age
			<< "  性别：" << H_Array[i].gender << endl;
	}
}


int main()
{
	// 2.创建英雄数组存放数据

	Hero H_Array[5] =
	{
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"}
	};

	int len = sizeof(H_Array) / sizeof(H_Array[0]);

	// 排序前
	cout << "排序前：" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << "姓名：" << H_Array[i].name
			<< "  年龄：" << H_Array[i].age
			<< "  性别：" << H_Array[i].gender << endl;
	}

	// 3.对数组进行排序，按照年龄进行升序排序
	BubbleSort(H_Array, len);

	// 4.将排序后的结果打印输出
	PrintHero(H_Array, len);




	system("pause");
	return 0;
}