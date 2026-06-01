#include <iostream>
#include <random>
using namespace std;

int main()
{
	random_device rd;   // 真随机种子
	mt19937 suiji(rd());  // 随机数发动机
	uniform_int_distribution<> dist(150, 200);	// 范围控制器


	cout << "五只小猪的重量分别是：";

	int a[5];

	for (int i = 0;i <= 4;i++)
	{
		a[i] = dist(suiji);		//得到150~200的随机数
		cout << a[i] << " ";
	}

	cout << endl;

	int max = a[0];
	int num = 1;

	for (int i = 1;i <= 4;i++)
	{
		//if (a[i] > max)
		//{
		//	max = a[i];
		//	num = i + 1;
		//}

		(a[i] > max) ? (max = a[i], num = i + 1) : 0;

	}

	cout << "最重的小猪是第" << num << "只，重" << max << "千克" << endl;


	system("pause");
	return 0;
}