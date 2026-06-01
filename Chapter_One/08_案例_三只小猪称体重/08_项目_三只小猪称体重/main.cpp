#include <iostream>
using namespace std;

int main()
{
	int a, b, c;

	cout << "请输入第一只小猪的重量：";
	cin >> a;
	cout << "请输入第二只小猪的重量：";
	cin >> b;
	cout << "请输入第三只小猪的重量：";
	cin >> c;

	if (a>=b && a>=c)
	{
		if (a==b && b==c)
		{
			cout << "三只小猪一样重！！" << endl;
		}
		else if (a==b)
		{
			cout << "第一只和第二只小猪一样都最重！" << endl;
		}
		else
		{
			cout << "第一只小猪最重！" << endl;
		}
		
	}
	else if (b>=a && b>=c)
	{
		if (b==c)
		{
			cout << "第二只和第三只小猪一样都最重！" << endl;
		}
		else
		{
			cout << "第二只小猪最重！！" << endl;
		}
	}
	else
	{
		cout << "第三只小猪最重！" << endl;
	}


	//if (a>b)
	//{
	//	if (a > c)
	//	{
	//		cout << "第一只最重" << endl;
	//	}
	//	else
	//	{
	//		cout << "第三只最重" << endl;
	//	}
	//}
	//else
	//{
	//	if (b>c)
	//	{
	//		cout << "第二只最重" << endl;
	//	}
	//	else
	//	{
	//		cout << "第三只最重" << endl;
	//	}
	//}






	system("pause");
	return 0;
}