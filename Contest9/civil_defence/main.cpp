#include <iostream>
#include <vector>
#include <cmath>

int binarySearch(std::pair<int, int> *arr, int size, int key, std::vector<int> &village, int i) {
    int l = -1, r = size, m;
    while (l < r - 1) {
        m = l + (r - l) / 2;
        if (arr[m].first < key) {
            l = m;
        } else {
            r = m;
        }
    }
    if (l == size - 1) {
        return arr[l].second;
    }
    if (r == 0) {
        return arr[r].second;
    }
    if (l >= 0 && l < size) {
        if (std::abs(village[i] - arr[l].first) <= std::abs(village[i] - arr[l + 1].first)) {
            return arr[l].second;
        }
        return arr[l + 1].second;
    }
    if (std::abs(village[i] - arr[r].first) <= std::abs(village[i] - arr[r - 1].first)) {
        return arr[r].second;
    }
    return arr[r - 1].second;
}

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

void radixSort(std::pair<int, int> *res, int n) {
    int carrying, max_digit = 0, d, count, tmp;
    auto *arr = new std::pair<int, int>[n];
    int *counts = new int[10];
    for (int i = 0; i < n; ++i) {
        std::cin >> carrying;
        std::pair<int, int> drone;
        drone.first = carrying;
        drone.second = i;
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
        for (int j = 0; j < 10; ++j) {
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
    delete[] arr;
    delete[] counts;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, dest, x;
    std::cin >> n;
    std::vector<int> village;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        village.push_back(x);
    }
    std::cin >> m;
    auto *shelter = new std::pair<int, int>[m];
    radixSort(shelter, m);
    for (int i = 0; i < n; ++i) {
        dest = binarySearch(shelter, m, village[i], village, i);
        std::cout << dest + 1 << ' ';
    }
    delete[] shelter;
}