#include <iostream>
using namespace std;

// 多态

// 动物类
class Animal
{
public:
	// 虚函数（地址晚绑定）
	// 此时类内部发生改变，多了一个 vfptr(虚函数指针)，它指向了一张 vftable(虚函数表)，表内记录了虚函数的地址
	virtual void speak()	// 父类里virtual一定要写才可以实现动态多态，子类可写可不写
	{
		cout << "动物在说话" << endl;
	}
};

// 猫类
class Cat :public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
};


// 狗类
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}

};



// 动态多态 满足条件：
// 1. 有继承关系
// 2. 子类重写父类的虚函数
	// 重写：函数的 返回值类型 函数名 参数列表 完全相同


// 动态多态 使用条件：
// 父类的指针或引用 指向子类对象


// 执行说话的函数
// 地址早绑定 在编译阶段确定函数地址
// 如果想让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定————>地址晚绑定(函数前加virtual)

void doSpeak(Animal& animal) // 父类引用 Animal& animal  指向子类 cat  (!父类的引用可指向子类对象!)
{
	animal.speak();
}




void test01()
{
	Cat cat;
	doSpeak(cat);	// 我本意是想传入哪个动物就让谁说话，但是函数前不加virtual，会打印“动物在说话”

	Dog dog;
	doSpeak(dog);
}


void test02()
{
	cout << "sizeof(Animal) = " << sizeof(Animal) << endl;




}





int main()
{
	//test01();
	test02();

	system("pause");
	return 0;
}