#include "workerManager.h"


void workerManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有信息  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}





// 退出系统
void workerManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);	// 退出程序
}




// 构造：要进行属性初始化
workerManager::workerManager()
{
	// 1. 文件不存在

	ifstream ifs;
	ifs.open(FILENAME, ios::in);


	if (!ifs.is_open())	// 判断是否能打开（存在）
	{
		//cout << "文件不存在！" << endl;
		// 初始化属性

		// 初始化记录人数
		this->m_EmpNum = 0;
		// 初始化数组指针
		this->m_EmpArray = nullptr;
		// 初始化标记为空
		this->m_FileisEmpty = true;

		ifs.close();	// 直接退出，不继续读了
		return;			// 退出函数
	}


	// 2. 文件存在，数据为空（用户手动清空数据）

	char ch;
	ifs >> ch;	// 从文件读取一个字符，存到变量 ch 里面。

	if (ifs.eof())	// EOF（End Of File，文件结束标志）只有"读取失败"以后才会置为 true。
	{
		// eof为真，文件为空
		//cout << "文件为空" << endl;

		this->m_EmpNum = 0;

		this->m_EmpArray = nullptr;

		this->m_FileisEmpty = true;

		ifs.close();	// 直接退出，不继续读了
		return;			// 退出函数
	}



	// 3. 当文件有数据


	//cout << "当前人数：" << this->get_EmpNum() << endl;
	this->m_EmpNum = this->get_EmpNum();

	this->m_FileisEmpty = false;

	this->m_EmpArray = new Worker * [this->m_EmpNum];		// 开辟数组，规定容量

	this->init_Emp();	// 将文件中原本的的数据，存到数组中


}



// 统计文件中人数
int workerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	// 打开方式 ———— 读

	string name;
	int ID;
	int DID;

	int num = 0;

	//getline() 是：一整行全部读进一个字符串，它不会帮你拆开。
	while (ifs >> ID >> name >> DID)	// 我们规定了"三个字段组成一个职工对象"。>> 会自动按空格、Tab、换行作为分隔符读取数据。
	{
		num++;
	}

	return num;

}


// 将文件原数据初始化，存入数组中
void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	// 读数据


	int ID;
	int DID;
	string name;

	int index = 0;

	while (ifs >> ID >> name >> DID)
	{
		Worker* original_Worker = nullptr;

		// 根据岗位来具体创建
		if (DID == 1)		// 普通职工
		{
			original_Worker = new Employee(ID, name, DID);
		}
		else if (DID == 2)	// 经理
		{
			original_Worker = new Manager(ID, name, DID);
		}
		else if (DID == 3)	// 总裁
		{
			original_Worker = new Boss(ID, name, DID);
		}

		this->m_EmpArray[index++] = original_Worker;	// 把文件原本的职工创建出来放进数组
	}

	// 关闭文件
	ifs.close();


}




// 添加职工
void workerManager::Add_Employee()
{
	cout << "请输入添加职工的数量：" << endl;


	int addNum = 0;		// 保存用户输入增加的数量
	cin >> addNum;


	if (addNum > 0)
	{
		// 添加
		// 计算新建空间大小
		int newSize = this->m_EmpNum + addNum;	// 新建空间大小 = 原记录人数 + 新增人数



		// 开辟（动态的）新空间
		Worker** newSpace = new Worker * [newSize];	// 在堆区开辟一个连续的空间，里面存放了newSize个 Worker* 类型的指针
		// Worker** ：指向"指针数组"的指针



		// 将原空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != nullptr)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];		// 复制的不是Employee对象，而是Worker*指针
			}
		}


		// 记录新职工开始存放的位置（原有职工后面的第一个位置）
		int next = this->m_EmpNum;


		// 批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int ID;			// 职工编号
			string name;	// 职工姓名
			int deptSelect;	// 部门选择


			// 检查添加的编号是否重复
			while (true)
			{
				bool repeat = false;

				cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
				cin >> ID;

				for (int j = 0; j < next; j++)		// j < next保证新添加的员工编号也会被检查
				{
					if (newSpace[j]->m_ID == ID)	// 用newSpace[j]不会数组越界
					{
						repeat = true;
						break;
					}
				}


				if (repeat)
				{
					cout << "编号重复，请重新输入编号!" << endl;
				}
				else
				{
					break;
				}
			}


			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;


			while (true)
			{
				cout << "请输入第" << i + 1 << "个新职工岗位：" << endl
					<< "1、普通员工" << endl
					<< "2、经理" << endl
					<< "3、总裁" << endl;
				cin >> deptSelect;


				if (deptSelect >= 1 && deptSelect <= 3)
				{
					break;
				}
				else
				{
					cout << "岗位输入错误，请重新输入!" << endl;
				}

			}



			// 根据岗位new出不同的对象
			Worker* new_Worker = nullptr;


			switch (deptSelect)
			{
			case 1:
				new_Worker = new Employee(ID, name, deptSelect);
				break;

			case 2:
				new_Worker = new Manager(ID, name, deptSelect);
				break;

			case 3:
				new_Worker = new Boss(ID, name, deptSelect);
				break;

			default:
				break;
			}


			// 将创建的职工，保存到数组中
			//newSpace[this->m_EmpNum + i] = nWorker;
			newSpace[next++] = new_Worker;

		}

		// 释放原有空间
		delete[] this->m_EmpArray;


		// 更新新空间的指向
		this->m_EmpArray = newSpace;


		// 更新新人数空间大小
		this->m_EmpNum = newSize;


		// 标记改为不为空
		this->m_FileisEmpty = false;


		// 提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;


		// 数据保存
		this->save();

	}
	else { cout << "输入数据有误" << endl; }


	// 按任意键后 回到上级目录
	system("pause");
	system("cls");

}


void workerManager::save()
{
	ofstream ofs;	// 输出文件流（写文件）
	ofs.open(FILENAME, ios::out | ios::trunc);	// 把内存中的所有职工重新保存到文件，重写（以内存数据为准，而不是无脑增加数据）

	// 将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}

	ofs.close();
}



// 显示职工
void workerManager::show_Emp()
{
	// 判断文件是否为空/存在
	if (this->m_FileisEmpty == true)
	{
		cout << "文件记录为空或不存在！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			// 利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	// 按任意键继续，清屏
	system("pause");
	system("cls");

}


// 判断员工是否存在（删除、更改、查找功能关联）
int workerManager::IsExist(int ID)
{

	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == ID)
		{
			//找到返回索引位置
			index = i;

			break;
		}
	}

	return index;

}

// 删除职工
void workerManager::del_Emp()
{
	if (this->m_FileisEmpty == true)
	{
		cout << "文件不存在或为空！" << endl;
	}
	else
	{
		// 按照职工编号来删除职工
		cout << "请输入想删除的职工编号：" << endl;
		int ID;
		cin >> ID;

		int index = this->IsExist(ID);
		if (index == -1)
		{
			cout << "未找到该职工！" << endl;
		}
		else
		{
			delete this->m_EmpArray[index];		// 如果不 delete，这块旧的堆内存没人指向，会造成内存泄漏

			// 删除的本质就是数据迁移
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}

			// 更新职工个数
			this->m_EmpNum--;

			// 避免以后误用已经失效的数组元素
			this->m_EmpArray[this->m_EmpNum] = nullptr;

			// 更新一下标记，防止一次全删数据后不提示 “文件不存在或为空”
			this->m_FileisEmpty = (this->m_EmpNum == 0);

			// 保存文件
			this->save();

			cout << "删除成功！" << endl;
		}
	}

	system("pause");
	system("cls");

}



// 修改职工
void workerManager::mod_Emp()
{
	if (this->m_FileisEmpty)
	{
		cout << "文件不存在 或 记录为空！" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号：" << endl;

		int ID;
		cin >> ID;


		int result = this->IsExist(ID);
		if (result != -1)	// 查找到编号职工
		{

			int newID = 0;
			string newName = "";
			int new_deptSelect = 0;


			// 判断编号是否重复
			while (true)
			{
				bool repeat = false;

				cout << "查找到" << ID << "号职工，请输入新的职工编号：" << endl;
				cin >> newID;

				for (int i = 0; i < this->m_EmpNum; i++)
				{
					// 跳过当前正在修改的员工
					if (i == result)
					{
						continue;
					}

					if (this->m_EmpArray[i]->m_ID == newID)
					{
						repeat = true;
						break;
					}
				}

				if (repeat)
				{
					cout << "编号重复，请重新输入！" << endl;
				}
				else
				{
					break;
				}
			}

			cout << "请输入新的姓名：" << endl;
			cin >> newName;

			while (true)
			{
				cout << "请输入新岗位：" << endl;
				cout << "1、普通员工" << endl
					<< "2、经理" << endl
					<< "3、总裁" << endl;

				cin >> new_deptSelect;

				if (new_deptSelect >= 1 && new_deptSelect <= 3)
				{
					break;
				}
				else
				{
					cout << "岗位输入错误，请重新输入！" << endl;
				}

			}


			// 根据岗位new出不同的对象
			Worker* new_Worker = nullptr;

			switch (new_deptSelect)
			{
			case 1:
				new_Worker = new Employee(newID, newName, new_deptSelect);
				break;

			case 2:
				new_Worker = new Manager(newID, newName, new_deptSelect);
				break;

			case 3:
				new_Worker = new Boss(newID, newName, new_deptSelect);
				break;

			default:
				break;
			}


			// 删除旧对象
			delete this->m_EmpArray[result];
			this->m_EmpArray[result] = nullptr;


			// 放入新对象
			this->m_EmpArray[result] = new_Worker;


			cout << "修改成功!" << endl;

			this->save();
		}
		else
		{
			cout << "修改失败，查无此人！" << endl;
		}
	}

	system("pause");
	system("cls");
}



// 查找职工
void workerManager::find_Emp()
{
	if (m_FileisEmpty)
	{
		cout << "文件不存在 或 记录为空！" << endl;
	}
	else
	{
		while (true)
		{
			cout << "请输入查找方式：" << endl
				<< "1、按照 ID 查找" << endl
				<< "2、按照 姓名 查找" << endl;

			int select = 0;
			cin >> select;

			if (select == 1 or select == 2)
			{
				if (select == 1)
				{
					int ID;
					cout << "请输入查找的编号：";
					cin >> ID;

					int result = IsExist(ID);

					if (result != -1)
					{
						cout << "查找成功！该职工信息如下：" << endl;
						this->m_EmpArray[result]->showInfo();
					}
					else
					{
						cout << "查无此人！" << endl;
					}
				}
				else if (select == 2)
				{
					string name;
					cout << "请输入查找职工的姓名：";
					cin >> name;

					bool Find = false;	// 找到的标记

					for (int i = 0; i < m_EmpNum; i++)
					{
						if (this->m_EmpArray[i]->m_Name == name)
						{
							cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_ID << " 的职工信息如下：" << endl;

							Find = true;

							this->m_EmpArray[i]->showInfo();

						}
					}

					if (!Find)
					{
						cout << "查无此人！" << endl;
					}

				}

				break;
			}
			else
			{
				cout << "输入有误！请重新输入！" << endl;
			}
		}
	}

	system("pause");
	system("cls");

}




// 按照ID排序
void workerManager::sort_Emp()
{
	if (m_FileisEmpty)
	{
		cout << "文件不存在 或 记录为空！" << endl;

		system("pause");
		system("cls");
	}
	else
	{
		bool sort = false;
		while (true)
		{
			cout << "请输入排序方式：" << endl
				<< "1、按照ID 升序" << endl
				<< "2、按照ID 降序" << endl;

			int select = 0;
			cin >> select;

			

			if (select == 1)	// 升序
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					int MinOrMax = i;	// MinOrMax 放整个数组 最小或最大 的数，假设是第i个

					for (int j = i + 1; j < this->m_EmpNum; j++)
					{
						if (this->m_EmpArray[MinOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
						{
							MinOrMax = j;	// 每次往后面的数值比较，找到更小的就更新下标，直到找到当次循环最小的值的下标
						}
					}

					// 看当次循环的定数，是不是真正的 最小值 或 最大值，如果不是 交换数据
					if (i != MinOrMax)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
						this->m_EmpArray[MinOrMax] = temp;
					}
				}

				sort = true;
				break;
			}
			else if (select == 2)	// 降序
			{
				for (int i = 0; i < this->m_EmpNum; i++)
				{
					int MinOrMax = i;	// 声明最小值下表 或者 最大值下标

					for (int j = i+1; j < this->m_EmpNum; j++)
					{
						if (this->m_EmpArray[MinOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
						{
							MinOrMax = j;	// 更新下标
						}
					}

					if (i != MinOrMax)
					{
						Worker* temp = this->m_EmpArray[i];
						this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
						this->m_EmpArray[MinOrMax] = temp;
					}

				}

				sort = true;
				break;
			}
			else
			{
				cout << "输入有误！请重新输入！" << endl;
			}
		}

		if (sort)
		{
			cout << "排序成功！" << endl;
			this->save();
			this->show_Emp();	// 展示所有职工。因为显示职工函数已经有清屏所以不用再写了
		}
	}

}




// 清空文件
void workerManager::clean_File()
{
	cout << "确定清空吗？" << endl
		<< "1、确定" << endl
		<< "2、取消" << endl;

	int select = 0;
	cin >> select;

	switch (select)
	{
	case 1:
	{
		ofstream ofs;

		ofs.open(FILENAME, ios::trunc);		// 打开模式 ios::trunc 如果存在删除文件并重新创建
		ofs.close();

		if (this->m_EmpArray !=nullptr)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];

			}
			
			delete[] this->m_EmpArray;	// 删除数组指针
			this->m_EmpArray = nullptr;	// 置空
			this->m_FileisEmpty = true;	// 更新标记
			this->m_EmpNum = 0;			// 更新人数

		}

		cout << "清空成功！" << endl;
		break;
	}
		
	default:
		cout << "已取消！" << endl;
		break;
	}

	system("pause");
	system("cls");
}




// 析构函数
workerManager::~workerManager()
{
	if (this->m_EmpArray != nullptr)
	{
		// 得先释放数组内各个职工
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
			//this->m_EmpArray[i] = nullptr;	// 这个指针马上连同整个数组一起销毁了，所以置空没有意义。置空意义只存在于这块空间以后还要用
		}

		// 再释放数组指针
		delete[] m_EmpArray;
		m_EmpArray = nullptr;
	}
}