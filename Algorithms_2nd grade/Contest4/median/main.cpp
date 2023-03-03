#include <iostream>
#include <iomanip>

float findMedian(const int arr1[], const int arr2[], int len) {
    if (len == 1) {
        return static_cast<float>(arr1[0] + arr2[0]) / 2;
    } else if (len == 2) {
        return static_cast<float>((std::max(arr1[0], arr2[0]) + std::min(arr1[1], arr2[1]))) / 2;
    }
    float median1, median2;
    int middle = len / 2;
    if (len % 2 != 0) {
        median1 = static_cast<float>(arr1[middle]);
        median2 = static_cast<float>(arr2[middle]);
    } else {
        median1 = static_cast<float>((arr1[middle - 1] + arr1[middle])) / 2;
        median2 = static_cast<float>((arr2[middle - 1] + arr2[middle])) / 2;
    }
    if (median1 == median2) {
        return median1;
    } else if (median1 < median2) {
        if (len % 2 == 0) {
            return findMedian(arr1 + len / 2 - 1, arr2, len - len / 2 + 1);
        } else {
            return findMedian(arr1 + len / 2, arr2, len - len / 2);
        }
    } else {
        if (len % 2 == 0) {
            return findMedian(arr2 + len / 2 - 1, arr1, len - len / 2 + 1);
        } else {
            return findMedian(arr2 + len / 2, arr1, len - len / 2);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, num;
    std::cin >> n >> m;
    int all_arrs[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> num;
            all_arrs[i][j] = num;
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::cout << std::fixed << std::setprecision(5)
                      << findMedian(all_arrs[i], all_arrs[j], m) << '\n';
        }
    }
}
