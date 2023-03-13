#include <iostream>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, k;
    double res;
    std::cin >> n >> m >> k;
    res = static_cast<double>(n) * k / m;
    if (res != floor(res)) {
        res = floor(res) + 1;
    }
    std::cout << res;
}
