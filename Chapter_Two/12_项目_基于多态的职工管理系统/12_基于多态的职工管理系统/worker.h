#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;



class Worker
{
public:
	// 显示个人信息
	virtual void showInfo() = 0;

	// 获取岗位名称
	virtual string getDeptName() = 0;
		

	int m_ID;		// 职工编号
	int m_DeptID;	// 职工所在岗位编号
	string m_Name;	// 职工姓名

};
