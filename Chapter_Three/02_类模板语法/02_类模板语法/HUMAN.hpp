#pragma once
#include <iostream>
#include <string>
using namespace std;


template<class T1, class T2>
class HUMAN
{
public:
	HUMAN(T1 name, T2 age);

	void showHuman();


	T1 m_Name;
	T2 m_Age;

};

template<class T1, class T2>
HUMAN<T1, T2>::HUMAN(T1 name, T2 age)
	:m_Name(name), m_Age(age)
{
}

template<class T1, class T2>
void HUMAN<T1, T2>::showHuman()
{
	cout << "姓名：" << m_Name << "  年龄：" << m_Age << endl;
}