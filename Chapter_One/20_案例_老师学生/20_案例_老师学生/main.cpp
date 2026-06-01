#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


//学生结构体
struct student
{
	string stu_name;
	int stu_score;
};

//老师结构体
struct teacher
{
	string t_name;
	struct student s_Array[5];	//添加学生数组
};


//给老师和学生赋值的函数
void Allocate(teacher t_Array[], int len)	//形参传进数组时看成指针，语法糖
{
	string name_num = "ABCDE";

	//给老师赋值
	for (int i = 0; i < len; i++)
	{
		t_Array[i].t_name = "teacher_";
		t_Array[i].t_name += name_num[i];
		//std::string 类重载了 [] 下标运算符，
		//它允许你像访问字符数组一样去访问字符串中的单个字符。


		//通过循环给每名老师所带的学生赋值
		for (int j = 0; j < 5; j++)
		{
			t_Array[i].s_Array[j].stu_name = "student_";
			t_Array[i].s_Array[j].stu_name += name_num[j];

			int random = rand() % 61 + 40;
			t_Array[i].s_Array[j].stu_score = random;
			//学生成绩赋值
		}
	}
}


// 形参：数组写法 → 纯指针写法 teacher*
void PrintInfo(teacher* t_Array, int len)
{
	for (int i = 0; i < len; i++)
	{
		// 访问第 i 个老师：(t_Array + i)->成员
		cout << "老师姓名：" << (t_Array + i)->t_name << endl;

		for (int j = 0; j < 5; j++)
		{
			// 访问学生：先找到老师 → 拿到学生数组 → 偏移 j → 访问成员
			cout << "\t学生姓名：" << ((t_Array + i)->s_Array + j)->stu_name 
				<< "  毕设得分：" << ((t_Array + i)->s_Array + j)->stu_score << endl;
		}								// -> 符号优先级大于 + —
		cout << endl;
	}
}


int main()
{
	srand((unsigned int)time(NULL));	//随机数种子

	// 1.创建老师的数组
	struct teacher t_Array[3];

	// 2.通过函数给三名老师赋值，并给老师带的学生信息赋值
	int	len = sizeof(t_Array) / sizeof(t_Array[0]);
	Allocate(t_Array, len);		//allocate意为“分配”
	//数组名本身，就代表数组首元素的地址，已经是个指针了。

	// 3.打印所有老师及所带的学生信息
	PrintInfo(&t_Array[0], len); 
	// t_Array 等价于 &t_Array[0] ，意思都是数组第一个元素的首地址
	//类型都位 teacher *，所以形参可以写为 teacher* t_Array



	system("Pause");
	return 0;
}