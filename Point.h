#pragma once

#include <iostream>
#include <vector>
#include <GL/glut.h>
#include "Canvas.h"


class Point {
private:
    int x;
    int y;

public:
    // Constructors
    Point();
    Point(int x, int y);

    // Getter functions
    void setX(int xNew);
    void setY(int yNew);
    int getX() const ;
    int getY() const ;

    // Overloaded + operator for adding two points
    Point operator+(const Point& other);

    Point change(int x, int y);

    void setPixel(Canvas& canvas, Color color, int layer, bool boundary);
};

