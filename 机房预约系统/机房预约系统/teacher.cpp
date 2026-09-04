#include "teacher.h"

// 默认构造
Teacher::Teacher()
{

}

// 有参构造
Teacher::Teacher(int ID, string name, string password)
{
	// 初始化属性
	this->m_EmpID = ID;
	this->m_Name = name;
	this->m_Password = password;
}

// 菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

// 查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;

	if (of.m_Num == 0)
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
			<< "   学号：" << of.m_orderData[i]["stuID"]
			<< "   姓名：" << of.m_orderData[i]["stuName"]
			<< "   时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
			<< "   机房号：" << of.m_orderData[i]["roomID"]
			<< "   预约状态：" << status << endl;
	}

	finish();
}

// 审核预约
void Teacher::validOrder()
{
	OrderFile of;

	if (of.m_Num == 0)
	{
		cout << "无预约记录！" << endl;
		finish();
		return;
	}

	vector<int> v;
	int index = 1;


	for (int i = 0; i < of.m_Num; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);

			cout << index++ << "、";
			cout << "预约日期： 周" << of.m_orderData[i]["date"]
				<< "   学生编号：" << of.m_orderData[i]["stuID"]
				<< "   学生姓名：" << of.m_orderData[i]["stuName"]
				<< "  时间段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午")
				<< "  机房编号：" << of.m_orderData[i]["roomId"]
				<< "   预约状态：审核中……" << endl;
		}
	}


	cout << "请输入要审核的预约记录（0表示返回）：" << endl;

	int select = 0;
	int result = 0;

	while (true)
	{
		cin >> select;

		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				cout << "-----取消审核-----" << endl;
				break;
			}
			else
			{
				cout << "请输入审核结果：" << endl;
				cout << "1、通过" << endl;
				cout << "2、拒绝" << endl;

				bool flag = false;

				while (true)
				{
					cin >> result;

					if (result >= 1 && result <= 2)
					{

						// 1 审核中		2 预约成功	-1 预约失败		0 取消预约
						if (result == 1)
						{
							of.m_orderData[v[select - 1]]["status"] = "2";
						}
						else if (result == 2)
						{
							of.m_orderData[v[select - 1]]["status"] = "-1";
						}

						of.updataOrder();	// 更新文件

						cout << "审核完成！" << endl;

						flag = true;

						break;
					}

					cout << "输入有误！请重新输入：" << endl;
				}

				if (flag)
				{
					break;
				}

			}
		}

		cout << "输入有误！请重新输入：" << endl;
	}

	finish();

}