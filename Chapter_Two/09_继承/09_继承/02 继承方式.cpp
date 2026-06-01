#include <iostream>
using namespace std;

// 继承方式



// 公共继承
class Father1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};


class Son1 :public Father1
{
public:
	void func()
	{
		m_A = 10;	// 父类中的公共成员 到子类中依然是公共权限
		m_B = 10;	// 父类中的保护成员 到子类中依然是保护权限
		//m_C = 10;	// 父类中的保护成员 到子类中依然是私有权限

	}
};



void Test01()
{
	Son1 s1;
	s1.m_A = 100;	// 到了Son1中，是 公共权限：类内可访问，类外不可访问
	//s1.m_B = 100;	// 到了Son1中，是 保护权限：类内可访问，类外不可访问
	
}


// 保护继承
class Father2
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};


class Son2:protected Father2
{
public:
	void func()
	{
		m_A = 100;	// 父类中公有成员，到子类变为保护成员
		m_B = 100;	// 父类中保护成员，到子类变为保护成员
		//m_C = 100;	// 父类中私有成员，子类访问不到

	}
};


void test02()
{
	Son2 s1;
	//s1.m_A = 100;	// 在Son2中，m_A变为保护权限，因此类外访问不到
	//s1.m_B = 100;	// 在Son2中，m_A依旧是保护权限，不可以访问

}



// 私有继承
class Father3
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};


class Son3 :private Father3
{
public:
	void func()
	{
		m_A = 100;	// 父类中公有成员，到子类变为私有成员
		m_B = 100;	// 父类中保护成员，到子类变为私有成员
		//m_C = 100;	// 父类中私有成员，子类访问不到
	}

};


class GrandSon3 :public Son3
{
public:
	void func()
	{
		//m_A = 1000;		// 对于GrandSon3来说，父亲是Son3，且Son3中m_A是私有，所以GrandSon3访问不到
		//m_B = 1000;
	}
};


void test03()
{
	Son3 s1;
	//s1.m_A = 1000;	// 到Son3中，m_A变为 私有成员，类外访问不到
	//s1.m_B = 1000;	// 到Son3中，m_B变为 私有成员，类外访问不到
}




int main2()
{






	system("pause");
	return 0;
}