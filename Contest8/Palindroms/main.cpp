#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, nech_index = -1, single_index = -1;
    int arr[26] = {0};
    std::string s, res;
    std::cin >> n;
    std::cin >> s;
    for (int i = 0; i < n; ++i) {
        ++arr[s[i] - 'A'];
    }
    for (int i = 25; i >= 0; --i) {
        if (arr[i] % 2 != 0) {
            nech_index = i;
        } else if (arr[i] == 1) {
            single_index = i;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (arr[i] != 0 && arr[i] % 2 == 0) {
            for (int j = 0; j < arr[i] / 2; ++j) {
                res += static_cast<char>(i + 'A');
            }
        } else if (arr[i] % 2 != 0) {
            for (int j = 0; j < arr[i] / 2; ++j) {
                res += static_cast<char>(i + 'A');
            }
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (i == nech_index || i == single_index) {
            res += static_cast<char>(i + 'A');
            break;
        }
    }
    for (int i = 25; i >= 0; --i) {
        if (arr[i] != 0 && arr[i] % 2 == 0) {
            for (int j = 0; j < arr[i] / 2; ++j) {
                res += static_cast<char>(i + 'A');
            }
        } else if (arr[i] % 2 != 0) {
            for (int j = 0; j < arr[i] / 2; ++j) {
                res += static_cast<char>(i + 'A');
            }
        }
    }
    std::cout << res;
}