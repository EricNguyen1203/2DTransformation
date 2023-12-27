#pragma once
#include "Shape.h"
#include "Line.h"

class Ellipse : public Shape
{
private:
	const int a = 150;
	const int b = 80;
	Point center;
public:
	Ellipse(Point click, Color colorFill);

	void draw(Canvas& canvas);

	void fill(Canvas& canvas);

	void construct();

	std::string toString();
};



