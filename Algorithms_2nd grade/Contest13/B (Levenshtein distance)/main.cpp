// решение основано на презентации к лекции
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, m;
    std::string s1, s2;
    std::cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
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
                matrix[i][j] = std::min(matrix[i - 1][j] + 1,
                                        std::min(matrix[i][j - 1] + 1, matrix[i - 1][j - 1] + 1));
            }
        }
    }
    std::cout << matrix[n][m];
}
