#pragma once

#include "Polygon.h"
class Multiply : public Polygon
{
private:
	const int distanceNear = 50;
	const int distanceFar = 150;
public:
	Multiply(Point click, Color colorFill);

	void construct();

	std::string toString();
};

