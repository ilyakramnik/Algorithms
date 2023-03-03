#include <iostream>
#include <vector>

int binarySearchLeft(std::vector<int> &arr, int size, int key) {
    int l = -1, r = size, m;
    while (l < r - 1) {
        m = l + (r - l) / 2;
        if (arr[m] < key) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}

int binarySearchRight(std::vector<int> &arr, int size, int key) {
    int l = -1, r = size, m;
    while (l < r - 1) {
        m = l + (r - l) / 2;
        if (arr[m] <= key) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

void heapify(std::vector<int> &heap, int root, int size) {
    int curr_max = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;
    if (l < size && heap[l] > heap[curr_max]) {
        curr_max = l;
    }
    if (r < size && heap[r] > heap[curr_max]) {
        curr_max = r;
    }
    if (curr_max != root) {
        std::swap(heap[root], heap[curr_max]);
        heapify(heap, curr_max, size);
    }
}

void heapSort(std::vector<int> &heap, int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(heap, i, n);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(heap[0], heap[i]);
        heapify(heap, 0, i);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, l, r, num, k, started, ended, m;
    std::cin >> n >> m;
    std::vector<int> arr_left, arr_right;
    for (int i = 0; i < n; ++i) {
        std::cin >> l >> r;
        arr_left.push_back(l);
        arr_right.push_back(r);
    }
    heapSort(arr_left, n);
    heapSort(arr_right, n);

    for (int i = 0; i < m; ++i) {
        std::cin >> num;
        started = binarySearchRight(arr_left, n, num);
        ended = binarySearchLeft(arr_right, n, num);
        k = started - ended + 1;
        std::cout << k << ' ';
    }
}