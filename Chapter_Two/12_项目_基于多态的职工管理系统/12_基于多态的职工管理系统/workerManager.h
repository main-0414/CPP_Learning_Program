#pragma once			// 防止头文件重复包含
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;


class workerManager
{
public:
	// 构造函数
	workerManager();

	// 展示菜单
	void showMenu();

	// 退出功能
	void exitSystem();

	// 记录职工人数
	int m_EmpNum;

	// 职工数组指针
	Worker** m_EmpArray;

	// 添加员工
	void Add_Emp();
	
	// 析构函数
	~workerManager();


};