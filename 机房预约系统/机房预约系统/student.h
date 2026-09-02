#pragma once
using namespace std;
#include <iostream>
#include "Identity.h"


class Student:public Identity
{
public:

	// 默认构造
	Student();
	
	// 有参构造
	Student(int ID, string name, string password);
	
	// 操作界面
	virtual void operMenu();	// 子类重载
	
	// 申请预约
	void applyOrder();

	// 查看我的预约
	void showMyOrder();

	// 查看所有预约
	void showAllOrder();

	// 取消预约
	void cancelOrder();


	int m_StuID;
};
