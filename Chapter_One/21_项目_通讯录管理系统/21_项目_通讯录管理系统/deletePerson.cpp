#include "deletePerson.h"

void deletePerson(AddressBook* bookk)
{
	if (bookk->size == 0)
	{
		cout << "没有联系人，请先添加！" << endl;
	}
	else
	{ 
		cout << "请输入你要删除的姓名：";
		string name; cin >> name;

		//result == -1 未查到
		//result != -1 有查到
		int result = personExist(bookk, name);
		//delertePerson要求传进来的bookk已经是一个地址了，无需 &

		if (result != -1)
		{
			for (int i = result; i < bookk->size - 1; i++)
				//当数组最大人数时，bookk->size - 1不会越界报错
			{
				bookk->personArray[i] = bookk->personArray[i + 1];
			}
			bookk->size--;	//减少一个人，这样下标最后一人会被截断不进循环，被截断

			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "查无此人！！" << endl;
		}
	}

	system("pause");
	system("cls");

}