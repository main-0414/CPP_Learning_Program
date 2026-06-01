#include<iostream>
using namespace std;

int main()
{
	//逢七过：输入1~100，其中7的倍数、个位有7、十位有7的特殊数字用"敲桌子"来代替

	for (int i = 1; i <= 100; i++)
	{
		if (i % 7 == 0 || i % 10 == 7 || i / 10 == 7)
		{
			cout << "敲桌子" << endl;
		}
		else
		{
			cout << i << endl;
		}

	}

	system("pause");
	return 0;
}