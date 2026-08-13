#include <iostream>

class Triangle {
private:
    double totalAngle, angleA, angleB, angleC;
public:
    Triangle(double A, double B, double C);
    void setAngles(double A, double B, double C);
    const bool validateTriangle();
};

int main() {
    Triangle set1(40, 50, 110);
    if (set1.validateTriangle()) {
        std::cout << "the shape is a valid triangle \n";
    } else {
        std::cout << "the shape is not a valid triangle \n";
    }
    return 0;
}

Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}

const bool Triangle::validateTriangle() {
    return (totalAngle <= 180);
}