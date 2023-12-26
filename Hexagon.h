#pragma once
#include "Polygon.h"

class Hexagon : public Polygon
{
private:
	const int distance = 150;
public:
	Hexagon(Point click, Color colorFill);

	void construct();

	std::string toString();
};

