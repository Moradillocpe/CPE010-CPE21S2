#include <iostream>

void showSum(double a, double b);
bool isGreater(double a, double b);
bool logicOps(bool a, bool b);

int main() {
    double a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;

    showSum(a, b);
    std::cout << a << (isGreater(a, b) ? " is" : " is NOT") << " greater than " << b << ".\n";
    logicOps(true, false);

    return 0;
}

void showSum(double a, double b) {
    std::cout << "Sum: " << a + b << "\n";
}

bool isGreater(double a, double b) {
    return a > b;
}

bool logicOps(bool a, bool b) {
    std::cout << "AND: " << (a && b) << " OR: " << (a || b) << " NOT A: " << !a << " NOT B: " << !b << "\n";
    return true;
}