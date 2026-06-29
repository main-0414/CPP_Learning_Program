#pragma once		// 防止头文件重复包含
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
using namespace std;

#define FILENAME "Data.txt"


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

	// 职工数组的指针
	Worker** m_EmpArray;

	// 添加员工
	void Add_Employee();

	// 保存数据
	void save();
	
	// 判断文件是否为空的标记
	bool m_FileisEmpty;

	// 统计文件中人数
	int get_EmpNum();

	// 初始化员工
	void init_Emp();

	// 析构函数
	~workerManager();

	
};