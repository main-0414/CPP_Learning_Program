// 比赛规则：
// 
// 大纲学校举行一场演讲比赛，共有 12个人 参加。 比赛共两轮，第一轮为淘汰赛，第二轮为决赛。
//
// 比赛方式：分组比赛，每组6个人 ；选手每次要随机分组，进行比赛
//
// 每名选手都有对应的 编号 ，如 10001 ~10012
//
// 第一轮分为两个小组，每组6个人。 整体按照选手编号进行 抽签 后顺序演讲。
//
// 当小组演讲完后，淘汰组内排名最后的三个选手， 前三名晋级 ，进入下一轮的比赛。
//
// 第二轮为决赛， 前三名胜出
//
// 每轮比赛过后需要 显示晋级选手的信息

using namespace std;
#include <iostream>
#include "speechManager.h"



int main()
{
	// 创建管理类对象
	SpeechManager sm;

	// 测试创建
	//for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	//{
	//	cout << "选手编号：" << it->first
	//		<< "  姓名：" << it->second.m_Name
	//		<< "  得分：" << it->second.m_Score[0] << endl;
	//}


	int UserChoice = 0;		// 存选项

	while (true)
	{
		sm.show_Menu();

		cout << "请输入选项：" << endl;
		cin >> UserChoice;

		switch (UserChoice)
		{
		case 1:		// 开始比赛
			
			sm.startSpeech();
			break;

		case 2:		// 查看往届比赛记录

			sm.showRecord();
			break;

		case 3:		// 清空比赛记录

			sm.dataClear();
			break;

		case 0:		// 退出系统

			sm.exitSystem();
			break;

		default:

			system("cls");
			break;

		}
	}



	system("pause");
	return 0;
}