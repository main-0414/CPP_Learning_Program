#include <iostream>
using namespace std;

int main()
{
	//打印星图

	for (int i = 1; i <=10 ; i++)
	{
		for (int j = 1; j <=10 ; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}