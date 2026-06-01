#include "findPerson.h"

void findPerson(AddressBook* book)
{
	if (book->size == 0)
	{
		cout << "请先添加联系人！" << endl;
	}
	else
	{
		cout << "请输入您要查找的联系人：";
		string name; cin >> name;

		// 判断输入联系人是否在通讯录中
		int result = personExist(book, name);

		if (result != -1)
		{
			cout << endl;
			cout << "姓名：" << book->personArray[result].name << "\t"
				<< " 年龄：" << book->personArray[result].age << "\t"
				<< "性别：" << (book->personArray[result].gender == 1 ? "男" : "女") << "\t"
				<< "电话：" << book->personArray[result].phone << "\t"
				<< "地址：" << book->personArray[result].address << "\t" << endl;
		}
		else
		{
			cout << "查无此人！" << endl;
		}
	}


	system("pause");
	system("cls");

}