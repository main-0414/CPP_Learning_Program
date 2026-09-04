#pragma once
using namespace std;
#include <iostream>
#include <map>
#include <string>
#include "globalFile.h"
#include <fstream>
#include <vector>

class OrderFile
{
public:

	// 构造函数
	OrderFile();

	// 更新预约记录
	void updataOrder();

	// 申请记录的容器		key ----- 哪一条？		value ----- 条内信息
	map<int, map<string, string>> m_orderData;

	// 预约记录条数
	int m_Num;


};