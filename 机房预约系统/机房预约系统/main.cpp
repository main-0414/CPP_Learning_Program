using namespace std;
#include <iostream>
#include "mainMenu.h"
#include "login.h"








int main()
{
	while (true)
	{
		mainMenu();


		int select = 0;
		cin >> select;

		switch (select)
		{
		case 1:		// 学生身份

			Login(STUDENT_FILE, 1);
			break;

		case 2:		// 老师身份

			Login(TEACHER_FILE, 2);
			break;

		case 3:		// 管理员身份

			Login(ADMIN_FILE, 3);
			break;

		case 0:		// 退出系统

			cout << "欢迎下次使用：" << endl;
			system("pause");
			return 0;
		
		default:

			system("cls");
			break;

		}
		
	}


}