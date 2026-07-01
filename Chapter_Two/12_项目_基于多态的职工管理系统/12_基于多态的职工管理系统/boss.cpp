#include "boss.h"

Boss::Boss(int ID, string name, int DID)
{
	this->m_ID = ID;
	this->m_Name = name;
	this->m_DeptID = DID;
}

void Boss::showInfo()
{
	cout << left;
	cout << "职工编号：" << setw(10) << this->m_ID
		<< "姓名：" << setw(10) << this->m_Name
		<< "岗位：" << setw(10) << this->getDeptName()
		<< "岗位职责：管理公司所有事务" << endl;
}


string Boss::getDeptName()
{
	return string("总裁");
}