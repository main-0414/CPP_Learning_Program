#include "manager.h"


// 默认构造
Manager::Manager()
{

}


// 有参构造	管理员姓名,密码
Manager::Manager(string name, string password)
{
	// 初始化管理员信息
	this->m_Name = name;
	this->m_Password = password;
}


// 菜单界面
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}


// 添加账号
void Manager::addPerson()
{
	int select = 0;
	cin >> select;

	while (true)
	{
		cout << "请输入添加账号的类型：" << endl;
		cout << "1、添加学生" << endl;
		cout << "2、添加老师" << endl;


		if (select==1 || select==2)
		{
			break;
		}
		
		cout << "输入错误，请重新输入！" << endl << endl;

	}


	string tip = "";		// 选择后提示
	string fileName = "";

	if (select==1)
	{
		tip = "请输入学生编号：";
		fileName = STUDENT_FILE;
	}
	else
	{
		tip = "请输入职工编号：";
		fileName = TEACHER_FILE;
	}

	int ID = 0;
	cin >> ID;

	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;


	cout << "请输入密码：" << endl;
	string password;
	cin >> password;


	ofstream ofs(fileName, ios::out | ios::app);

	ofs << ID << " " << name << " " << password << endl;	// 写入文件

	cout << "添加成功！" << endl;

	finish();


}


// 查看账号
void Manager::showPerson()
{

}


// 查看机房信息
void Manager::showComputerInfo()
{

}


// 清空预约记录
void Manager::cleanFile()
{

}