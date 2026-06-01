#include <iostream>
using namespace std;

int main2()
{
	//浮点型（实型）		默认情况下，最多表示6位有效数字
	//1.float单精度(4字节)
	//2.double双精度(8字节)

	float f1 = 3.1415926f;		//数字后面f是为了让3.14这个值从一开始就是单精度，编译器默认为双精度
	cout << "float占用的内存空间大小是：" << sizeof(f1) << endl;
	cout << "f1 = " << f1 << endl;


	double d1 = 3.1415926;
	cout << "double占用的内存空间大小是：" << sizeof(d1) << endl;
	cout << "d1 = " << d1 << endl;

	printf("用printf方式输出完整数据：%.7f\n", d1);
	//%是占位符，表示这里的东西由逗号后面的变量来表示，".7f"表示这里的数字是保留7位小数的浮点型数据

	//printf("%.nf", 变量);
	//n = 你想要输出的小数位数
	//f = 浮点数（float / double 都能用）

	//科学计数法
	double ff1 = 5e2;	//5* 10^2
	cout << "ff1=" << ff1 << endl;

	double ff2 = 5e-3;	//5* 0.1^2
	cout << "ff2=" << ff2 << endl;





	system("pause");
	return 0;
}