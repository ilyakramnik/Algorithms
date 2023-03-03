// идея реализации взята с лекции
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s1, s2;
    std::cin >> s1 >> s2;
    int **matrix = new int *[s1.size() + 1];
    for (int i = 0; i < s1.size() + 1; ++i) {
        matrix[i] = new int[s2.size() + 1];
    }

    for (int i = 0; i < s1.size() + 1; ++i) {
        for (int j = 0; j < s2.size() + 1; ++j) {
            if (i == 0 || j == 0) {
                matrix[i][j] = 0;
            } else if (s1[i - 1] == s2[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else if (s1[i - 1] != s2[j - 1]) {
                matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }
    std::cout << matrix[s1.size()][s2.size()];

    for (int i = 0; i < s1.size() + 1; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}