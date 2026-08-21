// 案例描述
// 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分

// 1. 创建五名选手，放到vector中
// 2. 遍历vector容器，取出来每个选手，执行for循环可以把10个评分存到deque容器中
// 3. sort算法对deque容器中分数进行排序，去除最高分和最低分
// 4. deque容器遍历，累加总分
// 5. 获取平均分


#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


class Person
{
public:
	Person(string name,double score)
		:m_Name(name),m_avgScore(score)
	{}

	 string m_Name;
	 double m_avgScore;
};


void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		double score = 0;

		Person p(name, score);

		v.push_back(p);

	}
}


void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it < v.end(); it++)
	{
		deque<int> d;

		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;

			d.push_back(score);
		}

		// 先进行排序，掐头去尾
		sort(d.begin(), d.end());

		d.pop_back();
		d.pop_front();

		// 计算平均值
		int sum=0;

		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;
		}

		double avg = sum / d.size();

		it->m_avgScore = avg;
	}
}

void showPerson(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).m_Name << " 的平均分：" << (*it).m_avgScore << endl;
	}
}




int main()
{
	// 随机数生成器
	srand((unsigned int)time(nullptr));


	// 创建vector容器
	vector<Person> v;

	// 创建并添加 选手
	createPerson(v);

	// 评委打分存进deque
	setScore(v);

	// 打印
	showPerson(v);


	system("pause");
	return 0;
}