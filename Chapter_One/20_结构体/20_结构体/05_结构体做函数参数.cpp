#include <iostream>
#include <string>
using namespace std;

//定义一个学生结构体
struct Student
{
	string name;
	int age;
	int score;
};

//打印学生信息
// 1.值传递
void PrintStudent1(Student stu)
{
	stu.age = 100;
	cout << "在子函数1中 姓名：" << stu.name
		<< "  年龄：" << stu.age
		<< "  成绩：" << stu.score << endl;
}


// 2.地址传递
void PrintStudent2(struct  Student* p)
{
	p->age = 100;
	cout << "在子函数2中，姓名：" << p->name
		<< "  年龄：" << p->age
		<< "  成绩：" << p->score << endl;
}

int main5()
{
	//函数体做函数参数
	//目的：将学生传入到一个参数中，打印学生身上的所有信息

	//创建结构体变量：
	Student stu;
	stu.name = "张三";
	stu.age = 20;
	stu.score = 85;


	//PrintStudent1(stu);	//值传递
	PrintStudent2(&stu);


	cout << "在main函数中打印 年龄：" << stu.age << endl;


	system("pause");
	return 0;
}