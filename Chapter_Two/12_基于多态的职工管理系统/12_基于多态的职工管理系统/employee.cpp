#include "employee.h"

Employee::Employee(int ID, string name, int DID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = DID;
}

// 显示个人信息
void Employee::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：完成经理交代的任务" << endl;
}

// 获取岗位名称
string Employee::getDeptName()
{
	return string("员工");
}