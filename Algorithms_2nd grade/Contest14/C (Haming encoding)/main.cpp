#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    int k, degree = 0, x, sum;
    std::cin >> s;
    for (auto i = 0; i < s.size(); ++i) {
        if (std::pow(2, degree) == i + 1) {
            ++degree;
            s.insert(i, 1, '0');
        }
    }
    k = static_cast<int>(std::floor(std::log2(s.size()))) + 1;

    std::vector<std::vector<int>> matrix(k, std::vector<int>(s.size(), 0));
    for (auto i = 0; i < s.size(); ++i) {
        std::string new_str;
        x = i + 1;
        while (x > 0) {
            new_str.insert(0, 1, '0' + (x % 2));
            x /= 2;
        }
        new_str.insert(0, k - new_str.size(), '0');
        for (int j = 0; j < k; ++j) {
            matrix[j][i] = new_str[k - j - 1] - '0';
        }
    }

    std::vector<char> new_bits;
    for (int i = 0; i < k; ++i) {
        sum = 0;
        for (int j = 0; j < s.size(); ++j) {
            sum += matrix[i][j] * (s[j] - '0');
        }
        new_bits.push_back('0' + (sum % 2));
    }
    degree = 0;
    int pos = 0;
    for (auto i = 0; i < s.size(); ++i) {
        if (std::pow(2, degree) == i + 1) {
            s[i] = new_bits[pos++];
            ++degree;
        }
    }
    std::cout << s;
}
