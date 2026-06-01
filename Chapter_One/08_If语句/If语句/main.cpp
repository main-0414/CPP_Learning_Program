#include <iostream>
using namespace std;

int main()
{
	//选择结构
	//用户选择输入，如果>=600分，那么视为考上一所一本大学；>=500，二本；>=400，三本；其他带专。


	//1.用户输入分数
	int score = 0;
	cout << "请输入分数：";

	cin >> score;
	
	//2.打印分数在屏幕上
	cout << "你的分数是：" << score << endl;

	//3.判断分数是否大于600，如果大于，那么输出	
	//if条件后不要加分号
	if (score>=600)
	{
		if (score>=700)
		{
			cout << "牛逼清华北大！" << endl;
		}
		else
		{
			cout << "恭喜你考了一本大学！" << endl;
		}
	}
	else if (score>=500)
	{
		cout << "恭喜你考了一所二本大学！" << endl;
	}
	else if (score>=400)
	{
		cout << "恭喜你考了一所三本大学！" << endl;
	}
	else 
	{
		cout << "带专咯！！！" << endl;
	}








	system("pause");
	return 0;
}