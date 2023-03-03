#include <iostream>

int isRightNumOfWires(const int arr[], int wire_len, int num_of_lines, int size) {
    int k = 0;
    for (int i = 0; i < size; ++i) {
        k += arr[i] / wire_len;
    }
    if (k >= num_of_lines) {
        return 1;
    }
    return 0;
}

int binarySearch(int size1, const int arr[], int size2, int num_of_lines) {
    int l = -1, r = size1, m;
    while (l < r - 1) {
        m = l + (r - l) / 2;
        if (isRightNumOfWires(arr, m + 1, num_of_lines, size2)) {
            l = m;
        } else {
            r = m;
        }
    }
    if (l >= 0 && l < size1 && isRightNumOfWires(arr, l + 1, num_of_lines, size2)) {
        return l + 1;
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k, x, max_num = 0;
    std::cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        arr[i] = x;
        max_num = std::max(max_num, x);
    }

    std::cout << binarySearch(max_num, arr, n, k);
    delete[] arr;
}
