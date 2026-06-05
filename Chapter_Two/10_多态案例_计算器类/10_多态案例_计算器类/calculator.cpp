#include <iostream>
using namespace std;

// 利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

// 普通写法
class Calculator
{
public:

	int getResult(string oper)
	{
		if (oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if (oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if (oper == "*")
		{
			return m_Num1 * m_Num2;
		}
		// 如果想扩展新的功能，需要修改源码
		// 在真是的开发中 提倡 开闭原则
		// 开闭原则：对扩展进行开放，对修改进行关闭
	}



	int m_Num1;		// 操作数1
	int m_Num2;		// 操作数2
};

void test01()
{
	Calculator cal;
	cal.m_Num1 = 10;
	cal.m_Num2 = 10;

	cout << cal.m_Num1 << " + " << cal.m_Num2 << " = " << cal.getResult("+") << endl;
	cout << cal.m_Num1 << " - " << cal.m_Num2 << " = " << cal.getResult("-") << endl;
	cout << cal.m_Num1 << " * " << cal.m_Num2 << " = " << cal.getResult("*") << endl;
}








// 利用多态实现计算器

// 实现计算器抽象类
class AbstractCalculator
{
public:

	virtual int getResult()
	{
		return 0;
	}



	int m_Num1;
	int m_Num2;
};


// 加法计算器类
class AddCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 + m_Num2;
	}
};


// 减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 - m_Num2;
	}
};


// 乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 * m_Num2;
	}
};

// 除法计算器类
class DivCalculator :public AbstractCalculator
{
public:
	int getResult()
	{
		return m_Num1 / m_Num2;
	}
};


void test02()
{
	// 多态使用条件
	// 父类指针或者引用指向子类对象

	// 加法运算
	AbstractCalculator* abs = new AddCalculator;
	abs->m_Num1 = 10;
	abs->m_Num2 = 10;

	cout << abs->m_Num1 << " + " << abs->m_Num2 << " = " << abs->getResult() << endl;

	// 用完后销毁
	delete abs;

	// 加法引用写法
	AddCalculator add;
	AbstractCalculator& abs_reference = add;   // 父类引用指向子类对象
	abs_reference.m_Num1 = 10;
	abs_reference.m_Num2 = 10;
	cout << abs_reference.m_Num1 << " + " << abs_reference.m_Num2 << " = " << abs_reference.getResult() << endl;




	// 减法运算
	abs = new SubCalculator;	// abs还是父类 AbstractCalculator 的指针
	abs->m_Num1 = 10;
	abs->m_Num2 = 10;

	cout << abs->m_Num1 << " - " << abs->m_Num2 << " = " << abs->getResult() << endl;
	delete abs;



	// 乘法运算
	abs = new MulCalculator;	// abs还是父类 AbstractCalculator 的指针
	abs->m_Num1 = 10;
	abs->m_Num2 = 10;

	cout << abs->m_Num1 << " * " << abs->m_Num2 << " = " << abs->getResult() << endl;
	delete abs;


	// 多态虽然代码量大，但结构清晰，如果出错容易定位
}









int main()
{
	//test01();
	test02();


	system("pause");
	return 0;
}