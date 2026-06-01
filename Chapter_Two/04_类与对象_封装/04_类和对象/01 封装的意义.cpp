#include <iostream>
using namespace std;

// 圆周率
const double PI = 3.14;

// 设计一个圆类，求圆的周长
// 圆求周长的公式：2 * PI * 半径

// class 代表设计一个类，类后面跟着类的名称
class Circle
{
	// 访问权限
	// 公共权限
public:

	// 属性(属性通常用变量)
	int m_r;

	// 行为(行为通常用函数)
	// 获取圆的周长
	double calculate_ZC()
	{
		return 2 * PI * m_r;
	}

};

int main1()
{
	// 通过圆类，创建具体的圆（对象）
	// 实例化（通过一个类 创建一个对象的过程）
	Circle c1;

	// 给圆对象 的属性进行赋值
	c1.m_r = 10;

	cout << "圆的周长为：" << c1.calculate_ZC() << endl;	//62.8



	system("pause");
	return 0;
}