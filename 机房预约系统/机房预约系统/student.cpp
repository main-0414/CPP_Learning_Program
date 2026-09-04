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

	int date = 0;		// 日期
	int interval = 0;	// 时间段
	int room = 0;		// 机房编号


	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
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

		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误！请重新输入：" << endl;
	}


	cout << "预约成功！审核中！" << endl;

	// 写入 order 文件
	ofstream ofs(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " "
		<< "interval:" << interval << " "	// 上下午时段
		<< "stuID:" << this->m_StuID << " "
		<< "stuName:" << this->m_Name << " "
		<< "roomID:" << room << " "
		<< "status:" << 1 << endl;			// 审核状态
	ofs.close();


	finish();
}


// 查看我的预约
void Student::showMyOrder()
{
	OrderFile of;

	bool found = false;

	// 找order文件里预约信息里有没有当前学生的
	for (int i = 0; i < of.m_Num; i++)
	{
		// 字符串转整数函数 stoi()
		if (this->m_StuID == stoi(of.m_orderData[i]["stuID"]))	// 找到自身预约
		{
			found = true;	// 找到自己的记录，让标记为真

			string status;

			// 1 审核中		2 预约成功	-1 预约失败		0 取消预约
			if (of.m_orderData[i]["status"] == "1")
			{
				status = "审核中……";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status = "预约成功！";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status = "预约失败！审核未通过！";
			}
			else
			{
				status = "预约已取消！";
			}


			cout << "预约日期：周" << of.m_orderData[i]["date"]
				<< "   时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
				<< "   机房号：" << of.m_orderData[i]["roomID"]
				<< "   预约状态：" << status << endl;

		}
	}

	if (!found)
	{
		cout << "你还未添加预约！" << endl;
		finish();
		return;
	}

	finish();
}


// 查看所有预约
void Student::showAllOrder()
{
	OrderFile of;

	if (of.m_Num==0)
	{
		cout << "无任何预约！" << endl;
		finish();
		return;
	}

	for (int i = 0; i < of.m_Num; i++)
	{
		string status;

		// 1 审核中		2 预约成功	-1 预约失败		0 取消预约
		if (of.m_orderData[i]["status"] == "1")
		{
			status = "审核中……";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status = "预约成功！";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status = "预约失败！审核未通过！";
		}
		else
		{
			status = "预约已取消！";
		}


		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["date"]
			<<"   学号："<<of.m_orderData[i]["stuID"]
			<<"   姓名："<<of.m_orderData[i]["stuName"]
			<< "   时间段：" << (of.m_orderData[i]["iterval"] == "1" ? "上午" : "下午")
			<< "   机房号：" << of.m_orderData[i]["roomID"]
			<< "   预约状态：" << status << endl;
	}

	finish();
}


// 取消预约
void Student::cancelOrder()
{


}