#include "managerMenu.h"

void managerMenu(Identity*& manager)
{
	while (true)
	{
		// 调用管理员子菜单，父类指针调用子类对象(多态)
		manager->operMenu();

		// 想要调用子类的接口还得转换回来
		Manager* m = (Manager*)manager;
		

		int select = 0;
		cin >> select;


		if (select==1)			// 添加账号
		{
			cout << "-----添加账号-----" << endl;
			m->addPerson();

		}
		else if (select==2)		// 查看账号
		{
			cout << "-----查看账号-----" << endl;
			m->showPerson();
		}
		else if (select == 3)	// 查看机房
		{
			cout << "-----查看机房-----" << endl;
			m->showComputerInfo();
		}
		else if (select==4)		// 清空预约
		{
			cout << "-----清空预约-----" << endl;
			m->cleanFile();
		}
		else					// 注销登录
		{
			delete manager;	// 销毁堆区对象
			cout << "注销成功！" << endl;
			finish();
			return;
		}

	}


}