#pragma once
#include "Polygon.h"

class Pentagon : public Polygon
{
private: 
	const int distance = 150;
public:
	Pentagon(Point click, Color colorFill);

	void construct();

	std::string toString();
};

