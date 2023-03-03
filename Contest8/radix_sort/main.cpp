#include <iostream>
#include <cmath>

int numOfDigits(int num) {
    int k = 0;
    while (num > 0) {
        ++k;
        num /= 256;
    }
    return k;
}

int digit(int num, int pos, int delta) {
    return (num / static_cast<int>(std::pow(256 + delta, pos - 1))) % (256 + delta);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, num, max_digit = 0, d, count, tmp, maxi, mini, delta = 0;
    std::cin >> n;
    int *arr = new int[n], *res = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        if (i == 0) {
            maxi = num;
            mini = num;
        }
        maxi = std::max(maxi, num);
        mini = std::min(mini, num);
        arr[i] = num;
        max_digit = std::max(max_digit, numOfDigits(std::abs(num)));
    }

    if (mini < 0) {
        delta = mini * -1;
    }
    int *counts = new int[256 + delta];
    for (int i = 1; i <= max_digit; ++i) {
        for (int j = 0; j < 256 + delta; ++j) {
            counts[j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            d = digit(arr[j] + delta, i, delta);
            ++counts[d];
        }
        count = 0;
        for (int j = 0; j < 256 + delta; ++j) {
            tmp = counts[j];
            counts[j] = count;
            count += tmp;
        }
        for (int j = 0; j < n; ++j) {
            d = digit(arr[j] + delta, i, delta);
            res[counts[d]] = arr[j];
            ++counts[d];
        }
        for (int j = 0; j < n; ++j) {
            arr[j] = res[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << res[i] << ' ';
    }
    delete[] arr;
    delete[] res;
    delete[] counts;
}