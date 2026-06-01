#include <iostream>
#include <string>
#include <cstdlib>  // 【必要修改1】补全system("pause")需要的头文件，不影响你的逻辑
using namespace std;

// 成员属性设置私有
// 1.可以自己控制读写权限
// 2.对于写，可以检测数据有效性

class Person
{
public:
	// 默认构造，确保成员正确初始化
	//Person() : m_Name(""), m_Age(18), m_Idol("") {}  // 【必要修改2】初始化所有成员，彻底解决乱码，保留你的注释

	// 设置姓名
	void setName(string name)
	{
		m_Name = name;
	}

	// 获取姓名
	string getName()
	{
		return m_Name;
	}



	// 给年龄界定范围（1~150）
	void setAge(int age)
	{
		if (age < 0 || age >= 150)
		{
			cout << "年龄 " << age << " 输入有误，赋值失败" << endl;
			return;
		}
		else
		{
			m_Age = age;
		}
	}

	// 获取年龄
	int getAge()
	{
		return m_Age;
	}



	// 设置偶像
	void setIdol(string Idol)
	{
		m_Idol = Idol;
	}


private:
	string m_Name;	// 姓名，可读可写

	int m_Age = 18; 	// 年龄  只读(所以直接给他一个数据毕竟外面不能改了)

	string m_Idol; 	// 偶像  只写

};


int main()
{

	// 实例化
	Person man;

	// 姓名设置
	man.setName("观观王");
	cout << "姓名：" << man.getName() << endl;



	// 年龄获取（只能获取）
	//man.m_Age = 100;	// 不可访问
	man.setAge(160); 	// 没有成员
	cout << "年龄：" << man.getAge() << endl;

	// 设置偶像
	man.setIdol("Osako");
	//cout << "偶像：" << man.m_Idol << endl;
	//cout << "偶像：" << man.getIdol() << endl; 		// 只写状态，外界访问不了

	system("pause");  // 给你加回来，方便看结果，不需要可以删掉
	return 0;
}