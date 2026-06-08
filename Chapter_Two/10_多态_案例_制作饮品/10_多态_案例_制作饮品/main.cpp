#include <iostream>
using namespace std;

// 多态案例2 制作饮品
class AbstractDringking
{
public:
	// 煮水
	virtual void Boil() = 0;

	// 冲泡
	virtual void Brew() = 0;

	// 倒入杯中
	virtual void PourInCup() = 0;

	// 加入辅料
	virtual void PutSomething() = 0;

	// 制作饮品
	void makeDrink()
	{
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};


// 制作咖啡
class Coffee:public AbstractDringking
{
	// 煮水
	virtual void Boil()
	{
		cout << "煮百岁山" << endl;
	}

	// 冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}

	// 倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}

	// 加入辅料
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl;
	}
};


// 制作茶叶
class Tea:public AbstractDringking
{
public:
	// 煮水
	virtual void Boil()
	{
		cout << "煮农夫山泉" << endl;
	}

	// 冲泡
	virtual void Brew()
	{
		cout << "冲茶叶" << endl;
	}

	// 倒入杯中
	virtual void PourInCup()
	{
		cout << "倒入杯中" << endl;
	}

	// 加入辅料
	virtual void PutSomething()
	{
		cout << "加入枸杞" << endl;
	}
};




void doWork(AbstractDringking* abs)	// AbstractDringking* abs = new Coffee;
{
	abs->makeDrink();
	delete abs;	// 释放
}

void doWork1(AbstractDringking& abs)	// 引用方式
{
	abs.makeDrink();
}




void test01()
{
	// 制作咖啡
	doWork(new Coffee);
	cout << "----------------" << endl;

	Coffee coffee;
	doWork1(coffee);

	cout << "----------------" << endl;



	// 制作茶叶
	doWork(new Tea);
	cout << "----------------" << endl;

	Tea tea;
	doWork1(tea);
}



int main()
{
	test01();



	system("pause");
}