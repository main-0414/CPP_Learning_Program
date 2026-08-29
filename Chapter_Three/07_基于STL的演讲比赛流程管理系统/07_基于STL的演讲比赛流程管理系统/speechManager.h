#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <numeric>
#include <random>
#include <iomanip>
using namespace std;



// 设计演讲管理类
class SpeechManager
{
public:

	// 构造
	SpeechManager();

	// 析构
	~SpeechManager();

	// 展示菜单
	void show_Menu();

	// 退出系统
	void exitSystem();

	// 初始化
	void initSpeech();

	// 创建选手
	void createSpeaker();

	// 开始比赛
	void startSpeech();

	// 抽签功能
	void speechDraw();

	// 比赛实现
	void speechCompetition();

	
private:
	// 成员属性
	// 比赛总选手
	vector<int> v1;

	// 第一轮晋级只剩6个人
	vector<int> v2;

	// 胜利的3个人
	vector<int> vVictory;

	// 存放编号 以及对应的 具体选手 容器
	map<int, Speaker> m_Speaker;

	// 轮数
	int m_Index;

	// 随机数引擎
	mt19937 gen{ random_device{}() };
};