#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int count[4] = {0};
    int n, left = 0, right = 0, res = 20000000;
    std::string s;
    std::cin >> n;
    std::cin >> s;
    while (right < n) {
        ++count[s[right++] - 'a'];
        while (left < right && count[0] * count[1] * count[2] * count[3] > 0) {
            res = std::min(res, count[0] + count[1] + count[2] + count[3]);
            --count[s[left++] - 'a'];
        }
    }
    if (res == 20000000) {
        std::cout << -1;
    } else {
        std::cout << res;
    }
}
