#include "Matrix.h"
#include <cmath>


Matrix::Matrix() {
    Elements = I_3;
}

Matrix::Matrix(double m11, double m12, double m21, double m22, double m31, double m32) {
    Elements = {
        {m11, m12, 0},
        {m21, m22, 0},
        {m31, m32, 1} // Assuming this is a 3x3 matrix
    };
}

// Resets this Matrix to have the elements of the identity matrix.
void Matrix::Reset() {
    Elements = I_3;
}

// Inverts this Matrix, if it is invertible.
void Matrix::Invert() {
    // Check if the matrix is invertible (determinant is not zero)
    double determinant = Elements[0][0] * (Elements[1][1] * Elements[2][2] - Elements[1][2] * Elements[2][1]) -
        Elements[0][1] * (Elements[1][0] * Elements[2][2] - Elements[1][2] * Elements[2][0]) +
        Elements[0][2] * (Elements[1][0] * Elements[2][1] - Elements[1][1] * Elements[2][0]);

    if (determinant == 0.0) {
        // Matrix is not invertible
        // You might want to handle this case appropriately
        return;
    }

    // Calculate the inverse using the adjugate matrix
    double invDet = 1.0 / determinant;

    std::vector<std::vector<double>> adjugate(3, std::vector<double>(3, 0.0));

    adjugate[0][0] = Elements[1][1] * Elements[2][2] - Elements[1][2] * Elements[2][1];
    adjugate[0][1] = Elements[0][2] * Elements[2][1] - Elements[0][1] * Elements[2][2];
    adjugate[0][2] = Elements[0][1] * Elements[1][2] - Elements[0][2] * Elements[1][1];
    adjugate[1][0] = Elements[1][2] * Elements[2][0] - Elements[1][0] * Elements[2][2];
    adjugate[1][1] = Elements[0][0] * Elements[2][2] - Elements[0][2] * Elements[2][0];
    adjugate[1][2] = Elements[0][2] * Elements[1][0] - Elements[0][0] * Elements[1][2];
    adjugate[2][0] = Elements[1][0] * Elements[2][1] - Elements[1][1] * Elements[2][0];
    adjugate[2][1] = Elements[0][1] * Elements[2][0] - Elements[0][0] * Elements[2][1];
    adjugate[2][2] = Elements[0][0] * Elements[1][1] - Elements[0][1] * Elements[1][0];

    // Multiply each element in the adjugate matrix by the inverse determinant
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            adjugate[i][j] *= invDet;
        }
    }

    // Set the matrix to its inverse
    Elements = adjugate;
}

// Multiplies this Matrix by the matrix specified in the `other` parameter, by appending the specified Matrix.
void Matrix::Multiply(Matrix matrix) {
    // Create a temporary matrix to store the result
    std::vector<std::vector<double>> result(3, std::vector<double>(3, 0.0));

    // Perform matrix multiplication
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += Elements[i][k] * matrix.Elements[k][j];
            }
        }
    }

    // Update the current matrix with the result
    Elements = result;
}

// Append to this Matrix a clockwise rotation, around the origin and by the specified angle (in degrees).
void Matrix::Rotate(double angle) {
    // Convert angle from degrees to radians
    double radians = angle * M_PI / 180.0;

    // Create a rotation matrix
    Matrix rotationMatrix(
        std::cos(radians), -std::sin(radians),
        std::sin(radians), std::cos(radians),
        0.0, 0.0
    );

    // Multiply the current matrix by the rotation matrix
    Multiply(rotationMatrix);
}


// Applies the specified translation vector (offsetX and offsetY) to this Matrix by prepending the translation vector.
void Matrix::Translate(double offsetX, double offsetY) {
    Matrix translateMatrix = Matrix(
        1.0, 0.0,
        0.0, 1.0,
        offsetX, offsetY
    );

    Multiply(translateMatrix);
}

// Applies the specified shear vector to this Matrix by prepending the shear transformation.
void Matrix::Scale(double scaleX, double scaleY) {
    // Create a scaling matrix
    Matrix scalingMatrix(
        scaleX, 0.0, 
        0.0, scaleY,
        0.0, 0.0
    );

    // Multiply the scaling matrix with the current matrix
    Multiply(scalingMatrix);
}
// Applies the specified shear vector to this Matrix by prepending the shear transformation.
void Matrix::Shear(double shearX, double shearY) {
    // Create a shear matrix
    Matrix shearMatrix(
        1.0, shearX,
        shearY, 1.0,
        0.0, 0.0
    );

    // Multiply the shear matrix with the current matrix
    Multiply(shearMatrix);
}

//  Applies the geometric transform represented by this Matrix to a point.
Point Matrix::TransformPoint(Point point) {
    if (Elements == I_3) {
        return point;
    }

    double x = point.getX();
    double y = point.getY();
    int newX = round(Elements[0][0] * x + Elements[1][0] * y + Elements[2][0]);
    int newY = round(Elements[0][1] * x + Elements[1][1] * y + Elements[2][1]);

    return Point(newX, newY);
}

// Applies the geometric transform represented by this Matrix to a specified array of points.
std::vector<Point> Matrix::TransformPoints(std::vector<Point> points) {
    if (Elements == I_3) {
        return points;
    }

    std::vector<Point> newPoints;
    for (Point point : points) {
        newPoints.push_back(TransformPoint(point));
    }
    return newPoints;
}