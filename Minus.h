#pragma once
#include "Polygon.h"

class Minus : public Polygon
{
private:
	int length = 300;
	int width = 50;
public:
	Minus(Point click, Color colorFill);

	void construct();

	std::string toString();
};



