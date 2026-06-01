#include <iostream>
using namespace std;

//结构体指针

//创建结构体
struct student
{
	string name;
	int age;
	int score;
};

int main3()
{
	// 1.创建结构体变量
	student s = { "张三",18,66 };

	// 2.通过指针指向结构体变量
	student* p = &s;

	// 3.通过指针访问结构体变量中的数据
	// 通过结构体指针访问结构体中的属性，需要利用“->”

	p->score = 60;

	cout << "姓名：" << p->name
		<< "   年龄：" << p->age
		<< "   成绩：" << p->score << endl;



	system("pause");
	return 0;
}