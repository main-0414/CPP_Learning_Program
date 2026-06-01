#include <iostream>
using namespace std;

// 动物类
class Animal
{
public:
	int m_Age;
};


// 利用虚继承 解决菱形继承的问题
// 在继承之前 加上关键字 virtual 变成 虚继承
// Animal类成为 虚基类（最大的这个类）
// 
// 此时  cl /d1 reportSingleClassLayoutSheepTuo "08 菱形继承.cpp"后
// 会发现只有一份 m_Age，且 Sheep 和 Tuo 类下有个 vbptr (虚基类指针)
// vbptr 指向 vbtable (虚基类表)
// 
// 下面 vbtable 显示了 指针的偏移量，也能找到 m_Age 数据
// 
// 
// 
// 
// 
// 羊类
class Sheep :virtual public Animal{};


// 驼类
 class Tuo:virtual public Animal{};



// 羊驼
class SheepTuo :public Sheep, public Tuo
{

};


void a()
{
	SheepTuo yt;
	yt.Sheep::m_Age = 18;	// 不使用虚继承，不加作用域会报错，产生二义性
	yt.Tuo::m_Age = 28;

	// 当菱形继承时，两个父类拥有相同的属性，需要加以作用域区分
	cout << "yt.Sheep::m_Age = " << yt.Sheep::m_Age << endl;
	cout << "yt.Tuo::m_Age = " << yt.Tuo::m_Age << endl;

	cout << yt.m_Age << endl;	// 使用虚继承不加作用域也可以访问，因为只有一份数据

	// 这只羊驼应该只有一个年龄，菱形继承导致数据有两份，资源浪费






}










int main()
{
	a();



	system("pause");
	return 0;
}