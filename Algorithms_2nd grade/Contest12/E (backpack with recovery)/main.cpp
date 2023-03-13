#include <iostream>
#include <vector>
#include <algorithm>

void recovery(const std::vector<int> &weights, std::vector<int> *res,
              const std::vector<std::vector<int>> &matrix, int i, int w) {
    if (matrix[i][w] == 0 || i * w == 0) {
        return;
    }
    if (matrix[i][w] == matrix[i - 1][w]) {
        recovery(weights, res, matrix, i - 1, w);
    } else {
        recovery(weights, res, matrix, i - 1, w - weights[i]);
        (*res).push_back(i);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, x;
    std::cin >> n >> m;
    std::vector<int> weights, costs, res;
    std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(m + 1, 0));
    weights.push_back(0);
    costs.push_back(0);
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        weights.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        costs.push_back(x);
    }

    for (int i = 0; i < n + 1; ++i) {
        for (int w = 0; w < m + 1; ++w) {
            if (i * w != 0) {
                if (weights[i] > w) {
                    matrix[i][w] = matrix[i - 1][w];
                } else {
                    matrix[i][w] =
                        std::max(matrix[i - 1][w], matrix[i - 1][w - weights[i]] + costs[i]);
                }
            }
        }
    }
    recovery(weights, &res, matrix, n, m);
    int sum = 0;
    for (int re : res) {
        sum += weights[re];
    }
    std::cout << matrix[n][m] << '\n' << sum << '\n' << res.size() << '\n';
    for (auto &i : res) {
        std::cout << weights[i] << ' ';
    }
    std::cout << '\n';
    for (auto &i : res) {
        std::cout << costs[i] << ' ';
    }
}
