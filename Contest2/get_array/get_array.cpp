#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, num, k = 0, razr_max = 0, razr;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        num = abs(num);
        razr = 0;
        while (num > 0) {
            if (num % 2 == 1) {
                if (razr > razr_max) {
                    razr_max = razr;
                }
                k += num % 2;
            }
            num /= 2;
            ++razr;
        }
    }
    k += razr_max;
    std::cout << k;
    return 0;
}