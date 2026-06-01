#include <iostream>
using namespace std;

// 定义学生结构体
struct student
{
	string name;
	int age;
	int score;
};

// 定义老师结构体
struct teacher
{
	string name;
	int id;
	int age;
	student stu1;		//老师所辅导的学生
};

int main4()
{
	//结构体嵌套结构体
	
	//创建老师
	teacher t;
	t.name = "老王";
	t.id = 10000;
	t.age = 43;
	
	t.stu1.name = "小王";
	t.stu1.age = 18;
	t.stu1.score = 99;

	cout << "教师姓名：" << t.name
		<< "  教师编号：" << t.id
		<< "  教师年龄：" << t.age << endl

		<< "教师所带学生姓名：" << t.stu1.name
		<< "  教师所带学生年龄：" << t.stu1.age
		<< "  教师所带学生成绩：" << t.stu1.score << endl;
		 

	system("pause");
	return 0;
}