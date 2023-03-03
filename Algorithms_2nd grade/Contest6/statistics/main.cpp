#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, num;
    std::vector<int> arr;
    char smb;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> smb;
        std::cin >> num;
        if (smb == '+') {
            arr.push_back(num);
            std::sort(arr.begin(), arr.end());
        } else if (smb == '?') {
            std::cout << arr[num - 1] << '\n';
        } else if (smb == '-') {
            arr.erase(std::remove(arr.begin(), arr.end(), num), arr.end());
        }
    }
}
