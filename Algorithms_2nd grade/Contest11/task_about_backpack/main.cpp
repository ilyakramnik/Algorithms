// идея взята из презентации к лекии
#include <iostream>
#include <vector>

void way(int **matrix, std::vector<int> &ans, int *stones, int i, int j) {
    if (matrix[i][j] == 0) {
        return;
    }
    if (matrix[i][j] != matrix[i - 1][j]) {
        way(matrix, ans, stones, i - 1, j - stones[i]);
        ans.push_back(stones[i]);
    } else {
        way(matrix, ans, stones, i - 1, j);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, w;
    std::cin >> n >> w;
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        if (i == 0) {
            arr[i] = 0;
        } else {
            std::cin >> arr[i];
        }
    }
    int **matrix = new int *[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        matrix[i] = new int[w + 1];
    }

    for (int i = 0; i < n + 1; ++i) {
        for (int j = 0; j < w + 1; ++j) {
            if (i == 0 || j == 0) {
                matrix[i][j] = 0;
            } else {
                if (j - arr[i] >= 0) {
                    matrix[i][j] = std::max(matrix[i - 1][j], matrix[i - 1][j - arr[i]] + arr[i]);
                } else {
                    matrix[i][j] = matrix[i - 1][j];
                }
            }
        }
    }
    std::cout << matrix[n][w] << '\n';

    std::vector<int> ans;
    way(matrix, ans, arr, n, w);
    std::cout << ans.size() << '\n';
    for (auto &x : ans) {
        std::cout << x << " ";
    }

    delete[] arr;
    for (int i = 0; i < n + 1; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}