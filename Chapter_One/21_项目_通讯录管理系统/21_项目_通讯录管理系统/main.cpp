#include <iostream>
#include <string>
#include "showMenu.h"
#include "struct.h"
#include "addPerson.h"
#include "showPerson.h"
#include "personExist.h"
#include "deletePerson.h"
#include "findPerson.h"
#include "modifyPerson.h"
#include "cleanPerson.h"
using namespace std;


int main()
{
	//创建通讯录结构体变量
	struct AddressBook book;		//建立一个叫book的“通讯录本体”
								//以后增删改查全部在book结构体变量里操作
	//初始化通讯录当前人数
	book.size = 0;

	while (true)
	{
		
		showMenu();	// 显示菜单

		int select = 0;
		cin >> select;

		switch (select)
		{

		case 1:		// 1、添加联系人
			addPerson(&book);	//利用地址传递修饰实参
			break;

		case 2:		// 2、显示联系人
			showPerson(&book);
			break;

		case 3:		// 3、删除联系人
/*		{	// test

			string name;
			cout << "请输入要查找的联系人姓名：" << endl;cin >> name;
			if (personExist(&book, name) == -1)
			{
				cout << "查无此人！" << endl;
			}
			else
			{
				cout << "找到了！" << endl;
			}
		}*/
			deletePerson(&book);
			break;

		case 4:		// 4、查找联系人
			findPerson(&book);
			break;

		case 5:		// 5、修改联系人
			modifyPerson(&book);
			break;

		case 6:		// 6、清空联系人
			cleanPerson(&book);
			break;

		case 0:		// 0、退出通讯录

			cout << "已退出！欢迎下次使用！" << endl;
			system("pause");
			return 0;	// 退出主函数

		default:

			cout << "输入无效，请输入 0-6 之间的数字！" << endl;
			system("pause");	//任意键继续
			system("cls");		//清屏
			break;	  // 退出当前循环 / switch

		}
	}

}