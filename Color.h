#pragma once
#include "define.h"
#include <unordered_map>


class Color{
private:
    int r;
    int g;
    int b;
public:
    static Color m_BLACK;
    static Color m_WHITE;
    static Color m_RED;
    static Color m_GREEN;
    static Color m_BLUE;
    static Color m_YELLOW;
    static Color m_MAGENTA;
    static Color m_CYAN;
    static std::unordered_map<int, Color> colorMap;


    int getRed();

    int getGreen();

    int getBlue();

    Color(int r, int g, int b) : r(r), g(g), b(b){}

    Color();

    void setColor(int r, int g, int b);

    bool operator==(Color other) {
        return r == other.r && g == other.g && b == other.b;
    }

    bool operator!=(Color other) {
        return !(*this == other);
    }
};

