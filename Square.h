#pragma once
#include "Polygon.h"
class Square : public Polygon
{
private:
	const int side = 200;
public:
	Square(Point click, Color colorFill);

	void construct();

	std::string toString();
};

