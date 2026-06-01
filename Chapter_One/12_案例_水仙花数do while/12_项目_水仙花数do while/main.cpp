#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//do while 实现水仙花数

	int ge, shi, bai;

	int n = 100;

	do
	{
		ge = n % 10;
		shi = (n / 10) % 10;
		bai = n / 100;
		if (pow(ge, 3) + pow(shi, 3) + pow(bai, 3) == n)
		{
			cout << n << endl;
		}
		n++;

	} while (n <= 999);



	system("pause");
	return 0;
}