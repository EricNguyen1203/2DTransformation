#include "Add.h"

Add::Add(Point click, Color colorFill) : Polygon(click, colorFill) {
    this->construct();
}

void Add::construct() {
    vertices.clear();

    const int numVertices = 12;  // Pentagon has 5 vertices

    // Calculate the angle between vertices
    double angleIncrement = 2 * M_PI / numVertices;
    double beginAngle = 0 - angleIncrement / 2;

    // Initialize min and max coordinates with the first vertex
    int minX = clickmouse.getX() + distanceFar * std::cos(beginAngle);
    int minY = clickmouse.getY() + distanceFar * std::sin(beginAngle);
    vertices.push_back(Point(minX, minY));
    int maxX = minX;
    int maxY = minY;

    // Iterate through the other vertices
    for (int i = 1; i < numVertices; ++i) {
        double angle = beginAngle + i * angleIncrement;

        int distance = (i % 3 == 2) ? distanceNear : distanceFar;

        // Calculate the coordinates of the current vertex
        int vertexX = clickmouse.getX() + static_cast<int>(distance * std::cos(angle));
        int vertexY = clickmouse.getY() + static_cast<int>(distance * std::sin(angle));
        vertices.push_back(Point(vertexX, vertexY));

        // Update min and max coordinates
        minX = std::min(minX, vertexX);
        minY = std::min(minY, vertexY);
        maxX = std::max(maxX, vertexX);
        maxY = std::max(maxY, vertexY);
    }

    // Set the bottomLeft and topRight points
    bottomLeft.setX(minX);
    bottomLeft.setY(minY);
    topRight.setX(maxX);
    topRight.setY(maxY);

    Polygon::construct();
}

std::string Add::toString() {
    return "Add";
}