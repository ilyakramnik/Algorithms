// идея взята с сайта https://habr.com/ru/company/otus/blog/460087/
#include <iostream>
#include <vector>

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x;
    std::vector<int> heap;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        heap.push_back(x);
    }
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(heap, i, n);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(heap[0], heap[i]);
        heapify(heap, 0, i);
    }
    for (auto &res : heap) {
        std::cout << res << ' ';
    }
}