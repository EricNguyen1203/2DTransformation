#pragma once
#include "Triangle.h"

class EquilTriangle : public Triangle
{
public:
	EquilTriangle(Point click, Color colorFill);

	void construct(); 

	std::string toString();
};

