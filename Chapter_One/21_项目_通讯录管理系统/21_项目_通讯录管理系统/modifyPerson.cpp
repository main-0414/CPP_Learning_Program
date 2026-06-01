#include "modifyPerson.h"

void modifyPerson(AddressBook* book)
{
	if (book->size == 0)
	{
		cout << "请先添加联系人！" << endl;
	}
	else
	{
		cout << "请输入要修改的联系人：";
		string name; cin >> name;

		int result = personExist(book, name);
		if (result != -1)
		{
			bool flag = true;
			while (flag)
			{
				cout << endl;
				cout << "您要修改的联系人是：" << book->personArray[result].name
					<< "，请选择要修改的属性：" << endl
					<< "1 --- 姓名" << endl
					<< "2 --- 年龄" << endl
					<< "3 --- 性别" << endl
					<< "4 --- 电话" << endl
					<< "5 --- 地址" << endl
					<< "0 --- 修改完毕" << endl;

				int select = 0; cin >> select;

				switch (select)
				{
				case 1:
				{
					cout << "请输入姓名：";
					string motify_name;
					while (true)
					{
						cin >> motify_name;
						bool ischar = true;
						for (char c : motify_name)
						{
							if (isdigit(static_cast<unsigned char>(c)))
							{
								ischar = false;
								break;
							}
						}

						if (!ischar)
						{
							cout << "姓名不合法！请重新输入：";
							continue;
						}

						break;
					}
					book->personArray[result].name = motify_name;
					break;
				}

				case 2:
				{
					cout << "请输入年龄：";
					int modify_age;
					while (true)
					{
						cin >> modify_age;

						if (!cin)
						{
							cin.clear();	// 清除错误状态
							cin.ignore(10000, '\n');

							cout << "输入无效，请重新输入年龄：" << endl;
							continue;	//跳回循环开头
						}

						if (modify_age > 0 && modify_age <= 120)
						{
							book->personArray[result].age = modify_age;
							break;
						}
						else
						{
							cout << "超出正常人年龄，请重输：";
						}
					}
					break;
				}

				case 3:
				{
					cout << "修改当前联系人性别为（1-男 2-女）：";
					int modify_gender;
					while (true)
					{
						cin >> modify_gender;
						if (!cin)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "输入无效，请重新输入性别（1 或 2）：" << endl;
							continue;
						}
						if (modify_gender == 1 || modify_gender == 2)
						{
							book->personArray[result].gender = modify_gender;
							break;
						}
						cout << "输入错误！请输入 1 或 2：";
					}
					break;
				}

				case 4:
				{
					cout << endl << "请输入电话号码：";
					string motify_phone;
					while (true)
					{
						cin >> motify_phone;

						// 判断是否为纯数字
						bool isnum = true;

						for (char c : motify_phone)	//范围for循环
						{
							if (!isdigit(static_cast<unsigned char> (c)))
							{
								isnum = false;
								break;
							}
						}

						if (!isnum)
						{
							cout << "号码包含非数字字符！请输入纯数字：";
							continue;	//跳过，回到循环开头
						}

						// 判断是否为11位数字
						if (motify_phone.length() != 11)	// 字符串.length() ————>获取字符串长度
						{
							cout << "手机号长度错误，请重新输入：";
							continue;
						}

						break;	// 走到这说明校验完毕没问题，那就退出while，进行赋值
					}
					book->personArray[result].phone = motify_phone; cout << endl;
					break;
				}

				case 5:
				{
					cout << "请输入地址：";
					cin >> book->personArray[result].address;
					break;
				}

				case 0:
					// 选择 0 表示修改完毕，不做修改
					flag = false;
					break;
				default:
					cout << "输入错误！请输入0-5的数字！" << endl;
					system("pause");
					system("cls");
					break;
				}
			}

			cout << endl;
			cout << "完毕！当前联系人属性：" << endl
				<< "姓名：" << book->personArray[result].name << "\t"
				<< " 年龄：" << book->personArray[result].age << "\t"
				<< "性别：" << (book->personArray[result].gender == 1 ? "男" : "女") << "\t"
				<< "电话：" << book->personArray[result].phone << "\t"
				<< "地址：" << book->personArray[result].address << "\t" << endl;


		}
		else
		{
			cout << "查无此人！！" << endl;
		}
	}


	system("pause");
	system("cls");
}