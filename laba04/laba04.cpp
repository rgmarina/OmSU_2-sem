#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double a, b, c, xstart, xend, dx;
    std::cout << "print a, b, c:";
    std::cin >> a >> b >> c;
    std::cout << "print start x:";
    std::cin >> xstart;
    std::cout << "print final x:";
    std::cin >> xend;
    std::cout << "print step:";
    std::cin >> dx;
    std::cout << std::setw(5) << "X" << "|\t" << std::setw(10) << "F(X)" << std::endl;//std::cout << "X\t|\tF(X)"; манипулятор ширины поле
    std::cout << "--------------------" << std::endl;
    for (double x = xstart; x <= xend; x += dx) {
        double F;
        if (x < 0 && b != 0) {
            F = a * pow(x, 2) + b;//возводим х в степеь 2 (pow)
        }
        else if (x > 0 && b == 0) {
            F = (x - a) / (x - c);
        }
        else {
            F = x / c;
        }
        int AC = static_cast<int>(a); //возвращаем перемнную типа int
        int BC = static_cast<int>(b);
        int CC = static_cast<int>(c);
        int condition = (AC | BC) & (AC | CC);
        if (condition != 0) {
            std::cout << std::fixed << std::setprecision(2) << std::setw(4) << x << "|\t" << std::setw(6) << F << std::endl;//std::cout << x << "\t|\t" << F; числа с плавающей (,) в десятичном формате

        }
        else {
            std::cout << std::fixed << std::setprecision(2) << std::setw(4) << x << "|\t" << std::setw(6) << static_cast<int>(F) << std::endl;//std::cout << x << "\t|\t" << static_cast<int>(F) << std::endl;
        }
    }
    return 0;

}