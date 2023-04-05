// идея взята из презентации к лекции
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    std::cin >> s;

    int k;
    std::vector<int> p(s.size());
    for (int i = 1; i < s.size(); ++i) {
        k = p[i - 1];
        while (k > 0 && s[i] != s[k]) {
            k = p[k - 1];
        }
        if (s[i] == s[k]) {
            ++k;
        }
        p[i] = k;
    }
    for (int i : p) {
        std::cout << i << ' ';
    }
}
