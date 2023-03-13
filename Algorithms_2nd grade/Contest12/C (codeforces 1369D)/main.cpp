#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, num;
    std::cin >> n;
    std::vector<uint64_t> arr;
    arr.push_back(0);
    arr.push_back(0);
    arr.push_back(0);
    for (int i = 3; i <= 2000000; ++i) {
        int paw = 0;
        if (i % 3 == 0) {
            paw = 4;
        }
        arr.push_back((2 * arr[i - 2] + arr[i - 1] + paw) % (1000000000 + 7));
    }
    for (int j = 0; j < n; ++j) {
        std::cin >> num;
        std::cout << arr[num] << '\n';
    }
}
