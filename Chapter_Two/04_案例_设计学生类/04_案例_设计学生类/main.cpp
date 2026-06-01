#include <iostream>
using namespace std;

// 创建一个学生类
class student
{
public:		//公共权限

	// 类中的属性和行为 统一成为 成员
	// 属性 成员属性 成员变量
	// 行为 成员函数 成员方法

	// 属性
	string s_name = "";
	int s_number = 0;

	// 行为
	// 显示信息
	void showStudent()
	{

		cout << "显示学生信息：" << endl << "学生姓名：" << s_name << endl
			<< "学生学号：" << s_number << endl;
	}

	// 姓名赋值
	void setName(string name)
	{
		s_name = name;
	}

	// 学号赋值
	void setNumber(int number)
	{
		s_number = number;
	}

};






int main()
{
	student s1;
	//s1.s_name = "观观王";
	s1.setName("观观王");
	//s1.s_number = 123456;
	s1.setNumber(123456);
	s1.showStudent();






	system("pause");
	return 0;
}