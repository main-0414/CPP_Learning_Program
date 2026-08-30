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


// 创建选手
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

	this->show_Menu();

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
}


// 加载数据
void SpeechManager::loadRecord()
{
	ifstream ifs(FILENAME, ios::in);	// 打开方式：读文件

	// 1. 文件不存在
	if (!ifs.is_open())		// 返回false，那么表示文件不存在
	{
		this->m_FileIsEmpty = true;
		cout << "文件不存在" << endl;
		ifs.close();
		return;		// 直接退出函数
	}


/*
	// 判断文件是否为空：
	// 方法一： 
	// 逻辑：先读一个字符试试看文件有没有内容，如果有，再把这个字符放回去puback()，让后面的代码正常读取整个文件。

	char ch;
	ifs >> ch;	// 从文件中读取第一个字符，存入 ch 里
	// 必须得读一次才知道读取成功与否
	if (ifs.eof())	// 如果读取失败了，那么eof()会返回true

	*/

	// 方法二： ————> peek()	只看（复制）下一个字符，不取走。
	// peek() 返回的是一个值，而 eof() 是一个函数。
	// 所以不应该写 if (ifs.eof())，而是 if (ifs.peek() == EOF) （EOF:文件结束标志）

	// 2. 文件存在无数据
	if (ifs.peek() == EOF)
	{
		cout << "文件为空！" << endl;

		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	else	// 有文件有数据
	{
		m_FileIsEmpty = false;

		//ifs.putback(ch);	// puback(ch) 把刚才读取的单个字符放回来

		string data;

		int index = 0;	// 届

		while (ifs >> data)		// 现在是读出一行数据，因为不是用空格来分割
		{
			// 10011,85.03,10002,82.11,10008,78.79,
			
			// 先用string容器的find()找到","的位置，再 substr() 截取字符串

			int pos = -1;	// 默认没查到返回-1
			int start = 0;	// find从0开始找
			

			vector<string> v;	// 存放每一届人员信息

			while (true)
			{
				pos = data.find(",", start);	// 找“,”位置

				if (pos==-1)
				{
					// 直到最后一个逗号，找不到下一个会返回 -1，直接break掉
					break;
				}
				else
				{
					string temp = data.substr(start, pos - start);	// 从 start 位置截取到 pos-start 位置
					//cout << temp << endl;
					v.push_back(temp);

					start = pos + 1;	// 指向下一个单词第一个字母

				} 
			}

			this->m_Record.insert(make_pair(index, v));
			index++;


		}


		ifs.close();

	}
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


	//第二轮比赛
	m_Index++;

	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechCompetition();

	//3、显示最终结果
	this->showScore();

	//4、保存分数
	this->saveRecord();



	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}