#include <iostream>
using namespace std;


//class CPP
//{
//public:
//	void header()
//	{
//		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
//	}
//
//	void footer()
//	{
//		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
//	}
//
//
//	void left()
//	{
//		cout << "Java、Python、C++公共课...(公共列表)" << endl;
//	}
//
//	void content()
//	{
//		cout << "C++学科视频" << endl;
//	}
//
//
//};


// 继承实现页面
class BasePage
{
public:
	void header()
	{
		cout << "首页、公开课、登录、注册...(公共头部)" << endl;
	}

	void footer()
	{
		cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
	}


	void left()
	{
		cout << "Java、Python、C++公共课...(公共列表)" << endl;
	}

	void content()
	{
		cout << "C++学科视频" << endl;
	}


};


// 继承的好处：减少重复的代码
// 语法————>    class 子类 : 继承方式 父类
// 子类 也成为 派生类
// 父类 也成为 基类

// 派生类中的成员，包含两大部分：
// 一部分是从基类继承过来的，一部分是自己增加的成员
// 从基类继承过来的表现其共性，而新增的成员体现了其个性



// CPP页面
class CPP :public BasePage
{
public:
	void content()
	{
		cout << "C++学科视频" << endl;
	}
};



// Java页面
class Java :public BasePage
{
public:
	void content()
	{
		cout << "Java学科视频" << endl;
	}
};



// Python页面
class Python :public BasePage
{
public:
	void content()
	{
		cout << "Python学科视频" << endl;
	}
};




void test01()
{
	cout << "C++ 下载视频页面如下：" << endl;
	CPP cpp;
	cpp.header();
	cpp.footer();
	cpp.left();
	cpp.content();

	cout << "————————————————————————" << endl;
	cout << "Java 下载视频页面如下：" << endl;
	Java ja;
	ja.header();
	ja.footer();
	ja.left();
	ja.content();

	cout << "————————————————————————" << endl;
	cout << "Python 下载视频页面如下：" << endl;
	Python Py;
	Py.header();
	Py.footer();
	Py.left();
	Py.content();
}







int main1()
{
	test01();

	system("pause");
	return 0;
}