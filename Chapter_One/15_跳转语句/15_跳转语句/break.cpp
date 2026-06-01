#include <iostream>
using namespace std;

int main1()
{
	//break的使用时机

	//1.出现在switch语句中
	cout << "请选择副本难度：" << endl;
	cout << "1.普通" << endl;
	cout << "2.中等" << endl;
	cout << "3.困难" << endl;

	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		cout << "选择了普通难度。" << endl;
		break;
	case 2:
		cout << "选择了中等难度。" << endl;
		break;
	case 3:
		cout << "选择了困难难度！" << endl;
		break;
	default:
		cout << "退出！" << endl;
		break;
	}

	cout << endl;

	//2.出现在循环语句中
	for (int i = 0; i < 10; i++)
	{	
		//如果i=5时，退出循环
		if (i==5)
		{
			break;
		}
		cout << i << endl;
	}


	cout << endl;


	//3.出现在循环嵌套语句中
	for (int i = 1; i <=10 ; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 5) { break; }	//只退出最近的循环
			cout << "* ";
		}
		cout << endl;
	}




	system("pause");
	return 0;
}