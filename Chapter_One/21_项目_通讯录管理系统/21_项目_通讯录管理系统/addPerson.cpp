#include "addPerson.h"

void addPerson(struct AddressBook* book)
{
	// 先判断通讯录是否满人
	if (book->size == MAX)
	{
		cout << "通讯录已满！无法添加！！";
		return;		//return = 直接结束整个函数，break是退出循环/判断
		//void类型函数无需返回某种类型所以无需return 0
	}
	else
	{
		// 1、输入姓名
		cout << "请输入姓名：";
		string name;
		while (true)
		{
			cin >> name;
			bool ischar = true;
			for (char c : name)
			{
				if (isdigit(static_cast<unsigned char> (c)))
					// isdigit(c)，c=中文、符号、特殊字符时char类型会变成负数
					// 而isdigit()不能接收负数，
					// 所以 static_cast<unsigned char> 把 c 强制转换为无符号字符
					// 再交给 isdigit 判断，保证不崩溃
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
		book->personArray[book->size].name = name; cout << endl;


		// 2、输入年龄
		cout << "请输入年龄：";
		int age;
		while (true)
		{
			cin >> age;

			if (!cin)	//如果cin读取错误时，下面两行代码可以防止无限循环报错
			{
				cin.clear();	// 清除错误状态
				cin.ignore(10000, '\n');
				// 清除缓冲区垃圾，从左往右删除，
				// 参数一：最多清掉 10000 个字符
				// 参数二：删到\n且包括\n							

				//cin.ignore() 的第二个参数要求是单个字符（char 类型）

				cout << "输入无效，请重新输入年龄：" << endl;
				continue;	//跳过后面的所有代码，直接回到循环开头
			}

			if (age > 0 && age <= 120)
			{
				book->personArray[book->size].age = age;
				break;
			}
			else
			{
				cout << "超出正常人年龄，请重输：";
			}
		}


		// 3、输入性别
		cout << endl << "1---男" << endl << "2---女" << endl;
		cout << "请输入性别：";
		int gender;
		while (true)
		{
			cin >> gender;

			if (!cin)	//如果cin读取错误时，下面两行代码可以防止无限循环报错
			{
				cin.clear();
				cin.ignore(10000, '\n');

				cout << "输入无效，请输入1或2：" << endl;
				continue;	//跳过后面的所有代码，直接回到循环开头
			}

			if (gender == 1 || gender == 2)
			{
				book->personArray[book->size].gender = gender;
				break;
			}
			cout << "错误！请输入1或2：";
		}


		// 4、输入电话号码
		cout << endl << "请输入电话号码：";
		string phone;
		while (true)
		{
			cin >> phone;

			// 判断是否为纯数字
			bool isnum = true;
			/*传统遍历字符串写法
			for (int i = 0; i < phone.length(); i++)
			{
				char c = phone[i];
			}
			*/
			for (char c : phone)	//范围for循环
			{
				/*				范围for循环专门用来遍历字符串、数组、容器，
								char c：定义一个变量，用来存当前拿出来的字符
								: 固定符号
								phone：你要遍历的字符串                                      */
				if (!isdigit( static_cast<unsigned char> (c) ))
					//isdigit(c) 判断c变量是否为 0-9 的数字			
				{
					// 如果c是一个字母，那么函数返回一个False，！再取反那么变成True，
					// 那么if(true)，程序就会进判断体里进行isnum=false操作
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
			if (phone.length() != 11)	// 字符串.length() ————>获取字符串长度
			{
				cout << "手机号长度错误，请重新输入：";
				continue;
			}

			break;	// 走到这说明校验完毕没问题，那就退出while，进行赋值
		}
		book->personArray[book->size].phone = phone; cout << endl;


		// 5、输入地址
		cout << "请输入地址：";
		cin >> book->personArray[book->size].address; cout << endl;

		// book是传进函数的指针变量，要用指针用->访问成员，
		// personArray[]，得到的是一个普通的Person变量，它不是指针！
		// 访问普通结构体变量要用 .
		// 注意！[]里不能直接写size，size不是独立变量！它是通讯录book里面的成员！


		book->size++;		// 添加完人数加 1

		cout << "完成添加联系人！" << endl;

		system("pause");	// 任意键继续
		system("cls");		// 清屏
	}
}