#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, num, k, left, right, res;
    std::cin >> n;
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        std::cin >> num;
        if (num == 0) {
            arr[i] = arr[i - 1] + 1;
        } else {
            arr[i] = arr[i - 1];
        }
    }
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> left >> right;
        res = arr[right] - arr[left - 1];
        std::cout << res << ' ';
    }
}
