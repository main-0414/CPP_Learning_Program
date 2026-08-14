// 案例描述
// 有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分

// 1. 创建五名选手，放到vector中 
// 2. 遍历vector容器，取出来每个选手，执行for循环可以把10个评分存到deque容器中
// 3. sort算法对deque容器中分数进行排序，去除最高分和最低分
// 4. deque容器遍历，累加总分
// 5. 或取平均分

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class Person
{
public:
	Person(string name, double score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;
	double m_Score;	// 平均分

};


void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";

	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		//name += nameSeed[i];

		name.append(1, nameSeed[i]);	// append主要是追加一个串，只追加1个char需要写参数
		//string& append(size_t n, char c);		// 追加 n 个 c 到 name 后面

		int score = 0;	// 默认平均分为 0

		Person p(name, score);

		// 将创建的 选手 对象都放入到容器中
		v.push_back(p);
	}
}

// 打分
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 将评委的分数 放入deque容器中
		deque<int> d;

		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}

		// 可以打印一下
		//cout << "选手" << it->m_Name << " 分数：" << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;


		// 排序
		sort(d.begin(), d.end());


		// 去除极值
		d.pop_back();
		d.pop_front();


		// 取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += *dit;	// 累加评委分
		}


		int avg = sum / d.size();


		// 将平均分赋值给选手
		(*it).m_Score = avg;

	}

}


void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->m_Name << " 的平均分是：" << it->m_Score << endl;
	}
}



int main()
{
	// 随机数种子
	srand((unsigned int)time(nullptr));


	// 1. 创建5名选手
	vector<Person> v;	// 存放 选手
	createPerson(v);	// 增加 选手

	// 测试
	//for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << "姓名：" << (*it).m_Name << " 分数：" << (*it).m_Score << endl;
	//}


	// 2. 给5名选手打分
	setScore(v);


	// 3. 显示最后得分
	showScore(v);


	system("pause");
	return 0;
}