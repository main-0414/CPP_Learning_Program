#include <iostream>
using namespace std;

// 重载关系运算符
class Persons
{
public:
	Persons(string name, int age):m_Age(age),m_Name(name){}

	// 判断相等
	bool operator==(Persons& p)
	{
		return (m_Age == p.m_Age and m_Name == p.m_Name) ? true : false;
	}

	// 判断不相等
	bool operator!=(Persons& p)
	{
		return (m_Age == p.m_Age and m_Name == p.m_Name) ? false : true;
	}



	int m_Age;
	string m_Name;
};


void t1()
{
	Persons p1("观观王", 20);
	Persons p2("观观王", 20);

	
	
	//if (p1==p2)	// 本质上p1.operator==(p2)
	//{
	//	cout << "他们两个人 相等！" << endl;
	//}
	//else
	//{
	//	cout << "他们两个人 不相等！" << endl;
	//}

	if (p1!=p2)
	{
		cout << "他们两个人 不相等！" << endl;
	}
	else
	{
		cout << "他们两个人 相等！" << endl;
	}




}





int main5()
{
	t1();



	system("pause");
	return 0;
}