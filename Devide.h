#pragma once
#include "Polygon.h"

class Devide : public Polygon
{
private:
	int length = 50;
	int width = 300;
public:
	Devide(Point click, Color colorFill);

	void construct();

	std::string toString();
};


