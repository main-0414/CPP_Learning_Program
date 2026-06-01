#include <iostream>
using namespace std;

class father
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class son :public father
{
public:

	int m_D;
};

// 利用开发人员命令提示符工具查看对象模型
// 跳转盘符	D:
// 跳转文件路径 cd 具体路径下
// 查看命名 cl /d1 reportSingleClassLayout+(类名) "文件名称.cpp"
//	




void te1()
{
	cout << "size of son = " << sizeof(son) << endl;	// 结果16
	// 在父类中，所有非静态成员属性都会被子类继承下去
	// 父类中私有成员属性 是被编译器给隐藏了，因此是访问不到的，但是确实被继承了
}



int main3()
{
	te1();



	system("pause");
	return 0;
}