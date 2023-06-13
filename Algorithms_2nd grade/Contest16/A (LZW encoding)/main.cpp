// идея взята из презентации к лекции
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> out;
    std::string s, substr;
    std::unordered_map<std::string, int> encodes;
    std::getline(std::cin, s);
    char symb;
    int code = 128;

    for (int i = 32; i <= 126; ++i) {
        std::string s_new(1, char(i));
        encodes[s_new] = i;
    }

    substr = s[0];
    for (int j = 1; j < s.size(); ++j) {
        symb = s[j];
        if (encodes.count(substr + symb)) {
            substr += symb;
        } else {
            out.push_back(encodes[substr]);
            encodes[substr + symb] = code++;
            substr = symb;
        }
    }
    out.push_back(encodes[substr]);
    std::cout << out.size() << '\n';
    for (auto x : out) {
        std::cout << x << ' ';
    }
}
