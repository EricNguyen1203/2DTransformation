#pragma once
#include "Polygon.h"
class Add : public Polygon
{
private:
	const int distanceNear = 50;
	const int distanceFar = 150;
public:
	Add(Point click, Color colorFill);

	void construct();

	std::string toString();
};

