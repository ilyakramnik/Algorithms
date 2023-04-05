#include <iostream>
#include <string>
#include <queue>
#include <map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s, code, coded_str, decode_letter;
    std::pair<char, std::string> pair;
    int k, l;
    std::cin >> k >> l;

    std::map<char, std::string> tree;
    for (int i = 0; i < k; ++i) {
        getline(std::cin, s);
        if (s.size() <= 2) {
            --i;
            continue;
        }
        code = s.substr(3, s.size());
        pair.first = s[0];
        pair.second = code;
        tree.insert(pair);
    }

    std::cin >> coded_str;

    for (char i : coded_str) {
        decode_letter += i;
        auto it = tree.begin();
        while (it != tree.end()) {
            if ((*it).second == decode_letter) {
                std::cout << (*it).first;
                decode_letter = "";
                break;
            }
            ++it;
        }
    }
}
