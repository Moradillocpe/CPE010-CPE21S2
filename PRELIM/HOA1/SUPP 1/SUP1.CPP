#include <iostream>

bool swapNumbers(double &a, double &b);

int main() {
    double x = 6, y = 7;

    std::cout << "Before swap: x = " << x << ", y = " << y << "\n";
    bool success = swapNumbers(x, y);
    std::cout << "After swap:  x = " << x << ", y = " << y << "\n";
    std::cout << "Swap successful: " << success << "\n";

    return 0;
}

bool swapNumbers(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
    return true;
}