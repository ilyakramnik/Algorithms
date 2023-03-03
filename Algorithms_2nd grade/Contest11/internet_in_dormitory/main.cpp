#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    int costs[n];
    int bro_costs_left[n], bro_costs_right[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> costs[i];
    }
    bro_costs_left[0] = 2000000000;
    for (int i = 1; i < n; ++i) {
        std::cin >> bro_costs_left[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        bro_costs_right[i] = bro_costs_left[i + 1];
    }
    bro_costs_right[n - 1] = 0;

    for (int i = 1; i < n; ++i) {
        bro_costs_left[i] += std::min(costs[i - 1], bro_costs_left[i - 1]);
        bro_costs_right[i] +=
            std::min(costs[i - 1], std::min(bro_costs_left[i - 1], bro_costs_right[i - 1]));
        costs[i] += std::min(costs[i - 1], std::min(bro_costs_left[i - 1], bro_costs_right[i - 1]));
    }
    std::vector<int> res;
    res.push_back(costs[n - 1]);
    res.push_back(bro_costs_left[n - 1]);
    res.push_back(bro_costs_right[n - 1]);
    std::sort(res.begin(), res.end());
    std::cout << res[1];
}