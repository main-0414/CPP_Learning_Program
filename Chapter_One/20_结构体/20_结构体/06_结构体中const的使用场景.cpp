#include <iostream>
#include <string>
using namespace std;

struct student
{
	string name;
	int age;
	int score;
};

//将函数中的形参改为指针，可以减少内存空间，而且不会复制新的空间出来
void PrintStudents(const student*  stu_p)  //const主要是防止误操作
{
	//stu_p->age = 20;	//参数前加了const便成为常量指针，值只能读不能改

	cout << "姓名：" << stu_p->name
		<< "  年龄：" << stu_p->age
		<< "  成绩：" << stu_p->score << endl;
}

int main()
{
	// 创建结构体变量stu
	struct student stu = { "张三",18,80 };

	PrintStudents(&stu);





	system("pause");
	return 0;
}