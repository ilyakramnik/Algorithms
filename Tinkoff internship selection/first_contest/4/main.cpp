#include <iostream>
#include <unordered_map>
#include <set>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x, num_of_one, l = -1, flag;
    std::cin >> n;

    std::unordered_map<int, int> freq;
    std::pair<int, int> temp;
    std::set<std::pair<int, int>> uniques;

    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        ++freq[x];
        num_of_one = 0;
        uniques.clear();
        for (auto &p: freq) {
            temp.first = p.second;
            temp.second = 1;
            flag = 0;
            for (auto &curr: uniques) {
                if (curr.first == temp.first) {
                    flag = 1;
                    auto &it = curr;
                    auto new_pair = it;
                    ++new_pair.second;
                    uniques.erase(it);
                    uniques.insert(new_pair);
                    break;
                }
            }
            if (!flag) {
                uniques.insert(temp);
            }
            if (p.second == 1) {
                ++num_of_one;
            }
        }
        if (i > 0) {
            bool cond1 = uniques.size() == 1 && num_of_one > 0;
            bool cond2 = uniques.size() == 2 && num_of_one == 1;
            if (cond1 || cond2) {
                l = i + 1;
            } else if (uniques.size() == 2) {
                int diff[2] = {0};
                int j = 0;
                for (auto curr: uniques) {
                    diff[j++] = curr.second;
                }
                if (diff[0] == 1 || diff[1] == 1) {
                    l = i + 1;
                }
            }
        }
    }
    std::cout << l;
}
