#include <iostream>
using namespace std;

// 继承中的构造和析构顺序
class Dad
{
public:
	Dad() { cout << "Dad的构造函数！" << endl; }
	~Dad() { cout << "Dad的析构函数！" << endl; }
};

class son0:public Dad
{
public:
	son0() { cout << "son0的构造函数！" << endl; }
	~son0() { cout << "son0的析构函数！" << endl; }
};


void tes1()
{
	// Dad d;

	son0 s;		// 创建时，因为继承原因也会创建父类
	// 继承中的构造和析构的顺序如下：
	// 先构造父类，再构造子类；析构先析构子类再析构父类（与构造相反）
}






int main4()
{
	tes1();

	system("pause");
	return 0;

}