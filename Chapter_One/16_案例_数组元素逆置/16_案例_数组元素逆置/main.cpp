#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	//数组元素逆置
	srand(time(NULL));

	int a[5] = { 0 };

	cout << "逆置前：";

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		a[i] = rand() % 90 + 10;
		cout << a[i] << "  ";
	}

	int start = 0;
	int end = sizeof(a) / sizeof(a[0]) - 1;

	while (start < end)
	{
		int temp = 0;

		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}

	cout << endl << "逆置后：";
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) { cout << a[i] << "  "; }

	system("pause");
	return 0;
}