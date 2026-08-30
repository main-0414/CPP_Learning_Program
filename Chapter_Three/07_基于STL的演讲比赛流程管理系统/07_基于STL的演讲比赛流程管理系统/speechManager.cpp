#include "speechManager.h"

// 构造
SpeechManager::SpeechManager()
{
	this->reset();

	// 加载往届记录
	this->loadRecord();
}

// 包装初始化
void SpeechManager::reset()
{
	// 初始化容器和属性
	this->initSpeech();

	// 创建选手
	this->createSpeaker();

}


// 展示菜单
void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


// 退出系统
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}



// 初始化
void SpeechManager::initSpeech()
{
	// 保证容器为空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();


	// 初始化比赛轮数
	this->m_Index = 1;
}



// 创建选手
void SpeechManager::createSpeaker()
{
	const string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;

		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}

		// 存放到map容器中
		m_Speaker.insert(make_pair(i + 10001, sp));

		// v1容器存放下所有选手(编号)
		v1.push_back(i + 10001);

	}
}


// 抽签
void SpeechManager::speechDraw()
{
	cout << "第 << " << this->m_Index << " >> 轮比赛选手正在抽签" << endl;
	cout << "-------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (m_Index == 1)
	{
		// 第一轮比赛
		shuffle(v1.begin(), v1.end(), gen);		// 洗牌算法打乱

		for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;

	}
	else
	{
		// 第二轮比赛
		shuffle(v2.begin(), v2.end(), gen);

		for (vector<int>::iterator it = v2.begin(); it < v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	cout << "-------------------" << endl;
	system("pause");
	cout << endl;

}


// 显示晋级结果
void SpeechManager::showScore()
{
	cout << "---------第 " << this->m_Index << " 轮晋级选手信息如下：-----------" << endl;

	// 依旧创建一个临时容器，如果是第一轮就复制v2，否则vVictory

	vector<int> vTemp;

	if (m_Index == 1)
	{
		vTemp = v2;
	}
	else
	{
		vTemp = vVictory;
	}


	for (vector<int>::iterator it = vTemp.begin(); it != vTemp.end(); it++)
	{
		cout << "选手编号：" << *it
			<< "   姓名：" << m_Speaker[*it].m_Name
			<< "   分数：" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}
	cout << endl;


	system("pause");
	system("cls");


}


// 保存结果到文件
void SpeechManager::saveRecord()
{
	ofstream ofs;

	ofs.open(FILENAME, ios::out | ios::app);	// “|” 把两个打开模式组合成一个模式。用追加方式写文件

	// 将每个选手的数据 写入到文件中
	for (vector<int>::iterator it = vVictory.begin();it != vVictory.end();it++)
	{

		ofs << *it << ","
			<< m_Speaker[*it].m_Score[1] << ",";	// 一行是一届比赛，逗号分隔数据

	}
	ofs << endl;	// 往文件里写一个换行



	ofs.close();	// 关闭文件

	cout << "记录已经保存！" << endl;

	m_FileIsEmpty = false;
}


// 显示往届记录
void SpeechManager::showRecord()
{
	if (m_FileIsEmpty)
	{
		cout << "文件或数据为空！" << endl;
		system("pause");
		system("cls");
		return;		// 直接退出函数
	}

	for (int i = 0; i < m_Record.size(); i++)
	{
		vector<string> v = m_Record[i];

		cout << "第 " << i + 1 << " 届"
			<< "	冠军编号：" << v[0] << "  得分：" << v[1]
			<< "	亚军编号：" << v[2] << "  得分：" << v[3]
			<< "	季军编号：" << v[4] << "  得分：" << v[5] << endl;

	}

	system("pause");
	system("cls");

}

// 清空数据
void SpeechManager::dataClear()
{
	int index = 0;

	cout << "是否清空？" << endl
		<< "1、确认" << endl
		<< "2、取消" << endl;

	cin >> index;

	if (index==1)
	{
		ofstream ofs(FILENAME, ios::out | ios::trunc);

		cout << "已清空数据！" << endl;

		ofs.close();

		this->reset();

		this->loadRecord();
	}
	
	system("pause");
	system("cls");
}




// 开始比赛
void SpeechManager::startSpeech()
{
	// 初始化
	this->reset();


	//第一轮比赛
	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechCompetition();

	//3、显示晋级结果
	this->showScore();
	this->show_Menu();


	//第二轮比赛
	m_Index++;

	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechCompetition();

	//3、显示最终结果
	this->showScore();
	this->show_Menu();

	//4、保存分数
	this->saveRecord();

	// 更新数据
	this->loadRecord();


	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}