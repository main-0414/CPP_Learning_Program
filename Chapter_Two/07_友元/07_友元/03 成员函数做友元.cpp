#include <iostream>
using namespace std;

class Build;

class Gay
{
public:
	Gay();

	void visit();	// 让visit()函数可以访问Build中私有成员
	void visit2();	// 让visit2()函数不可以访问Build中私有成员


	Build* build;
};

class Build
{
	// 告诉编译器 Gay类下的visit()成员函数作为本类的好朋友，可以访问私有成员
	friend void Gay::visit();	

public:
	Build();

	string m_LivingRoom;	// 客厅

private:

	string m_Bedroom;		// 卧室

};

Gay::Gay()
{
	
	build = new Build;
}

Build::Build()
{
	m_LivingRoom = "客厅";
	m_Bedroom = "卧室";
}

void Gay::visit()
{
	cout << "Gay visit 正在访问：" << build->m_LivingRoom << endl;
	cout << "Gay visit 正在访问：" << build->m_Bedroom << endl;
	
}

void Gay::visit2()
{
	cout << "Gay visit2 正在访问：" << build->m_LivingRoom << endl;
	//cout << "Gay visit2 正在访问：" << build->m_Bedroom << endl;
}

void Test();



int main()
{
	Test();



	system("pause");
	return 0;
}




void Test()
{
	Gay GG;
	GG.visit();
	GG.visit2();
}