// идея взята из презентации с лекции
#include <iostream>
#include <vector>

uint64_t lazyRecursion(std::vector<std::vector<int64_t>> *matrix, int64_t i, int64_t j, int64_t n,
                       int64_t m) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return 0;
    }
    if ((*matrix)[i][j] != -1) {
        return (*matrix)[i][j];
    }
    int64_t res = 0;
    res += lazyRecursion(matrix, i - 2, j - 1, n, m);
    res += lazyRecursion(matrix, i - 1, j - 2, n, m);
    res += lazyRecursion(matrix, i + 1, j - 2, n, m);
    res += lazyRecursion(matrix, i - 2, j + 1, n, m);
    (*matrix)[i][j] = res;
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int64_t n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int64_t>> matrix(n, std::vector<int64_t>(m));

    for (int64_t i = 0; i < n; ++i) {
        for (int64_t j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = -1;
            }
        }
    }
    std::cout << lazyRecursion(&matrix, n - 1, m - 1, n, m);
}
