#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k, x;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        arr[i] = x;
    }
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> x;
        --arr[x - 1];
    }
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            std::cout << "yes\n";
        } else {
            std::cout << "no\n";
        }
    }
    delete[] arr;
}