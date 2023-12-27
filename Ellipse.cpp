#include "Ellipse.h"
#include "ColorFilling.h"

Ellipse::Ellipse(Point click, Color colorFill) : Shape(click, colorFill) {
	center = clickmouse;
}

void Ellipse::draw(Canvas& canvas) {
	glColor3ub(Color::m_BLACK.getRed(), Color::m_BLACK.getGreen(), Color::m_BLACK.getBlue());

    if (a <= 0 || b <= 0) {
        return;
    }

    // Draw boundary
    int xT = center.getX(), yT = center.getY();
    int x = 0, y = b;
    int p;
    int x0 = round(a * a * 1.0 / (sqrt(a * a + b * b)));

    Point startPoint = matrix.TransformPoint(Point(x + xT, y + yT));
    int minX = startPoint.getX(), maxX = startPoint.getX();
    int minY = startPoint.getY(), maxY = startPoint.getY();

    std::vector<Point> prevPoints;
    // First region
    p = round(a * a / 4 + b * b - a * a * b);
    while (x <= x0) {
        // Translate the points to its actual position then set pixels
        std::vector<Point> points = {
            Point(x + xT, y + yT),
            Point(-x + xT, y + yT),
            Point(x + xT, -y + yT),
            Point(-x + xT, -y + yT)
        };
        std::vector<Point> tmp;
        for (int i = 0; i < 4; i++) {
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
            p += b * b * (2 * x + 3);
        }
        else {
            p += b * b * (2 * x + 3) - a * a * (2 * y - 2);
            y--;
        }
        x++;
    }

    // Second region
    p = round(b * b * (x + 1 / 2) * (x + 1 / 2) + a * a * (y - 1) * (y - 1) - a * a * b * b);
    while (y >= 0) {
        std::vector<Point> points = {
            Point(x + xT, y + yT),
            Point(-x + xT, y + yT),
            Point(x + xT, -y + yT),
            Point(-x + xT, -y + yT)
        };
        std::vector<Point> tmp;
        for (int i = 0; i < 4; i++) {
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
            p += b * b * (2 * x + 2) - a * a * (2 * y - 3);
            x++;
        }
        else {
            p -= a * a * (2 * y - 3);
        }
        y--;
    }

	this->fill(canvas);
}


void Ellipse::fill(Canvas& canvas) {
	ColorFilling::boundaryFill(this->getCenter().getX(), this->getCenter().getY(), layer, colorFill, canvas);
	return;
}

void Ellipse::construct() {
	center = matrix.TransformPoint(clickmouse);
}

std::string Ellipse::toString() {
	return "Ellipse";
}
