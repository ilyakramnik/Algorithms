#include <iostream>
#include <string>

//8
//BCCBBCBC
//8
//BBCCCBBC
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, ind = -1, new_ind = -1;
    char c = 'Z';
    std::cin >> n;
    std::string s, new_s;
    std::cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (new_ind != -1) {
            if (s[i] == s[ind + new_s.size()]) {
                new_s.push_back(s[i]); // не учли случай когда две строки равны, но нужно брать последнюю
                if (i + 1 == s.size()) {
                    c = s[new_ind];
                    ind = new_ind;
                    new_ind = -1;
                }
            } else if (s[i] > s[ind + new_s.size()]) {
                new_ind = -1;
                new_s = "";
            } else {
                c = s[i - new_s.size()];
                ind = new_ind;
                new_ind = -1;
                new_s = "";
            }
        }
        if (s[i] < c) {
            c = s[i];
            ind = i;
        } else if (s[i] == c) {
            if (i + 1 == s.size()) {
                ind = i;
            }
            if (new_ind == -1) {
                new_ind = i;
                new_s = s[i];
            }
        }
    }
    for (int i = ind; i < s.size(); ++i) {
        std::cout << s[i];
    }
}
