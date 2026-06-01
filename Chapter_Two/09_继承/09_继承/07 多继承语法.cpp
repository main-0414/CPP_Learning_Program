#include <iostream>
using namespace std;

// 多继承语法
class dad1
{
public:
	dad1() { m_A = 100; }

	int m_A;
};


class dad2
{
public:
	dad2() { m_A = 200; }

	int m_A;
};



// 子类	需要继承dad1和dad2
// 语法：	class 子类 : 继承方式 父类1 , 继承方式 父类2
class son1 :public dad1, public dad2
{
public:
	son1()
	{
		m_C = 300;
		m_D = 400;
	}

	int m_C;
	int m_D;
};




void testt1()
{
	son1 s;

	cout << "sizeof son1 = " << sizeof(s) << endl;	// 16，自己两个属性+继承的两个属性
	
	//cout << "m_A = " << s.m_A << endl;	// 如果两个父类都有m_A，那么会报错，出现二义性
	
	// 当父类中出现同名成员，需要加作用域区分
	cout << "dad1 m_A = " << s.dad1::m_A << endl;
	cout << "dad2 m_A = " << s.dad2::m_A << endl;

}


// 总结：多继承中如果父类出现了同名情况，子类使用要加作用域




int main()
{
	testt1();


	system("pause");
	return 0;
}