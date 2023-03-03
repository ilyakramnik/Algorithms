#include <iostream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x2, x3, x4;
    std::cin >> n;
    if (static_cast<int>(sqrt(n)) * static_cast<int>(sqrt(n)) == n) {
        std::cout << static_cast<int>(sqrt(n));
        return 0;
    }
    for (x2 = ceil(sqrt(n)); x2 >= 0; --x2) {
        for (x3 = ceil(sqrt(n - x2 * x2)); x3 >= 0; --x3) {
            for (x4 = ceil(sqrt(n - x2 * x2 - x3 * x3)); x4 >= 0; --x4) {
                if (x4 * x4 == n) {
                    std::cout << x4;
                    return 0;
                } else if (x3 * x3 + x4 * x4 == n) {
                    std::cout << x4 << ' ' << x3;
                    return 0;
                } else if (x4 * x4 + x3 * x3 + x2 * x2 == n) {
                    std::cout << x4 << ' ' << x3 << ' ' << x2;
                    return 0;
                } else if (int(sqrt(n - x2 * x2 - x3 * x3 - x4 * x4)) ==
                           sqrt(n - x2 * x2 - x3 * x3 - x4 * x4)) {
                    std::cout << x4 << ' ' << x3 << ' ' << x2 << ' '
                              << sqrt(n - x2 * x2 - x3 * x3 - x4 * x4);
                    return 0;
                }
            }
        }
    }
}
