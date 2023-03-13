#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int h1, h2, h3, h4;
    std::cin >> h1 >> h2 >> h3 >> h4;
    if (h1 >= h2 && h2 >= h3 && h3 >= h4 || h1 <= h2 && h2 <= h3 && h3 <= h4) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
