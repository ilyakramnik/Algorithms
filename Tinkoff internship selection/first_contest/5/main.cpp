#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

bool comp(std::pair<int, int> &first, std::pair<int, int> &second) {
    return first.first < second.first;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::unordered_map<int, int> prefix_sum_indices;
    std::vector<std::pair<int, int>> intervals;
    prefix_sum_indices[0] = -1;
    int prefix_sum = 0;

    for (int i = 0; i < n; i++) {
        prefix_sum += a[i];
        if (prefix_sum_indices.count(prefix_sum) > 0) {
            int start = prefix_sum_indices[prefix_sum] + 1;
            int end = i;
            intervals.emplace_back(start, end);
        }
        prefix_sum_indices[prefix_sum] = i;
    }
    std::sort(intervals.begin(), intervals.end(), comp);

    int res = 0, prev_first = -1, prev_second = -1;
    for (int i = 0; i < static_cast<int>(intervals.size()); ++i) {
        if (i == 0) {
            res += intervals[i].first + n - intervals[i].second;
            prev_first = intervals[i].first;
            prev_second = intervals[i].second;
        } else {
            res += n - intervals[i].second + prev_second - prev_first;
            if (intervals[i].first == prev_second) {
                --res;
            }
            if (intervals[i].second < prev_second) {
                res -= (prev_second - intervals[i].first);
            }
            prev_first = intervals[i].first;
            prev_second = intervals[i].second;
        }
    }
    std::cout << res;
}
