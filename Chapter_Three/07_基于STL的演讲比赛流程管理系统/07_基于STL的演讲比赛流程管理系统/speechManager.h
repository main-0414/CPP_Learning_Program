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
#include <fstream>
using namespace std;

const string FILENAME = "speech.csv";


// 设计演讲管理类
class SpeechManager
{
public:

	// 构造
	SpeechManager();

	// 析构
	~SpeechManager() = default;

	// 展示菜单
	void show_Menu();

	// 退出系统
	void exitSystem();

	// 初始化
	void initSpeech();

	// 创建选手
	void createSpeaker();

	// 封装初始化和创建选手功能
	void reset();

	// 开始比赛框架
	void startSpeech();

	// 抽签功能
	void speechDraw();

	// 比赛实现
	void speechCompetition();

	// 显示晋级结果
	void showScore();

	// 保存结果到文件
	void saveRecord();

	// 加载数据
	void loadRecord();

	// 显示往届记录
	void showRecord();

	// 清空数据
	void dataClear();

	
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

	// 判断文件是否为空标记
	bool m_FileIsEmpty;

	// 存放往届记录的容器（第几届,数据）
	map<int, vector<string>> m_Record;
};