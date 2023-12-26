#pragma once

#include "Line.h"


class Polygon : public Shape
{
protected:
	std::vector<Point> vertices;
	const float M_PI = 3.14;
	
	Polygon(const Point& click, Color colorFill) : Shape(click, colorFill){}

	virtual void construct() = 0;

	virtual void findFillPoint();
	
	void draw(Canvas& canvas);

	void fill(Canvas& canvas);

	std::string toString();
};

