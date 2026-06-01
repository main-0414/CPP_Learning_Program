#include <iostream>
using namespace std;

// 类对象作为另一个类的成员

// 手机 类
class Phone
{
public:

	Phone(string brand)		// 调用的时候直接告诉品牌名称
	{
		m_brand = brand;
		cout << "Phone 构造函数调用" << endl;
	}

	~Phone() { cout << "Phone 析构" << endl; }

	// 成员变量
	string m_brand;	// 品牌

};



// 人 类
class human
{
public:
												//  Phone m_phone = brand 隐式转换法
	human(string name, string brand) :m_name(name), m_phone(brand)	//一上来就知道这个人的手机品牌
	{
		cout << "human 构造" << endl;
	}

	~human() { cout << "human 析构" << endl; }

	// 成员变量
	// 姓名
	string m_name;
	// 手机
	Phone m_phone;	// 手机对象 m_phone（Phone 类型），作为人的成员
};


// 当其他类的对象，作为本类的成员，构造时先构造其他类的对象，再构造自身
// 析构时，先析构自身再析构其他类对象（构造时和析构时顺序相反）
void T1()
{
	human h("吴京", "苹果");
	cout << h.m_name << "拿着" << h.m_phone.m_brand <<"牌手机" << endl;
}



int main7()
{
	// 那么先构造人还是先构造手机呢？
	T1();	// Phone先构造，先要有胳膊腿才能构造出人


	system("pause");
	return 0;
}