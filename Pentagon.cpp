#include "Pentagon.h"

Pentagon::Pentagon(Point click, Color colorFill) : Polygon(click, colorFill){
    this->construct();
}

void Pentagon::construct() {
    vertices.clear();

    const int numVertices = 5;  // Pentagon has 5 vertices

    // Calculate the angle between vertices
    double angleIncrement = 2 * M_PI / numVertices;

    // Initialize min and max coordinates with the first vertex
    int minX = clickmouse.getX() + distance * std::sin(0);
    int minY = clickmouse.getY() + distance * std::cos(0);
    vertices.push_back(Point(minX, minY));
    int maxX = minX;
    int maxY = minY;

    // Iterate through the other vertices
    for (int i = 1; i < numVertices; ++i) {
        double angle = i * angleIncrement;

        // Calculate the coordinates of the current vertex
        int vertexX = clickmouse.getX() + static_cast<int>(distance * std::sin(angle));
        int vertexY = clickmouse.getY() + static_cast<int>(distance * std::cos(angle));
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

std::string Pentagon::toString() {
	return "Pentagon";
}