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

	// 初始化容器
	this->initVector();
}


// 初始化容器
void Manager::initVector()
{
	// 读取老师和学生的信息

	ifstream ifs(STUDENT_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "学生文件读取失败！" << endl;
		return;
	}

	// 清空容器重新读、写
	vStudent.clear();
	vTeacher.clear();


	// 从文件里读取存入容器
	Student s;

	while (ifs >> s.m_StuID >> s.m_Name >> s.m_Password)	// 将文件中的学生信息读取到 Student 对象的属性中
	{
		vStudent.push_back(s);
	}

	cout << "当前学生数量为：" << vStudent.size() << endl;
	ifs.close();




	ifs.open(TEACHER_FILE, ios::in);

	if (!ifs.is_open())
	{
		cout << "老师文件读取失败！" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.m_Empid >> t.m_Name >> t.m_Password)
	{
		vTeacher.push_back(t);
	}
	cout << "当前老师数量为：" << vTeacher.size() << endl;
	ifs.close();


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
	

	while (true)
	{
		cout << "请输入添加账号的类型：" << endl;
		cout << "1、添加学生" << endl;
		cout << "2、添加老师" << endl;

		cin >> select;

		if (select==1 || select==2)
		{
			break;
		}
		
		cout << "输入错误，请重新输入！" << endl << endl;

	}


	string tip = "";		// 选择后提示
	string fileName = "";
	string errorTip = "";	// 重复提示


	if (select==1)
	{
		tip = "请输入学号：";
		fileName = STUDENT_FILE;
		errorTip = "学号重复！请重新输入：";
	}
	else
	{
		tip = "请输入职工编号：";
		fileName = TEACHER_FILE;
		errorTip = "职工号重复！请重新输入：";
	}

	// 输入ID
	cout << tip << endl;
	int ID = 0;

	while (true)
	{
		cin >> ID;

		if (this->checkRepeat(ID,select))
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}


	// 输入姓名
	cout << "请输入姓名：" << endl;
	string name;
	cin >> name;

	// 输入密码
	cout << "请输入密码：" << endl;
	string password;
	cin >> password;


	ofstream ofs(fileName, ios::out | ios::app);
	ofs << ID << " " << name << " " << password << endl;	// 写入文件

	cout << "添加成功！" << endl;

	this->initVector();		// 更新一下容器，保持最新数据

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




// 检查重复
bool Manager::checkRepeat(int ID, int type)
{
	if (type==1)
	{
		for (vector<Student>::iterator it = vStudent.begin(); it != vStudent.end(); it++)
		{
			if (ID==it->m_StuID)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTeacher.begin(); it != vTeacher.end(); it++)
		{
			if (ID == it->m_Empid)
			{
				return true;
			}
		}
	}

	return false;	// 重复了返回true，反之false
}