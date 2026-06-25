#pragma once			// 防止头文件重复包含
#include <iostream>		// 包含输入输出流头文件
using namespace std;	// 使用标准的命名空间


class workerManager
{
public:
	// 构造函数
	workerManager();

	// 展示菜单
	void showMenu();

	// 退出功能
	void exitSystem();


	
	// 析构函数
	~workerManager();


};