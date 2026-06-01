#include "cleanPerson.h"

void cleanPerson(AddressBook* book)
{
	cout << "确认清空通讯录？" << endl << "输入 1 为确认！其他数字为取消" << endl;

	bool flag = true;
	while (flag)
	{
		int select = 0; cin >> select;

		if (!cin)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "请重新输入：";
			continue;
		}
		else
		{
			switch (select)
			{
			case 1:
				book->size = 0;
				cout << "已清空！" << endl;
				flag = false;
				break;

			default:
				cout << "退出清空！" << endl;
				flag = false;
				break;
			}
		}

	}

	system("pause");
	system("cls");

}