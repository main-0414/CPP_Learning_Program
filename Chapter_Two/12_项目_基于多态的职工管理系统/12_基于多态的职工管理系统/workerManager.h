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

	// 显示职工
	void show_Emp();

	// 删除职工
	void del_Emp();

	// 判断员工是否存在
	int IsExist(int ID);

	// 修改职工
	void mod_Emp();

	// 查找职工
	void find_Emp();

	// 按照ID排序
	void sort_Emp();


	// 析构函数
	~workerManager();

	
};