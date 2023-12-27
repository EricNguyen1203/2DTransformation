#pragma once

#include "Line.h"


class Polygon : public Shape
{
protected:
	std::vector<Point> vertices;
	
	Polygon(const Point& click, Color colorFill) : Shape(click, colorFill){}
	
	void draw(Canvas& canvas);

	void fill(Canvas& canvas);

	virtual void construct();

	std::string toString();
};

