#include "speechManager.h"

// 构造
SpeechManager::SpeechManager()
{
	// 初始化容器和属性
	this->initSpeech();

	// 添加选手
	this->createSpeaker();
}

// 析构
SpeechManager::~SpeechManager()
{

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



void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	
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

	if (m_Index==1)
	{
		// 第一轮比赛
		shuffle(v1.begin(), v1.end(), gen);

		for (vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;

	}
	else
	{
		// 第二轮比赛
		shuffle(v2.begin(), v2.end(), mt19937(random_device{}()));

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



// 开始比赛
void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechCompetition();


	//3、显示晋级结果



	//第二轮比赛
	//1、抽签



	//2、比赛



	//3、显示最终结果



	//4、保存分数



}