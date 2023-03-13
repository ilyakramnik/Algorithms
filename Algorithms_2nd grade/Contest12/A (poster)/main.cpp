#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m, step;
    uint64_t res = 0;
    std::cin >> n >> m;
    std::vector<std::vector<char>> matrix(n + 1, std::vector<char>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<std::vector<int>> ups(n + 1, std::vector<int>(m + 1, 0));
    std::vector<std::vector<int>> downs(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i > 1) {
                matrix[i][j] == matrix[i - 1][j] ? ups[i][j] = ups[i - 1][j] + 1 : 0;
            }
        }
    }

    for (int i = n; i > 0; --i) {
        for (int j = m; j > 0; --j) {
            if (i < n) {
                matrix[i][j] == matrix[i + 1][j] ? downs[i][j] = downs[i + 1][j] + 1 : 0;
            }
        }
    }

    std::vector<int> left(m + 1, 0);
    std::vector<int> right(m + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            step = j;
            while (step <= m) {
                if (matrix[i][j] != matrix[i][step]) {
                    break;
                }
                ++step;
            }
            --step;
            for (int t = j; t <= step; ++t) {
                t == j ? left[t] = t
                       : left[t] = std::max(left[t - 1], t - std::min(ups[i][t], downs[i][t]));
            }
            j = step;
        }
        for (int j = m; j >= 1; --j) {
            step = j;
            while (step > 0) {
                if (matrix[i][j] != matrix[i][step]) {
                    break;
                }
                --step;
            }
            ++step;
            for (int t = j; t >= step; --t) {
                t == j ? right[t] = t
                       : right[t] = std::min(right[t + 1], t + std::min(ups[i][t], downs[i][t]));
            }
            j = step;
        }
        for (int j = 1; j <= m; ++j) {
            res += std::min(j - left[j] + 1, right[j] - j + 1);
        }
    }
    std::cout << res << '\n';
}
