#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, min_pos = 10000000, min_ind = -1;
    int pos[3] = {0};
    std::cin >> n;
    char** arr = new char*[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new char[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 'X') {
                ++pos[(i + j) % 3];
            }
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (pos[i] < min_pos) {
            min_pos = pos[i];
            min_ind = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 'X' && (i + j) % 3 == min_ind) {
                arr[i][j] = '0';
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << arr[i][j];
        }
        std::cout << '\n';
    }
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}