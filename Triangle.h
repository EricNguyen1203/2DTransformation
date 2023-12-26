#pragma once
#include "Polygon.h"

class Triangle : public Polygon
{
protected:
	const int distance = 100;
public:
	Triangle(Point click, Color colorFill) : Polygon(click, colorFill){}

	std::string toString() {
		return "Triangle";
	}

	virtual void construct() = 0;
};

