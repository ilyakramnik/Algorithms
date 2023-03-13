#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, x, new_m, new_n;
    std::cin >> n >> m;
    new_m = m, new_n = n;
    std::vector<int> weights, costs, weights_new, costs_new;
    std::vector<double> avg;
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        weights.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        costs.push_back(x);
    }
    avg.reserve(n);
    for (int i = 0; i < n; ++i) {
        avg.push_back(static_cast<double>(costs[i]) / weights[i]);
    }

    while (true) {
        int curr_weight = 0, ind = -1;
        double curr_avg = 0;
        for (int i = 0; i < new_n; ++i) {
            if (avg[i] > curr_avg && weights[i] <= new_m) {
                curr_avg = avg[i];
                ind = i;
                curr_weight = weights[i];
            } else if (avg[i] == curr_avg && weights[i] <= new_m) {
                if (weights[i] > curr_weight) {
                    curr_avg = avg[i];
                    ind = i;
                    curr_weight = weights[i];
                }
            }
        }
        if (ind == -1) {
            break;
        }
        weights_new.push_back(weights[ind]);
        costs_new.push_back(costs[ind]);
        new_m -= weights[ind];
        weights.erase(weights.begin() + ind);
        costs.erase(costs.begin() + ind);
        avg.erase(avg.begin() + ind);
        --new_n;
    }

    int sum = 0;
    for (auto &s : costs_new) {
        sum += s;
    }
    std::cout << sum << '\n' << m - new_m << '\n' << weights_new.size() << '\n';
    for (int i : weights_new) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    for (int i : costs_new) {
        std::cout << i << ' ';
    }
}
