// 普通员工文件
#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Employee :public Worker
{
public:
	// 创建时要初始化职工属性
	Employee(int ID,string name,int DID);

	// 显示个人信息
	virtual void showInfo();

	// 获取岗位名称
	virtual string getDeptName();
};