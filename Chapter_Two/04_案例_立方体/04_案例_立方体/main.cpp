#include <iostream>
using namespace std;

// 立方体类设计
// 1.创建立方体类
// 2.设计属性
// 3.设计行为 获取立方体面积和体积
// 4.分别利用全局函数和成员函数 判断两个立方体是否相等

class Cube
{
public:

	// 设置长
	void setLong(int longg) { m_Long = longg; }

	// 获取长
	int getLong() { return m_Long; }

	// 设置宽
	void setWide(int Wide) { m_Wide = Wide; }

	// 获取宽
	int getWide() { return m_Wide; }

	// 设置高
	void setHeight(int Height) { m_Hight = Height; }

	// 获取高
	int getHeight() { return m_Hight; }


	// 获取立方体的面积
	int calculateS()
	{
		return 2 * m_Long * m_Hight + 2 * m_Wide * m_Hight + 2 * m_Long * m_Wide ;
	}


	// 获取立方体的体积
	int calculateV()
	{
		return m_Long * m_Wide * m_Hight;
	}

	// 利用成员函数判断两个立方体是否相等
	bool isSameByClass(Cube& c)	// 成员函数需要已知的成员来调用，所以参数只用写一个和他对比的
	{
		if (m_Long == c.getLong() && m_Wide == c.getWide() && m_Hight == c.getHeight())
		{
			return true;
		}
		else
		{
			return false;
		}
	}




private:	// 属性一般在praivate里

	int m_Long;		// 长
	int m_Wide;		// 宽
	int m_Hight;	// 高 


};




// 利用全局函数判断 两个立方体是否相等
bool isSame(Cube& c1, Cube& c2)
{
	if (c1.getLong() == c2.getLong() && c1.getWide() == c2.getWide() && c1.getHeight() == c2.getHeight())
	{
		return true;
	}
	else
	{
		return false;
	}
}





int main()
{
	// 实例化立方体对象
	Cube c1;
	c1.setLong(10);
	c1.setHeight(10);
	c1.setWide(10);

	cout << "c1的面积为：" << c1.calculateS() << endl;
	cout << "c1的体积为：" << c1.calculateV() << endl;


	// 创建第二个立方体
	Cube c2;
	c2.setLong(10);
	c2.setHeight(10);
	c2.setWide(11);

	// 利用全局函数判断
	bool ret = isSame(c1, c2);
	if (ret)
	{
		cout << "c1和c2是相等的" << endl;
	}
	else
	{
		cout<< "c1和c2是不相等的" << endl;
	}


	// 利用成员函数判断
	ret = c1.isSameByClass(c2);
	if (ret)
	{
		cout << "成员函数判断：c1和c2是相等的" << endl;
	}
	else
	{
		cout << "成员函数判断：c1和c2是不相等的" << endl;
	}

	system("pause");
	return 0;
}