#include <iostream>
#include <vector>

void karatsuba(const std::string& first, const std::string& second) {
    std::vector<int> num1;
    std::vector<int> num2;
    std::vector<int> res;
    num1.reserve(first.size());
    num2.reserve(second.size());
    res.reserve(first.size() + second.size());
    for (int i = 0; i < (first.size() + second.size()); ++i) {
        if (i < first.size()) {
            num1.push_back(first[i] - '0');
        }
        if (i < second.size()) {
            num2.push_back(second[i] - '0');
        }
        res.push_back(0);
    }

    if (first == "0" || second == "0") {
        std::cout << "0";
    } else {
        int lvl_main = 0;
        for (int i = first.size() - 1; i >= 0; --i) {
            int ost = 0, lvl = 0;
            for (int j = second.size() - 1; j >= 0; --j) {
                int temp = ost + num1[i] * num2[j];
                res[lvl_main + lvl] += temp;
                ost = res[lvl_main + lvl] / 10;
                res[lvl_main + lvl] %= 10;
                ++lvl;
            }
            res[lvl_main + lvl] += ost;
            ++lvl_main;
        }
        int start = res[res.size() - 1] == 0 ? res.size() - 2 : res.size() - 1;
        for (int i = start; i >= 0; --i) {
            std::cout << res[i];
        }
    }
}

int main() {
    std::string s1;
    std::string s2;
    std::cin >> s1 >> s2;
    karatsuba(s1, s2);
    return 0;
}
