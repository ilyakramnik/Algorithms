#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int64_t n, m, q;
    std::cin >> n >> m >> q;
    int64_t **arr = new int64_t *[n], **arr_new = new int64_t *[n];
    for (int64_t i = 0; i < n; ++i) {
        arr[i] = new int64_t[m];
        arr_new[i] = new int64_t[m];
    }
    for (int64_t i = 0; i < n; ++i) {
        for (int64_t j = 0; j < m; ++j) {
            std::cin >> arr[i][j];
        }
    }
    for (int64_t i = 0; i < n; ++i) {
        for (int64_t j = 0; j < m; ++j) {
            if (i == 0 && j == 0) {
                arr_new[i][j] = arr[i][j];
            } else if (i == 0) {
                arr_new[i][j] = arr_new[i][j - 1] + arr[i][j];
            } else if (j == 0) {
                arr_new[i][j] = arr_new[i - 1][j] + arr[i][j];
            } else {
                arr_new[i][j] =
                    arr_new[i - 1][j] + arr_new[i][j - 1] - arr_new[i - 1][j - 1] + arr[i][j];
            }
        }
    }
    int64_t x1, y1, x2, y2, ans, part1, part2, part3;
    for (int64_t i = 0; i < q; ++i) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        part1 = 0, part2 = 0, part3 = 0;
        if (x1 - 2 >= 0) {
            part1 = arr_new[x1 - 2][y2 - 1];
        }
        if (y1 - 2 >= 0) {
            part2 = arr_new[x2 - 1][y1 - 2];
        }
        if (x1 - 2 >= 0 && y1 - 2 >= 0) {
            part3 = arr_new[x1 - 2][y1 - 2];
        }
        ans = arr_new[x2 - 1][y2 - 1] - part1 - part2 + part3;
        std::cout << ans << '\n';
    }

    for (int64_t i = 0; i < n; ++i) {
        delete[] arr[i];
        delete[] arr_new[i];
    }
    delete[] arr;
    delete[] arr_new;
}