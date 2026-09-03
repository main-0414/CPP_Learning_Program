#include "login.h"


// 登录功能	参数一：操作文件名	参数二：身份类型
void Login(string FileName, int type)
{
	// 父类指针，用于指向子类对象
	Identity* person;

	// 读文件
	ifstream ifs(FileName, ios::in);	// 读文件

	// 判断文件是否存在（得有文件有内容才开始读）
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	// 准备接收用户信息
	int ID = 0;
	string name;
	string password;


	// 判断身份（管理员没有id号）
	if (type == 1)	// 学生身份
	{
		cout << "请输入你的学号：" << endl;
		cin >> ID;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> ID;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> password;



	// 开始做学生的身份验证
	if (type == 1)
	{
		// 学生身份验证
		int fID;
		string fName;
		string fPassword;

		while (ifs >> fID >> fName >> fPassword)	// 文件中保存格式是 “ID 姓名 密码”
		{
			// 与用户输入的信息做对比
			if (fID == ID && fName == name && fPassword == password)
			{
				cout << "学生验证登录成功！" << endl;

				finish();

				// 创建该身份的对象
				person = new Student(ID, name, password);

				// 进入学生身份子菜单
				studentMenu(person);

				return;
			}
		}

	}
	else if (type == 2)
	{
		// 老师身份验证
		int fID;
		string fName;
		string fPassword;

		while (ifs >> fID >> fName >> fPassword)
		{
			if (fID == ID && fName == name && fPassword == password)
			{
				cout << "老师验证登录成功！" << endl;

				finish();

				person = new Teacher(ID, name, password);



				finish();
				return;
			}
		}

	}
	else if (type == 3)	// 不能用else要不然自动归为管理员了
	{
		// 管理员身份验证
		string fName;
		string fPassword;

		while (ifs >> fName >> fPassword)
		{
			if (fName == name && fPassword == password)
			{
				cout << "管理员验证登录成功！" << endl;

				// 跳转界面前先清屏
				finish();

				person = new Manager(name, password);

				managerMenu(person);

				return;
			}
		}

	}

	cout << "验证登录失败！" << endl;

	finish();
	return;
}
