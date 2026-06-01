#include <iostream>
using namespace std;

// 类做友元

// 建筑物类
class Building
{
	friend class GoodGay;	// GoodGay是本类的好朋友，可以访问本类私有成员

public:
	Building();	// 构造函数


public:
	string m_LivingRoom;

private:
	string m_BedRoom;
};



class GoodGay
{
public:
	GoodGay();	// 构造函数

	void visit();	// 参观函数，访问Building类中的属性

	~GoodGay();	// 析构，清除内存

	Building* building;	// 维护一个指针变量

};






// 类外写成员函数
Building::Building()
{
	m_LivingRoom = "客厅";
	m_BedRoom = "卧室";

}

GoodGay::GoodGay()
{
	// 创建一个建筑物对象
	building = new Building;	// 给这个指针赋值，让它指向一个真实的房子对象。
	// 如果在GoodGay构造里用 Building b; 这样创建对象，那么构造结束，b就没了。
	// 只能在class GoodGay里这么写（直接定义对象成员）
}


void GoodGay::visit()
{
	cout << "好基友正在访问：" << building->m_LivingRoom << endl;
	cout << "好基友正在访问：" << building->m_BedRoom << endl;
}

GoodGay::~GoodGay()
{
	delete building;  // 释放new的对象
	building = NULL;   // 指针置空
}




void test1()
{
	GoodGay GG;
	GG.visit();
}


int main2()
{
	test1();



	system("pause");
	return 0;
}