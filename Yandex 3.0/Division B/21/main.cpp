#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << 2;
    } else if (n == 2) {
        std::cout << 4;
    } else if (n == 3) {
        std::cout << 7;
    } else {
        std::vector<int> arr(n + 1);
        arr[1] = 2, arr[2] = 4, arr[3] = 7;
        for (int i = 4; i < n + 1; ++i) {
            arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
        }
        std::cout << arr[n];
    }
}
