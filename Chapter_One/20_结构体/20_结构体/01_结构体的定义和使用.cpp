#include <iostream>
using namespace std;

//1.创建Student数据类型（模板）：学生包括	（姓名，年龄，分数）
//自定义数据类型，一些类型集合组成的一个类型
//语法：struct 类型名称  { 成员列表 };

struct Student
{
	//成员列表：
	
	string name;	//姓名
	int age;		//年龄
	int score;		//分数
}S3;

//2.通过Student类型创建具体学生

int main1()
{
	//2.1 定义一个 Student 结构体变量 S1
	Student S1;		//创建结构体变量时，关键字struct可以省略

	//给S1变量(某学生)的某属性赋值，通过“.”访问结构体变量中的属性
	S1.name = "观观王";
	S1.age = 18;
	S1.score = 100;

	cout << "姓名：" << S1.name << "   年龄：" << S1.age << "   分数：" << S1.score << endl;


	//2.2 struct Student S2={ . . . }
	struct Student S2 = { "张三",19,80 };	// c语言里结构体名称前要加struct，c++随意
	cout << "姓名：" << S2.name << "   年龄：" << S2.age << "   分数：" << S2.score << endl;


	//2.3 在定义结构体变量时顺便创建结构体变量（第15行）
	S3.name = "李四";
	S3.age = 20;
	S3.score = 60;
	cout << "姓名：" << S3.name << "   年龄：" << S3.age << "   分数：" << S3.score << endl;




	system("pause");
	return 0;
}