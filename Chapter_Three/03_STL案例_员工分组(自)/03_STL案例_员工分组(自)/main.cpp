//* 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
//* 员工信息由: 姓名、工资组成；部门分为：策划、美术、研发
//* 随机给10名员工分配部门和工资
//* 通过multimap进行信息的插入  key(部门编号) value(员工)
//* 分部门显示员工信息

#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#define CEHUA 1
#define MEISHU 2
#define YANFA 3


class Worker
{
public:
	Worker(string name, int galary)
	{
		m_Name = name;
		m_Galary = galary;
	}

	string m_Name;
	int m_Galary;
};


// 新建员工
void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";

	for (int i = 0; i < 10; i++)
	{
		string name = "员工";
		name += nameSeed[i];

		int galary = rand() % 10001 + 10000;	// 10000 - 20000

		v.push_back(Worker(name, galary));

	}
}


// 分部门
void setGroup(multimap<int, Worker>& m, vector<Worker>& v)
{
	for (vector<Worker>::iterator it = v.begin();it != v.end();it++)
	{
		int num = rand() % 3 + 1;

		m.insert(make_pair(num, *it));
	}
}


// 展示部门
void showGroup(multimap<int, Worker>& m, vector<Worker>& v)
{
	cout << "策划部门：" << endl;

	multimap<int, Worker>::iterator pos = m.find(CEHUA);

	int count = m.count(CEHUA);
	int index = 0;

	for (;pos != m.end() and index < count; index++, pos++)
	{
		cout << "姓名：" << pos->second.m_Name
			<< "  工资：" << pos->second.m_Galary << endl;
	}


	cout << "美术部门：" << endl;

	pos = m.find(MEISHU);

	count = m.count(MEISHU);
	index = 0;

	for (;pos != m.end() and index < count; index++, pos++)
	{
		cout << "姓名：" << pos->second.m_Name
			<< "  工资：" << pos->second.m_Galary << endl;
	}



	cout << "研发部门：" << endl;

	pos = m.find(YANFA);

	count = m.count(YANFA);
	index = 0;

	for (;pos != m.end() and index < count; index++, pos++)
	{
		cout << "姓名：" << pos->second.m_Name
			<< "  工资：" << pos->second.m_Galary << endl;
	}

}



int main()
{
	srand((unsigned)time(nullptr));


	// 创建员工
	vector<Worker> vWorker;
	createWorker(vWorker);

	// 分部门
	multimap<int, Worker> mWorker;
	setGroup(mWorker, vWorker);

	// 展示部门
	showGroup(mWorker, vWorker);



	system("pause");
	return 0;
}

