#include "Matrix.h"


Matrix::Matrix() {

}

Matrix::Matrix(double m11, double m12, double m21, double m22, double m31, double m32) {

}

// Resets this Matrix to have the elements of the identity matrix.
void Matrix::Reset() {

}

// Inverts this Matrix, if it is invertible.
void Matrix::Invert() {

}

// Multiplies this Matrix by the matrix specified in the `other` parameter, by appending the specified Matrix.
// (this <- this * other)
void Matrix::Multiply(Matrix matrix) {

}

// Append to this Matrix a clockwise rotation, around the origin and by the specified angle (in degrees).
void Matrix::Rotate(double angle) {

}


// Applies the specified translation vector (offsetX and offsetY) to this Matrix by prepending the translation vector.
void Matrix::Translate(double translateX, double translateY) {

}

// Applies the specified shear vector to this Matrix by prepending the shear transformation.
void Matrix::Scale(double scaleX, double scaleY) {

}

// Applies the specified shear vector to this Matrix by prepending the shear transformation.
void Matrix::Shear(double shearX, double shearY) {

}

//  Applies the geometric transform represented by this Matrix to a specified array of points.
Point Matrix::TransformPoint(Point point) {

}

// Applies the geometric transform represented by this Matrix to a specified array of points.
std::vector<Point> Matrix::TransformPoints(std::vector<Point> points) {

}