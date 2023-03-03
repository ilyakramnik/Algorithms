#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, l, r, curr;
    std::vector<int> unique_nums;
    std::cin >> m >> n;
    if (n > 0) {
        int *arr = new int[m + 1];
        for (int i = 0; i <= m; ++i) {
            arr[i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            std::cin >> l >> r;
            for (int j = l; j <= r; ++j) {
                if (arr[j] != 0) {
                    curr = arr[j];
                    for (int t = 1; t <= m; ++t) {
                        if (arr[t] == curr) {
                            arr[t] = 0;
                        }
                    }
                }
                arr[j] = i;
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (arr[i] != 0 && std::count(unique_nums.begin(), unique_nums.end(), arr[i]) == 0) {
                unique_nums.push_back(arr[i]);
            }
        }
    }
    std::cout << unique_nums.size();
}