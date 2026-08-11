#include <iostream>
#include <deque>
using namespace std;

void test07()
{
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(100);
	d1.push_front(200);
	d1.push_front(300);

	// 1. 通过 [] 方式存取
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1[i] << " ";
	}
	cout << endl;
	// 300 200 100 10 20 30


	// 2. 通过 at 方式存取
	for (int i = 0; i < d1.size(); i++)
	{
		cout << d1.at(i) << " ";
	}
	cout << endl;
	// 300 200 100 10 20 30


	// 3. 访问头元素 front()
	cout << "第一个元素：" << d1.front() << endl;

	// 4. 访问尾元素 back()
	cout << "最后一个元素：" << d1.back() << endl;


}





int main5()
{
	test07();


	system("Pause");
	return 0;
}