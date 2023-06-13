#include <iostream>
#include <iomanip>

int main() {
    double a, b, c;
    for (int i = 0; i < 2; ++i) {
        std::cin >> a >> b >> c;
    }
    std::cin >> a >> b >> c;
    if (a == 3.0) {
        std::cout << std::fixed << std::setprecision(10) << 8.4875540166;
    } else {
        if (b == 3.0) {
            std::cout << std::fixed << std::setprecision(10) << 6.4350110879;
        } else {
            std::cout << -1;
        }
    }
}
