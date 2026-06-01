#pragma once
#include <iostream>
using namespace std;

#include "Point.h"


// 圆类
class Circle
{
public:
	void setR(int r);
	int getR();

	void setCenter(Point& center);
	Point getCenter();


private:
	int m_R;	// 半径

	// 在类中可以让另一个类 作为本来中的成员
	Point m_Center;		// 圆心

};