#include "student.h"


// 默认构造
Student::Student()
{

}


// 有参构造
Student::Student(int ID, string name, string password)
{
	// 初始化属性
	this->m_StuID = ID;
	this->m_Name = name;
	this->m_Password = password;

	// 初始化机房信息
	initRoom();
}

// 初始化机房
void Student::initRoom()
{
	ifstream ifs(COMPUTER_FILE, ios::in);

	computerRoom c;

	while (ifs >> c.m_RoomID >> c.m_RoomMAX)
	{
		vRoom.push_back(c);
	}

	ifs.close();
}


// 操作界面
void Student::operMenu()	// 子类重载
{
	cout << "欢迎学生代表：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

// 申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一至周五!" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;

	int data = 0;		// 日期
	int interval = 0;	// 时间段
	int room = 0;		// 机房编号


	while (true)
	{
		cin >> data;
		if (data >=1 && data<=5)
		{
			break;
		}

		cout << "输入有误！请重新输入：" << endl;
	}

	cout << "请输入申请预约时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;

	while (true)
	{
		cin >> interval;
		if (interval == 1 || interval == 2)
		{
			break;
		}

		cout << "输入有误！请重新输入：" << endl;
	}

	cout << "请选择机房：" << endl;
	
	for (int i = 0; i < vRoom.size(); i++)
	{
		cout << vRoom[i].m_RoomID << " 号机房容量为：" << vRoom[i].m_RoomMAX << endl;
	}


	while (true)
	{
		cin >> room;

		if (room>=1 && room<=3)
		{
			break;
		}
		cout << "输入有误！请重新输入：" << endl;
	}
	

	cout << "预约成功！审核中！" << endl;

	// 写入 order 文件
	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	ofs << "data:" << data << " "
		<< "interval:" << interval << " "	// 上下午时段
		<< "stuID:" << this->m_StuID << " "
		<< "stuName:" << this->m_Name << " "
		<< "roomID:" << room << " "
		<< "status:" << 0 << endl;			// 审核状态
	ofs.close();


	finish();
}


// 查看我的预约
void Student::showMyOrder()
{

}


// 查看所有预约
void Student::showAllOrder()
{

}


// 取消预约
void Student::cancelOrder()
{


}