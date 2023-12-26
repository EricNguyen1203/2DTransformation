#pragma once
#include "Shape.h"

class Line : public Shape
{
private:
	bool isEdge;
public:
	Line(Point click, Color colorFill);
	Line(Point start, Point end, int layer);	// Use for draw edge

	void draw(Canvas& canvas);

	void fill(Canvas& canvas);

	std::string toString();
};

