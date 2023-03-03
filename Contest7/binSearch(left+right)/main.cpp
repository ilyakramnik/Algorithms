#include <iostream>

int binarySearch(const int arr[], int size, int key, int flag) {
    int l = -1, r = size, m;
    while (l < r - 1) {
        m = l + (r - l) / 2;
        if (!flag) {
            if (arr[m] < key) {
                l = m;
            } else {
                r = m;
            }
        } else {
            if (arr[m] <= key) {
                l = m;
            } else {
                r = m;
            }
        }
    }
    if (flag && l >= 0 && l < size && arr[l] == key) {
        return l + 1;
    } else if (!flag && r >= 0 && r < size && arr[r] == key) {
        return r + 1;
    }
    return 0;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, x, output1;
    std::cin >> n >> m;
    int *arr1 = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        arr1[i] = x;
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> x;
        output1 = binarySearch(arr1, n, x, 0);  // left boundary
        std::cout << output1;
        if (output1 != 0) {
            std::cout << ' ' << binarySearch(arr1, n, x, 1) << '\n';  // right boundary
        } else {
            std::cout << '\n';
        }
    }
    delete[] arr1;
}
