#include <iostream>
#include <string>
using namespace std;

//结构体数组
// 1.定义结构体
struct Student
{
	string name;
	int age;
	int score;
};


int main2()
{
	// 2.创建结构体数组
	Student StuArray[3] =
	{
		{"张三",18,60},
		{"李四",19,80},
		{"王五",20,78}
	};

	// 3.给结构体数组中的元素赋值

	StuArray[2].name = "赵六";		//可以后期再给值，也可以初始化时候给值
	StuArray[2].age = 99;



	// 4.遍历结构体数组

	for (int i = 0; i < 3; i++)
	{
		cout << "姓名："    << StuArray[i].name 
			 << "   年龄：" << StuArray[i].age 
			 << "   成绩：" << StuArray[i].score << endl;
	}




	system("pause");
	return 0;
}