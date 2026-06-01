#include <iostream>
using namespace std;

// 访问权限（三种）:
// 公共权限 public		成员 类内可以访问		类外可以访问
// 保护权限 protected	成员 类内可以访问		类外不可以访问	儿子也可以访问父亲中的保护内容
// 私有权限 private		成员 类内可以访问		类外不可以访问	儿子不可以访问父亲的私有内容

// 类中的属性和行为 统一成为 成员
// 属性 成员属性 成员变量
// 行为 成员函数 成员方法
class Person
{
public:		// 公共权限
	
	string m_Name;	// 姓名

protected:	// 保护权限
	
	string m_Car;	// 车

private:	// 私有权限

	int m_Password;	// 银行卡密码


// class大括号内都叫类内（比如下面我访问属性没有报错，但是在main函数中就不是类内了）
public:	
	void func()	// func函数是public的，所以main函数可以访问
	{
		m_Name = "观观王";
		m_Car = "兰博基尼";
		m_Password = 123456;

	}

};



int main2()
{
	// 实例化具体对象
	Person P1;

	P1.m_Name = "张三";
	//P1.m_Car = "奔驰";		// 报错：声明20行，不可访问（保护权限内容，在类外访问不到）
	//P1.m_Password = 123;	// 报错：声明24行，不可访问（私有权限内容，在类外访问不到）

	P1.func();




	system("pause");
	return 0;
}