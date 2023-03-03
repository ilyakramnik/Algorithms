#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n + k);
    for (int i = 1; i <= k; ++i) {
        arr[i] = 1;
    }
    for (int i = k + 1; i < n + k; ++i) {
        for (int j = i - 1; j >= i - k && j >= k; --j) {
            arr[i] += arr[j];
        }
    }
    std::cout << arr[n + k - 1];
}