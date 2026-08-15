// queue (队列) 基本概念
// queue 是一种先进先出的数据结构，他有两个口，一进一出，尾进头出
// 队列中只有 队头 和 队尾 才可以被外界使用，因此 不允许有遍历行为
// 队列中进数据称为 ———— 入队 push
// 队列中出数据称为 ———— 出队 pop

#include <iostream> 
#include <queue>
using namespace std;

class Person
{
public:
	Person(string name, int age)
		:m_Name(name), m_Age(age) 
	{}


	string m_Name;
	int m_Age;
};


void test01()
{
	queue<Person> q;


	// 准备数据
	Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
	Person p3("猪八戒", 500);
	Person p4("沙僧", 200);


	// 入队
	q.push(p1);		// 唐僧先入队，先出
	q.push(p2);
	q.push(p3);
	q.push(p4);



	// 先查看队列大小
	cout << "队列大小：" << q.size() << endl;



	// 判断只要队列不为空，查看队头，查看队尾，出队
	while (!q.empty())
	{
		// 查看队头
		cout << "队头元素 ———— 姓名：" << q.front().m_Name 
			<< " 队头元素 ———— 年龄：" << q.front().m_Age << endl;

		// 查看队尾
		cout << "队尾元素 ———— 姓名：" << q.back().m_Name 
			<< " 队尾元素 ———— 年龄：" << q.back().m_Age << endl;

		// 出队
		q.pop();

	}

	cout << "队列大小：" << q.size() << endl;
}



int main()
{
	test01();


	system("pause");
	return 0;
}