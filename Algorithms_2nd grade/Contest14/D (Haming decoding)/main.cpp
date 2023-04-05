#include <iostream>
#include <vector>
#include <string>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    int k, degree, x, sum;
    std::cin >> s;

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

    bool error = false;
    std::string new_bits;
    for (int i = 0; i < k; ++i) {
        sum = 0;
        for (int j = 0; j < s.size(); ++j) {
            sum += matrix[i][j] * (s[j] - '0');
        }
        if (sum % 2 == 1) {
            error = true;
        }
        new_bits += '0' + (sum % 2);
    }

    std::string final_str;
    if (error) {
        int pos = 0;
        for (auto i = 0; i < new_bits.size(); ++i) {
            pos += (new_bits[i] - '0') * static_cast<int>(std::pow(2, i));
        }
        if (pos > 0 && pos < s.size()) {
            s[pos - 1] == '1' ? s[pos - 1] = '0' : s[pos - 1] = '1';
        }
    }

    degree = 0;
    for (auto i = 0; i < s.size(); ++i) {
        if (std::pow(2, degree) == i + 1) {
            ++degree;
        } else {
            final_str += s[i];
        }
    }

    std::cout << final_str;
}
