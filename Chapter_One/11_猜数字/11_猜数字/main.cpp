#include <iostream>
#include <cstdlib>
#include <ctime>	//包含系统时间头文件
using namespace std;

int main()
{
	srand( (unsigned int) time(NULL) );		//随机数种子

	int num = rand() % 10 + 1;		//rand() % (b - a + 1) + a;
	//生成一个 1~10 的数

	int n = 1, player;

	cout << "请输入你猜的数：";
	cin >> player;

	while (n <= 5)
	{
		if (player == num) { break; }

		if (player > num)
		{
			cout << "大了！" << endl;
		}
		else
		{
			cout << "小了！" << endl;
		}

		if (n < 5)
		{
			cout << "再试一次吧！请输入：";
			cin >> player;
			n++;
		}
		else { break; }


	}

	if (n==1)
	{
		cout << "牛逼！一发入魂！！！" << endl;
	}
	else if (n<5)
	{
		cout << "答对了！共用了" << n << "次" << endl;
	}
	else
	{
		cout << "5次机会用尽！答案是：" << num << endl << "运气不好稍后再试！" << endl;
	}



















	//int player, n;
	////cout << num << endl;
	//cout << "你有5次猜数机会！" << endl << "请输入你猜测的数：";
	//cin >> player;
	//n = 1;

	//while (player != num && n <=5)
	//{
	//	if (player>num)
	//	{
	//		cout << "大了" << endl;

	//		if (n==5)
	//		{
	//			cout << "5次机会用尽！运气不好稍后再试！" << endl;
	//			break;
	//		}
	//		else
	//		{
	//			cout << "再试一次：";
	//			cin >> player;
	//			n++;
	//		}
	//	}
	//	else if (player<num)
	//	{
	//		cout << "小了" << endl;

	//		if (n == 5)
	//		{
	//			cout << "5次机会用尽！运气不好稍后再试！" << endl;
	//			break;
	//		}
	//		else
	//		{
	//			cout << "再试一次：";
	//			cin >> player;
	//			n++;
	//		}	
	//	}
	//}

	//if (n==1)
	//{
	//	cout << "对了！一发入魂！！！" << endl;
	//}
	//else if (n<=5)
	//{
	//	cout << "答对了！！！" << "一共用了" << n << "次" << endl;
	//}






	system("pause");
	return 0;
}