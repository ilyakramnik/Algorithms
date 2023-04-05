// идея взята из презентации к лекции
#include <iostream>
#include <string>
#include <vector>

std::vector<int> kmp(const std::string& t, const std::string& s) {
    std::vector<int> br(s.size() + 1, 0);
    std::vector<int> matches;
    int j = 0;
    for (int i = 1; i < static_cast<int>(s.size()); ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = br[j];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        br[i + 1] = j;
    }
    j = 0;
    for (int i = 0; i < static_cast<int>(t.size()); ++i) {
        while (j > 0 && t[i] != s[j]) {
            j = br[j];
        }
        if (t[i] == s[j]) {
            ++j;
        }
        if (j == static_cast<int>(s.size())) {
            matches.push_back(i - j + 1);
            j = br[j];
        }
    }
    return matches;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::vector<int> res;
    std::string s, t;
    std::cin >> s >> t;

    res = kmp(t, s);
    std::cout << res.size() << '\n';
    if (!res.empty()) {
        for (int x : res) {
            std::cout << x << '\n';
        }
    }
}
