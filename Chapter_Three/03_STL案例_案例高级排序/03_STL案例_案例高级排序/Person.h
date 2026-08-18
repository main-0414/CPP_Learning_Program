#pragma once
#include <iostream>
using namespace std;

class Person
{
public:
	Person(string name, int age, int height)
		:m_Name(name),
		m_Age(age),
		m_Height(height)
	{
	}


	string m_Name;
	int m_Age;
	int m_Height;
};