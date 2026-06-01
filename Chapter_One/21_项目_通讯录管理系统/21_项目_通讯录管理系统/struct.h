//因为结构体要给所有文件共用！不能只放在 main 里！
#pragma once
#include <iostream>
#include <string>
using namespace std;
#define MAX 1000


// 联系人结构体
struct Person
{
	string name;
	int age;
	int gender;
	string phone;
	string address;
};

// 通讯录结构体————> 通讯录 = 装着一叠名片 + 记录当前数量的本子
struct AddressBook	// 建立一个通讯录的框架
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];	//定义一个能装MAX个Person类型的数组，名字叫personArray。

	//通讯录中当前记录联系人个数
	int size;
};
