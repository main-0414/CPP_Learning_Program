#pragma once
using namespace std;
#include <iostream>
#include "Identity.h"
#include "globalFile.h"
#include <fstream>
#include "finish.h"


class Manager:public Identity
{
public:
	// 默认构造
	Manager();

	// 有参构造	管理员姓名,密码
	Manager(string name, string password);

	// 菜单界面
	virtual void operMenu();

	// 添加账号
	void addPerson();

	// 查看账号
	void showPerson();

	// 查看机房信息
	void showComputerInfo();

	// 清空预约记录
	void cleanFile();


};