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

	this->m_EmpArray = new Worker* [this->m_EmpNum];		// 开辟数组，规定容量

	this->init_Emp();	// 将文件中原本的的数据，存到数组中

	//// 测试：
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工ID：" << this->m_EmpArray[i]->m_ID
	//		<< " 职工姓名：" << this->m_EmpArray[i]->m_Name
	//		<< " 部门ID：" << this->m_EmpArray[i]->m_DeptID << endl;
	//}
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

	while (ifs >> ID >> name >> DID)	// 我们规定了"三个字段组成一个职工对象"。“>>” 通过空格来确定每个属性
	{
		num++;
	}

	return num;

}


// 将文件原数据存入数组中
void workerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);


	int ID;
	int DID;
	string name;

	int index = 0;

	while (ifs >> ID >> name >> DID)
	{
		Worker* original_Worker = nullptr;

		// 根据部门来具体创建
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

			cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
			cin >> ID;

			cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
			cin >> name;

			cout << "请输入第" << i + 1 << "个新职工部门：" << endl
				<< "1、普通员工" << endl
				<< "2、经理" << endl
				<< "3、总裁" << endl;
			cin >> deptSelect;


			// 不同部门选择要new出不同的对象
			Worker* new_Worker = nullptr;


			switch (deptSelect)
			{
			case 1:
				new_Worker = new Employee(ID, name, 1);
				break;

			case 2:
				new_Worker = new Manager(ID, name, 2);
				break;

			case 3:
				new_Worker = new Boss(ID, name, 3);
				break;

			default:
				break;
			}


			// 将创建的职工，保存到数组中
			//newSpace[this->m_EmpNum + i] = nWorker;
			newSpace[next] = new_Worker;
			next++;

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
	ofstream ofs;
	ofs.open(FILENAME, ios::out | ios::trunc);	// 追加写入文件（保留原有内容）

	// 将每个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< "\t" << this->m_EmpArray[i]->m_Name << " "
			<< "\t" << this->m_EmpArray[i]->m_DeptID << endl;
	}

	ofs.close();
}












// 退出系统
void workerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);	// 退出程序
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