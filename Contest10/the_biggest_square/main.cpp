#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    int **arr = new int *[n], **arr_new = new int *[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
        arr_new[i] = new int[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> arr[i][j];
        }
    }

    int max_side = 1, first_min, second_min;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 || j == 0 || arr[i][j] == 0) {
                arr_new[i][j] = arr[i][j];
            } else {
                first_min = std::min(arr_new[i][j - 1], arr_new[i - 1][j]);
                second_min = std::min(arr_new[i - 1][j - 1], first_min);
                arr_new[i][j] = second_min + arr[i][j];
            }
        }
    }
    /*for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout<<arr_new[i][j]<<' ';
        }
        std::cout<<'\n';
    }*/

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr_new[i][j] > max_side) {
                max_side = arr_new[i][j];
            }
        }
    }
    std::cout << max_side;

    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
        delete[] arr_new[i];
    }
    delete[] arr;
    delete[] arr_new;
}