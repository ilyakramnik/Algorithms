// алгоритм DFS взят из презентации к лекции
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <stack>

std::vector<std::string> guests;
std::vector<std::string> ans, ans_set;
std::vector<std::vector<int>> links;

bool sortNames(int &first, int &second) {
    return guests[first] < guests[second];
}

void dfs(int &v, std::vector<bool> &used) {
    if (!used[v]) {
        std::sort(links[v].begin(), links[v].end(), sortNames);
    }
    used[v] = true;

    for (auto x : links[v]) {
        if (!used[x]) {
            ans.push_back(guests[x]);
            dfs(x, used);
        }
    }
}

void iterativeDFS(int v, std::vector<bool> &used) {
    std::stack<int> stack;
    stack.push(v);
    while (!stack.empty()) {
        v = stack.top();
        stack.pop();
        if (used[v]) {
            continue;
        }

        ans.push_back(guests[v]);
        used[v] = true;

        std::sort(links[v].begin(), links[v].end(), sortNames);

        for (auto it = links[v].rbegin(); it != links[v].rend(); ++it) {
            auto x = *it;
            if (!used[x]) {
                stack.push(x);
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, pos, main_pos, link1, link2;
    std::string name;
    std::cin >> n >> m;
    links.resize(n);
    guests.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pos;
        std::getline(std::cin.ignore(1), name);
        guests[pos] = name;
        // reversed_guests[name] = pos;
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> link1 >> link2;
        links[link1].push_back(link2);
        links[link2].push_back(link1);
    }
    std::cin >> main_pos;
    std::cout << guests[main_pos] << '\n';

    std::vector<bool> used(n);
    dfs(main_pos, used);
    // iterativeDFS(main_pos, used);

    for (auto &x : ans) {
        int c = std::count(ans_set.begin(), ans_set.end(), x);
        if (c == 0) {
            std::cout << x << '\n';
            ans_set.push_back(x);
        }
    }
}
