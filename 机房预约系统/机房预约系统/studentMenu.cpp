#include "studentMenu.h"

void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();

		Student* s = (Student*)student;

		int select = 0;

		while (true)
		{
			cin >> select;

			if (select >= 0 && select <= 4)
			{
				break;
			}

			cout << "输入有误！请重新输入：" << endl;
		}

		if (select==1)		// 申请预约
		{
			cout << "-----申请预约-----" << endl;
			s->applyOrder();
		}
		else if (select==2)	// 查看我的预约
		{
			cout << "-----查看我的预约-----" << endl;
			s->showMyOrder();
		}
		else if (select==3)	// 查看所有预约
		{
			cout << "-----查看所有预约-----" << endl;
			s->showAllOrder();
		}
		else if (select==4)	// 取消预约
		{
			cout << "-----取消预约-----" << endl;
			s->cancelOrder();
		}
		else
		{
			cout << "-----注销成功！-----" << endl;
			delete student;
			finish();
			return;
		}
	}

}