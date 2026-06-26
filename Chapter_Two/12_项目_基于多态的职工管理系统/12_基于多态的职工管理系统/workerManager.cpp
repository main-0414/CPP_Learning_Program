#include "workerManager.h"

workerManager::workerManager()
{
	// 初始化属性
	this->m_EmpNum = 0;
	this->m_EmpArray = nullptr;
}

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
		Worker** newSpace = new Worker* [newSize];	// 在堆区开辟一个连续的空间，里面存放了newSize个 Worker* 类型的指针
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
			Worker* nWorker = nullptr;


			switch (deptSelect)
			{
			case 1:
				nWorker = new Employee(ID, name, 1);
				break;

			case 2:
				nWorker = new Manager(ID, name, 2);
				break;

			case 3:
				nWorker = new Boss(ID, name, 3);
				break;

			default:
				break;
			}


			// 将创建的职工，保存到数组中
			//newSpace[this->m_EmpNum + i] = nWorker;
			newSpace[next] = nWorker;
			next++;

		}

		// 释放原有空间
		delete[] this->m_EmpArray;


		// 更新新空间的指向
		this->m_EmpArray = newSpace;


		// 更新新人数空间大小
		this->m_EmpNum = newSize;


		// 提示添加成功
		cout << "成功添加" << addNum << "名新职工！" << endl;

	}
	else { cout << "输入数据有误" << endl; }


	// 按任意键后 回到上级目录
	system("pause");
	system("cls");

}







void workerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);	// 退出程序
}








workerManager::~workerManager()
{

}