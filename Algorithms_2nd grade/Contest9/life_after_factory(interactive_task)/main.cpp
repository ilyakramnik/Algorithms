#include <iostream>
#include <cmath>

int binarySearch(int *arr, int size, int key, int flag) {  // find pos
    int l = -1, r = size, m;
    while (l < r - 1) {
        m = l + (r - l) / 2;
        if (arr[m] <= key) {
            l = m;
        } else {
            r = m;
        }
    }
    if (flag) {
        if (l >= 0 && l < size && arr[l] == key) {
            return l;
        }
        return l + 1;
    } else {
        if (l >= 0 && l < size && arr[l] == key) {
            return l + 1;
        }
        return l + 1;
    }
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

void radixSort(int *res, int n) {
    int max_digit = 1, d, count, tmp;
    int *arr = new int[n];
    int *counts = new int[10];
    for (int i = 0; i < n; ++i) {
        arr[i] = res[i];
        max_digit = std::max(max_digit, numOfDigits(res[i]));
    }
    for (int i = 1; i <= max_digit; ++i) {
        for (int j = 0; j < 10; ++j) {
            counts[j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            d = digit(arr[j], i);
            ++counts[d];
        }
        count = 0;
        for (int j = 0; j < 10; ++j) {
            tmp = counts[j];
            counts[j] = count;
            count += tmp;
        }
        for (int j = 0; j < n; ++j) {
            d = digit(arr[j], i);
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
    int n, l, r, num, k, started = 0, ended = 0;
    char symb = ' ';
    std::cin >> n;
    int *arr_left = new int[n], *arr_right = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> l >> r;
        arr_left[i] = l;
        arr_right[i] = r;
    }
    radixSort(arr_left, n);
    radixSort(arr_right, n);

    std::cin >> symb >> num;
    while (symb != '!') {
        started = binarySearch(arr_left, n, num, 0);
        ended = binarySearch(arr_right, n, num, 1);
        k = started - ended;
        std::cout << "! " << k << '\n';
        std::cout.flush();
        std::cin >> symb;
        if (symb == '!') {
            break;
        }
        std::cin >> num;
    }
    delete[] arr_left;
    delete[] arr_right;
}