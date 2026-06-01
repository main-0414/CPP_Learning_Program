#include "showPerson.h"

void showPerson(AddressBook* book)
{
	if (book->size == 0)
	{
		cout << "没有联系人！请先添加！" << endl;
	}
	else
	{
		cout << "显示所有联系人：" << endl;
		for (int i = 0; i < book->size; i++)
		{
			cout << i + 1 << "、"
				<< "姓名：" << book->personArray[i].name << "\t"
				<< " 年龄：" << book->personArray[i].age << "\t"
				<< "性别：" << (book->personArray[i].gender == 1 ? "男" : "女") << "\t"
				<< "电话：" << book->personArray[i].phone << "\t"
				<< "地址：" << book->personArray[i].address << endl;
		}
	}

	system("pause");
	system("cls");
}