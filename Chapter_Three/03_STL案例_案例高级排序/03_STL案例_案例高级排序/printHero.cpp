#include "printHero.h"

void printHero(const list<Person>& L)
{
	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << (*it).m_Name
			<< "  年龄：" << (*it).m_Age
			<< "  身高：" << (*it).m_Height << endl;
	}
	cout << endl;
}