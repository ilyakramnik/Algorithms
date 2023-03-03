#include <iostream>
#include <algorithm>
#include <vector>

struct Interval {
    double left, right, weight;
};

bool compare(Interval x1, Interval x2) {
    if (x1.right == x2.right) {
        return x1.left < x2.left;
    }
    return x1.right < x2.right;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<Interval> intervals(n);
    for (auto &interval : intervals) {
        std::cin >> interval.left >> interval.right >> interval.weight;
    }
    std::sort(intervals.begin(), intervals.end(), compare);
    auto *arr = new double[n];
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            arr[i] = intervals[i].weight;
        } else {
            arr[i] = arr[i - 1];
            for (int j = i - 1; j >= 0; --j) {
                if (intervals[j].right <= intervals[i].left) {
                    arr[i] = std::max(arr[i], intervals[i].weight + arr[j]);
                    break;
                }
            }
            arr[i] = std::max(arr[i], intervals[i].weight);
        }
    }
    std::cout.precision(4);
    std::cout << std::fixed << arr[n - 1];
    delete[] arr;
}