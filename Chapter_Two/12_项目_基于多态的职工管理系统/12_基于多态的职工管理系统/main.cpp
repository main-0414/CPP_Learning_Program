#include <iostream>
#include <string>
#include "workerManager.h"


int main()
{
	// 实例化管理对象
	workerManager wm;
	
	// choice 存储用户选项
	int choice = 0;


	while (true)
	{
		// 展示菜单
		wm.showMenu();

		cout << "请输入您的选择：" << endl;
		cin >> choice;	// 存选择


		switch (choice)
		{
		case 0:		// 退出系统

			wm.exitSystem();
			break;

		case 1:		// 增加职工
			
			wm.Add_Employee();
			break;

		case 2:		// 显示职工

			wm.show_Emp();
			break;	

		case 3:		// 删除职工

			wm.del_Emp();
			break;

		case 4:		// 修改职工

			wm.mod_Emp();
			break;
			
		case 5:		// 查找职工

			wm.find_Emp();
			break;
			
		case 6:		// 排序职工

			wm.sort_Emp();
			break;

		case 7:		// 清空职工

			wm.clean_File();
			break;

		default:
			system("cls");	// 清屏
			break;
		}
	}


}