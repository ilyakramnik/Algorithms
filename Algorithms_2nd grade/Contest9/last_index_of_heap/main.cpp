#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x, i;
    std::cin >> n;
    std::vector<int> heap;
    for (i = 0; i < n; ++i) {
        std::cin >> x;
        heap.push_back(x);
        if (i > 0) {
            if (i % 2 == 0) {
                if (heap[i] > heap[i / 2 - 1]) {
                    std::cout << i - 1;
                    return 0;
                }
            } else if (i % 2 != 0) {
                if (heap[i] > heap[i / 2]) {
                    std::cout << i - 1;
                    return 0;
                }
            }
        }
    }
    std::cout << i - 1;
}