#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	//考试成绩统计
	srand(time(NULL));
	int score[3][3] = { 0 };
	string names[3] = { "张三","李四","王五" };
	double avg[3] = { 0 };


	cout << "学生\t语文\t数学\t英语\t总分" << endl;
	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		cout << names[i] << "\t";

		for (int j = 0; j < 3; j++)
		{
			score[i][j] = rand() % 41 + 60;
			cout << score[i][j] << "\t";
			sum += score[i][j];
		}
		cout << sum << endl;
	}

	cout << "平均分\t";

	for (int i = 0; i < 3; i++)
	{
		int all = 0;
		for (int j = 0; j < 3; j++)
		{
			all += score[j][i];
		}
		avg[i] = all * 1.0 / 3;
		cout << fixed << setprecision(2) << avg[i] << "\t";		//保留两位小数输出
	}

	cout << endl;








	system("pause");
	return 0;
}