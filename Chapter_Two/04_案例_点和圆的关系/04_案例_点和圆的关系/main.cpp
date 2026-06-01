#include <iostream>
#include <cmath>
using namespace std;

#include "Circle.h"
#include "Point.h"

// 点和圆的关系
// 设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。

// 点到圆的距离 == 半径	点在圆上
// 点到圆的距离	> 半径	点在圆外
// 点到圆的距离	< 半径	点在圆内

// 圆心和点的距离：两点距离公式	sqrt( (x1-x2)^2 + (y1-y2)^2 )

// 点类
//class Point
//{
//public:
//	void setX(int x) { m_X = x; }
//	void setY(int y) { m_Y = y; }
//	int getX() { return m_X; }
//	int getY() { return m_Y; }
//
//private:
//	int m_X;
//	int m_Y;
//};



// 圆类
//class Circle
//{
//public:
//	void setR(int r) { m_R = r; }
//	int getR() { return m_R; }
//
//	void setCenter(Point& center) { m_Center = center; }
//	Point getCenter() { return m_Center; }
//
//
//private:
//	int m_R;	// 半径
//
//	// 在类中可以让另一个类 作为本来中的成员
//	Point m_Center;		// 圆心
//
//};

// 判断点和圆的关系
void isInCircle(Circle& circle, Point& point)
{
	// 两点之间距离
	int distance = sqrt(
		(circle.getCenter().getX() - point.getX()) * (circle.getCenter().getX() - point.getX()) +
		(circle.getCenter().getY() - point.getY()) * (circle.getCenter().getY() - point.getY())
	);

	// 判断
	if (distance == circle.getR())
	{
		cout << "点在圆上！" << endl;
	}
	else if (distance > circle.getR())
	{
		cout << "点在圆外！" << endl;
	}
	else
	{
		cout << "点在圆内!" << endl;
	}

}


int main()
{
	// 创建圆
	Circle c1;
	c1.setR(10);

	Point c1_Center;
	c1_Center.setX(10);
	c1_Center.setY(0);
	c1.setCenter(c1_Center);


	// 创建点
	Point p1;

	p1.setX(10);
	p1.setY(10);
	cout << "p1："; isInCircle(c1, p1);


	Point p2;
	p2.setX(3);
	p2.setY(3);
	cout << "p2：";isInCircle(c1, p2);


	Point p3;
	p3.setX(10);
	p3.setY(11);
	cout << "p3：";isInCircle(c1, p3);



	system("pause");
	return 0;
}