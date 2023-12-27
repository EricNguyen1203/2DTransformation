#pragma once
#include "Point.h"
#include "Matrix.h"

#include <string>

class Shape {
protected:
    Point bottomLeft;
    Point topRight;
    Point clickmouse;
    Point start, end; // use for drawing edge
    int layer;
    Point fillPoint;
    Color colorFill;
    bool isSelecting = false;
    Matrix matrix;
public:
    static int layerOder;
    // Constructors
    //Shape();
    Shape(Point click, Color colorFill);

    Shape(Point start, Point end, int layer, Color colorFill = Color::m_BLACK);  // use for drawing edge

    // Getter functions
    Point getBottomLeft() const;
    Point getTopRight() const;
    Point getCenter() const;
    Point getStart() const;
    Point getEnd() const;
    int getLayer() const;
    Color getColor() const;

    virtual void findFillPoint() {};

    virtual void draw(Canvas& canvas) = 0;

    virtual void fill(Canvas& canvas) = 0;

    virtual std::string toStrong();

    virtual void setColor(Color color);

    virtual void setSelectingShape(bool isSelected);

    virtual void construct() = 0;

    virtual ~Shape() {}

public:
    virtual void translate(double dx, double dy);

    virtual void rotate(double angle);

    virtual void scale(double sx, double sy);
};


