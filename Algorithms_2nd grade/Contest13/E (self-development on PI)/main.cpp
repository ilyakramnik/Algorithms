#include <iostream>
#include <string>
#include <vector>

int levenshteinDistance(const std::string &s1, const std::string &s2, int d) {
    int n = static_cast<int>(s1.size());
    int m = static_cast<int>(s2.size());
    std::vector<std::vector<int>> matrix(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 0; i < n + 1; ++i) {
        matrix[i][0] = i;
    }
    for (int j = 0; j < m + 1; ++j) {
        matrix[0][j] = j;
    }

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1];
            } else {
                matrix[i][j] =
                    std::min(matrix[i - 1][j], std::min(matrix[i][j - 1], matrix[i - 1][j - 1])) +
                    1;
            }
            if (i == j && i >= d) {
                if (matrix[i - 1][j] > d && matrix[i][j - 1] > d && matrix[i - 1][j - 1] > d) {
                    return d + 1;
                }
            }
        }
    }
    return matrix[n][m];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, d, q, k;
    std::cin >> n;
    std::vector<std::string> strings(n);
    std::string query;
    for (int i = 0; i < n; ++i) {
        std::cin >> strings[i];
    }
    std::cin >> d >> q;
    for (int i = 0; i < q; ++i) {
        std::cin >> query;
        k = 0;
        for (int j = 0; j < n; ++j) {
            if (levenshteinDistance(query, strings[j], d) <= d) {
                ++k;
            }
        }
        std::cout << k << '\n';
    }
}
