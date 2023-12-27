#pragma once
#include "Point.h"

#define I_3  std::vector<std::vector<double>>{{1, 0, 0}, {0, 1, 0}, { 0, 0, 1 }}
#define M_PI 3.14

class Matrix {
private:
    std::vector<std::vector<double>> Elements;

public:
    Matrix();

    Matrix(double m11, double m12, double m21, double m22, double m31, double m32);

public:
    // Resets this Matrix to have the elements of the identity matrix.
    void Reset();

    // Inverts this Matrix, if it is invertible.
    void Invert();

    // Multiplies this Matrix by the matrix specified in the `other` parameter, by appending the specified Matrix.
    // (this <- this * other)
    void Multiply(Matrix matrix);

    // Append to this Matrix a clockwise rotation, around the origin and by the specified angle (in degrees).
    void Rotate(double angle);


    // Applies the specified translation vector (offsetX and offsetY) to this Matrix by prepending the translation vector.
    void Translate(double offsetX, double offsetY);

    // Applies the specified shear vector to this Matrix by prepending the shear transformation.
    void Scale(double scaleX, double scaleY);

    // Applies the specified shear vector to this Matrix by prepending the shear transformation.
    void Shear(double shearX, double shearY);

    //  Applies the geometric transform represented by this Matrix to a specified array of points.
    Point TransformPoint(Point point);

    // Applies the geometric transform represented by this Matrix to a specified array of points.
    std::vector<Point> TransformPoints(std::vector<Point> points);
};