#pragma once
using namespace std;
#include <iostream>
#include "Identity.h"

class Teacher:public Identity
{
public:
	// 默认构造
	Teacher();

	// 有参构造
	Teacher(int ID, string name, string password);

	// 菜单界面
	virtual void operMenu();

	// 查看所有预约
	void showAllOrder();

	// 审核预约
	void validOrder();



	int m_Empid;
};