#include "boss.h"

Boss::Boss(int ID, string name, int DID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = DID;
}

void Boss::showInfo()
{
	cout << "职工编号：" << this->m_ID
		<< "\t姓名：" << this->m_Name
		<< "\t岗位：" << this->getDeptName()
		<< "\t岗位职责：管理公司所有事务" << endl;
}


string Boss::getDeptName()
{
	return string("总裁");
}