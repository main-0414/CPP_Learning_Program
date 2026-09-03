#include "studentMenu.h"

void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();

		Student* s = (Student*)student;

		int select = 0;
		cin >> select;

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
		}
		else
		{
			cout << "注销账号" << endl;
			delete student;
			finish();
			return;
		}
	}

}