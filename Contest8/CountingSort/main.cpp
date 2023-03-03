#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x, maxi, mini, delta = 0, right_border;
    std::cin >> n;
    int *arr = new int[n], *res = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (i == 0) {
            maxi = x;
            mini = x;
        }
        maxi = std::max(maxi, x);
        mini = std::min(mini, x);
        arr[i] = x;
    }

    right_border = maxi + 1;
    if (mini < 0) {
        delta = mini * -1;
    }
    int *counts = new int[right_border + delta];
    for (int i = 0; i < right_border + delta; ++i) {
        counts[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++counts[arr[i] + delta];
    }
    for (int i = mini + delta + 1; i < right_border + delta; ++i) {
        counts[i] += counts[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        --counts[arr[i] + delta];
        res[counts[arr[i] + delta]] = arr[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ';
    }

    delete[] arr;
    delete[] counts;
    delete[] res;
}