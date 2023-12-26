#pragma once
#include "Polygon.h"

class Rectangle : public Polygon
{
private:
	int length = 300;
	int width = 150;
public:
	Rectangle(Point click, Color colorFill);

	void construct();

	std::string toString();
};

