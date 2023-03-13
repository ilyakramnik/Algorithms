#include <iostream>
#include <string>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    double x1, x2;
    int left_border = 0, right_border = 0, com = 0, del1 = 0, del2 = 0;
    int num = 0;
    std::string s, s1, s2;
    std::cin >> s1;
    std::cin >> s2;
    s = s1 + s2;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            continue;
        }
        if (s[i] == '[') {
            left_border = 1;
        } else if (s[i] == ']') {
            right_border = 1;
        }
        if (s[i] == ')' || s[i] == ']') {
            break;
        } else if (s[i] == ',') {
            com = 1;
        } else {
            if (com == 0) {
                if (s[i] == '/') {
                    del1 = 1;
                } else {
                    if (s[i] >= '0' && s[i] <= '9') {
                        num = num * 10 + (s[i] - '0');
                        if (s[i - 1] == '-') {
                            num *= -1;
                        }
                    }
                    if (s[i + 1] < '0' || s[i + 1] > '9') {
                        if (del1 == 0) {
                            x1 = num;
                        } else {
                            x1 /= num;
                        }
                        num = 0;
                    }
                }
            } else {
                if (s[i] == '/') {
                    del2 = 1;
                } else {
                    if (s[i] >= '0' && s[i] <= '9') {
                        num = num * 10 + (s[i] - '0');
                        if (s[i - 1] == '-') {
                            num *= -1;
                        }
                    }
                    if (s[i + 1] < '0' || s[i + 1] > '9') {
                        if (del2 == 0) {
                            x2 = num;
                        } else {
                            x2 /= num;
                        }
                        num = 0;
                    }
                }
            }
        }
    }
    int k = 0;
    if (x1 != floor(x1) && x2 != floor(x2)) {
        for (int i = floor(x1) + 1; i <= floor(x2); ++i) {
            ++k;
        }
    }
    if (x1 == floor(x1) && x2 != floor(x2)) {
        if (left_border == 1) {
            ++k;
        }
        for (int i = x1 + 1; i <= floor(x2); ++i) {
            ++k;
        }
    } else if (x1 != floor(x1) && x2 == floor(x2)) {
        if (right_border == 1) {
            ++k;
        }
        for (int i = floor(x1) + 1; i < x2; ++i) {
            ++k;
        }
    } else if (x1 == floor(x1) && x2 == floor(x2)) {
        if (left_border == 1) {
            ++k;
        }
        if (right_border == 1) {
            ++k;
        }
        for (int i = x1 + 1; i < x2; ++i) {
            ++k;
        }
    }
    std::cout << k;
}
