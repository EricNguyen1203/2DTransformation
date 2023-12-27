#pragma once
#include "Shape.h"
class Circle : public Shape
{
private:
	const int radius = 100;
	Point center;
public:
	Circle(Point click, Color colorFill);

	void fill(Canvas& canvas);

	void draw(Canvas& canvas);

	void construct();

	std::string toString();
};

