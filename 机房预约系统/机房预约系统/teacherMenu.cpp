#include "teacherMenu.h"

void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* s = (Teacher*)teacher;

		int select = 0;

		while (true)
		{
			cin >> select;

			if (select>=0 && select<=2)
			{
				break;
			}

			cout << "输入有误！请重新输入：" << endl;
		}


		if (select == 1)		// 查看所有预约
		{
			cout << "-----查看所有预约-----" << endl;
			s->showAllOrder();
		}
		else if (select == 2)	// 查看我的预约
		{
			cout << "-----审核预约-----" << endl;
			s->validOrder();
		}
		else
		{
			cout << "-----注销成功！-----" << endl;
			delete teacher;
			finish();
			return;
		}
	}
}