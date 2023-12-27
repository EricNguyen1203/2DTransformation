#pragma once

#include "Line.h"


class Polygon : public Shape
{
protected:
	std::vector<Point> vertices;
	
	Polygon(const Point& click, Color colorFill) : Shape(click, colorFill){}

	virtual void construct() = 0;
	
	void draw(Canvas& canvas);

	void fill(Canvas& canvas);

	std::string toString();
};

