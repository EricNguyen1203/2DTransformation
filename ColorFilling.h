#pragma once
#include "define.h"

#include <stack>

class ColorFilling
{
public:
    static bool isInScreen(int x, int y, int deltaX, int deltaY) {
        return (x >= deltaX && x < WIN_WIDTH - deltaX && y >= deltaY && y < WIN_LENGTH - deltaY);
    }

    static void boundaryFill(int x, int y, int layer, Color fillColor, Canvas& canvas, int nDirect = 4) {
        glColor3ub(fillColor.getRed(), fillColor.getGreen(), fillColor.getBlue());
        // Non-recursive implementation
        std::stack<std::pair<int, int>> s;
        s.push(std::make_pair(x, y));
        while (!s.empty()) {
            std::pair<int, int> p = s.top();
            s.pop();

            int x = p.first, y = p.second;
            Cell cell = canvas.getCell(y, x);

            // if (cell.isBoundary())
                // std::cout << x << " " << y << " is boundery" << std::endl;

            // std::cout << x << " " << y << std::endl;
            // if (cell.getLayer() != layer || cell.getColor() == fillColor || cell.isBoundary()) {
            // std::cout << cell.getLayer() << " " << layer << std::endl;
            if (cell.getLayer() == layer && (cell.getColor() == fillColor || cell.isBoundary())) {
                // std::cout << "Haha" << std::endl;
                continue;
            }

            Point(x, y).setPixel(canvas, fillColor, layer, false);

            if (isInScreen(x + 1, y, 0 ,0))
                s.push(std::make_pair(x + 1, y));
            if (isInScreen(x - 1, y, 0, 0))
                s.push(std::make_pair(x - 1, y));
            if (isInScreen(x, y + 1, 0, 0))
                s.push(std::make_pair(x, y + 1));
            if (isInScreen(x, y - 1, 0, 0))
                s.push(std::make_pair(x, y - 1));

            if (nDirect == 8) {
                if (isInScreen(x + 1, y + 1, 0, 0))
                    s.push(std::make_pair(x + 1, y + 1));
                if (isInScreen(x - 1, y - 1, 0, 0))
                    s.push(std::make_pair(x - 1, y - 1));
                if (isInScreen(x + 1, y - 1, 0, 0))
                    s.push(std::make_pair(x + 1, y - 1));
                if (isInScreen(x - 1, y + 1, 0, 0))
                    s.push(std::make_pair(x - 1, y + 1));
            }
        }
    }
};