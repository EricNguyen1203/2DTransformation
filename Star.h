#pragma once
#include "Polygon.h"

class Star : public Polygon
{
private:
	const int distanceNear = 50;
	const int distanceFar = 150;
public:
	Star(Point click, Color colorFill);

	void construct();

	std::string toString();
};

