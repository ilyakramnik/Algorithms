// идея взята из презентации к лекции
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string out, substr;
    std::unordered_map<int, std::string> encodes;
    int k, code = 128, old, num;
    char symb;

    for (int i = 32; i <= 126; ++i) {
        std::string s_new(1, char(i));
        encodes[i] = s_new;
    }

    std::cin >> k;
    std::cin >> old;
    symb = encodes[old][0];
    out += symb;
    for (int i = 1; i < k; ++i) {
        std::cin >> num;
        if (!encodes.count(num)) {
            substr = encodes[old] + symb;
        } else {
            substr = encodes[num];
        }
        out += substr;
        symb = substr[0];
        encodes[code++] = encodes[old] + symb;
        old = num;
    }
    std::cout << out;
}