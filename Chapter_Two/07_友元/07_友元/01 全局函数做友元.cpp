#include <iostream>
using namespace std;

class Building1
{
	// 告诉编辑器 GoodGay全局函数 是 Building类 的好朋友，可以访问Buiding类的私有成员
	friend void GoodGay1(Building1& building);


public:
	Building1()
	{
		m_LivingRoom = "客厅";
		m_BedRoom = "卧室";

	}

	// 其他成员函数和属性

	string m_LivingRoom;

private:
	string m_BedRoom;
};


// 全局函数
void GoodGay1(Building1& building)
{
	cout << "好基友全局函数 正在访问：" << building.m_LivingRoom << endl;
	cout << "好基友全局函数 正在访问：" << building.m_BedRoom << endl;
}


void test01()
{
	Building1 building;
	GoodGay1(building);
}










int main1()
{
	test01();



	system("pause");
	return 0;
}