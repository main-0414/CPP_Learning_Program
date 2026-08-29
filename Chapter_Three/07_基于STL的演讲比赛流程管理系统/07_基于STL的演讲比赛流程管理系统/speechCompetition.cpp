#include "speechManager.h"


void SpeechManager::speechCompetition()
{
	cout << "------------- 第 " << this->m_Index << " 轮正式比赛开始：------------- " << endl << endl;

	int num = 0;
	multimap<double, int, greater<double>> groupScore;


	// 定义一个临时vector容器，如果是第一轮就复制v1，否则v2
	vector<int> vTemp;

	if (m_Index == 1)
	{
		vTemp = this->v1;
	}
	else
	{
		vTemp = this->v2;
	}



	// 遍历vector容器，并给每个选手评分
	for (vector<int>::iterator it = vTemp.begin(); it != vTemp.end(); it++)
	{
		deque<double> d;


		// 随机生成评委分数
		for (int i = 0; i < 10; i++)
		{
			uniform_real_distribution<double> dis(60.0, 100.0);

			d.push_back(dis(gen));
		}


		// 排序
		sort(d.begin(), d.end(), greater<double>());


		// 去最大最小
		d.pop_back();
		d.pop_front();


		// 计算平均分
		double sum = accumulate(d.begin(), d.end(), 0.0);
		double avg = round(sum / (double)d.size() * 100) / 100.0;


		// 保存到每个选手的 m_Score 属性里
		this->m_Speaker[*it].m_Score[m_Index - 1] = avg;


		// 6个人一组，打印排名，用一个自动排序的容器存储
		groupScore.insert(make_pair(avg, *it));


		num++;	// 插入完就增加一个人


		// 如果满一组6人，那么打印小组所有人信息
		if (num % 6 == 0)
		{
			cout << "第 " << num / 6 << " 小组比赛名次：" << endl;

			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second
					<< "   姓名：" << this->m_Speaker[it->second].m_Name
					<< "   分数：" << this->m_Speaker[it->second].m_Score[m_Index - 1] << endl;
			}


			// 取前三名，晋级

			int count = 0;


			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
				it != groupScore.end() && count < 3;
				it++, count++)
			{
				if (m_Index == 1)
				{
					v2.push_back(it->second);	// 把编号塞进去
				}
				else
				{
					vVictory.push_back(it->second);
				}
			}

			groupScore.clear();		// 打印、晋级完一组要清空，要不然第二组会打印12个人

			cout << endl;

		}

	}

	cout << "------------- 第 " << this->m_Index << " 轮比赛完毕  ------------- " << endl;
	system("pause");

}