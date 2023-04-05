#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s;
    std::cin >> s;

    int l = 0, r = 0;
    std::vector<int> z(s.size());
    for (auto i = 1; i < s.size(); ++i) {
        z[i] = std::max(0, std::min(r - i + 1, z[i - l]));
        while (i + z[i] < s.size() && s[i + z[i]] == s[z[i]]) {
            ++z[i];
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    for (int i = 1; i < z.size(); ++i) {
        if (i + z[i] == z.size()) {
            std::cout << i;
            return 0;
        }
    }
    std::cout << s.size();
}
