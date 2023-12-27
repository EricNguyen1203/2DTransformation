#include "Circle.h"
#include "Line.h"
#include "ColorFilling.h"

Circle::Circle(Point click, Color colorFill) : Shape(click, colorFill) {
    center = clickmouse;
}

void Circle::fill(Canvas& canvas) {
	ColorFilling::boundaryFill(this->getCenter().getX(), this->getCenter().getY(), layer, colorFill, canvas);
	return;
}

void Circle::draw(Canvas& canvas) {
    glColor3ub(Color::m_BLACK.getRed(), Color::m_BLACK.getGreen(), Color::m_BLACK.getBlue());

    int x = 0, y = radius;
    int xT = center.getX(), yT = center.getY();
    int p = 1 - radius;

    Point startPoint = matrix.TransformPoint(Point(x + xT, y + yT));
    int minX = startPoint.getX(), maxX = startPoint.getX();
    int minY = startPoint.getY(), maxY = startPoint.getY();

    std::vector<Point> prevPoints;
    while (x <= y) {
        std::vector<Point> points = {
            Point(x + xT, y + yT),
            Point(y + xT, x + yT),
            Point(-x + xT, y + yT),
            Point(-y + xT, x + yT),
            Point(-x + xT, -y + yT),
            Point(-y + xT, -x + yT),
            Point(x + xT, -y + yT),
            Point(y + xT, -x + yT)
        };
        std::vector<Point> tmp;
        for (int i = 0; i < 8; i++) {
            Point newP = matrix.TransformPoint(points[i]);
            if (prevPoints.size() > 0) {
                Point prevP = prevPoints[i];
                Line(prevP, newP, layer).draw(canvas);
            }
            tmp.push_back(newP);
            newP.setPixel(canvas, Color::m_BLACK, layer, true);
            minX = std::min(minX, newP.getX());
            maxX = std::max(maxX, newP.getX());
            minY = std::min(minY, newP.getY());
            maxY = std::max(maxY, newP.getY());
        }
        prevPoints = tmp;

        if (p < 0) {
            p += 2 * x + 3;
        }
        else {
            p += 2 * (x - y) + 3;
            y--;
        }
        x++;
    }

	this->fill(canvas);
}

void Circle::construct() {
	center = matrix.TransformPoint(clickmouse);
    std::cout << "(" << center.getX() << " " << center.getY() << ")" << std::endl;
}

std::string Circle::toString() {
	return "Circle";
}

