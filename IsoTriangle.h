#pragma once
#include "Triangle.h"

class IsoTriangle : public Triangle
{
public:
	IsoTriangle(Point click, Color colorFill);

	void construct();

	std::string toString();
};

