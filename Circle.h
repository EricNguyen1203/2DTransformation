#pragma once
#include "Shape.h"
class Circle : public Shape
{
private:
	const int radius = 100;
public:
	Circle(Point click, Color colorFill);

	void fill(Canvas& canvas);

	void draw(Canvas& canvas);

	std::string toString();
};

