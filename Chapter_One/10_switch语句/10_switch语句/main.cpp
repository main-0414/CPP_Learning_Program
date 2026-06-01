#include <iostream>
using namespace std;

int main()
{
	//switch语句

	//给电影打分
	//10~9	经典
	//8~7	非常好
	//6~5	一般
	//5以下	烂片

	//1.提示用户打分
	cout << "请给电影进行打分：" ;
	//2.用户开始打分
	int score;
	cin >> score;
	cout << "您打的分数是：" << score << endl;
	//3.根据用户输入的分数来提示用户最后的结果


	switch (score)	//score语句中表达式只能是整型或者字符型
	{
	case 10:	//case 后面必须是常量值（不能是范围、变量、表达式）。
	case 9:
		cout << "您认为这是经典电影！" << endl;
		break;	//没有 break 程序会一直往下执行

	case 8:
	case 7:
		cout << "您认为这部电影非常好！" << endl;
		break;

	case 6:
	case 5:
		cout << "您认为这部电影一般。" << endl;
		break;

	default:
		cout << "烂片！！" << endl;
		break;
	}


	//switch 相较于 if 结构清晰，执行效率高，缺点是不能判断区间





	system("pause");
	return 0;
}