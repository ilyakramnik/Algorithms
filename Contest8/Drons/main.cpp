#include <iostream>
#include <cmath>

int numOfDigits(int num) {
    int k = 0;
    while (num > 0) {
        ++k;
        num /= 10;
    }
    return k;
}

int digit(int num, int pos) {
    return (num / static_cast<int>(std::pow(10, pos - 1))) % 10;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, id, carrying, max_digit = 0, d, count, tmp;
    std::cin >> n;
    std::pair<int, int> *arr = new std::pair<int, int>[n], *res = new std::pair<int, int>[n];
    int *counts = new int[10];
    for (int i = 0; i < n; ++i) {
        std::cin >> id >> carrying;
        std::pair<int, int> drone;
        drone.first = carrying;
        drone.second = id;
        arr[i] = drone;
        max_digit = std::max(max_digit, numOfDigits(carrying));
    }
    for (int i = 1; i <= max_digit; ++i) {
        for (int j = 0; j < 10; ++j) {
            counts[j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            d = digit(arr[j].first, i);
            ++counts[d];
        }
        count = 0;
        for (int j = 9; j >= 0; --j) {
            tmp = counts[j];
            counts[j] = count;
            count += tmp;
        }
        for (int j = 0; j < n; ++j) {
            d = digit(arr[j].first, i);
            res[counts[d]] = arr[j];
            ++counts[d];
        }
        for (int j = 0; j < n; ++j) {
            arr[j] = res[j];
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << res[i].second << '\t' << res[i].first << '\n';
    }
    delete[] arr;
    delete[] res;
    delete[] counts;
}