#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int first_max = 0, second_max = 0, x;
    std::cin >> x;
    while (x != 0) {
        if (x >= 100 && x <= 150) {
            if (x > first_max) {
                second_max = first_max;
                first_max = x;
            } else if (x > second_max) {
                second_max = x;
            }
        }
        std::cin >> x;
    }
    std::cout << first_max << '\n' << second_max;
}
