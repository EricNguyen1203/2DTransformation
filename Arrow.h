#pragma once
#include "Polygon.h"
class Arrow : public Polygon
{
private:
	const int length = 300;
	const int width = 150;
public:
	Arrow(Point click, Color colorFill);

	void construct();

	std::string toString();
};

