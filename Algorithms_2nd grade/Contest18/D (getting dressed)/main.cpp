#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

std::vector<int> links[5001];
std::vector<bool> used;
std::stack<int> stk;
std::vector<std::pair<std::string, int>> item_pairs;
std::vector<std::string> items;

bool sortNames(int &first, int &second) {
    return items[first] < items[second];
}

void dfs(int u) {
    if (!used[u]) {
        std::sort(links[u].begin(), links[u].end(), sortNames);
    }
    used[u] = true;
    for (int v : links[u]) {
        if (!used[v]) {
            dfs(v);
        }
    }
    stk.push(u);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, m, pos;
    std::cin >> n >> m;

    items.resize(n + 1);
    used.resize(n + 1);
    std::vector<int> sons(n);
    for (int i = 1; i <= n; ++i) {
        std::cin >> pos;
        getline(std::cin.ignore(1), items[i]);
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        links[a].push_back(b);
        sons.push_back(b);
    }

    std::vector<int> parents;
    for (int i = 1; i <= n; ++i) {
        int fl = 0;
        for (int j = 0; j < sons.size(); ++j) {
            if (sons[j] == i) {
                fl = 1;
                break;
            }
        }
        if (fl == 0) {
            parents.push_back(i);
        }
    }

    item_pairs.resize(n);
    for (int i = 1; i <= n; ++i) {
        item_pairs[i - 1] = {items[i], i};
    }
    sort(item_pairs.begin(), item_pairs.end());

    for (int i = 0; i < n; ++i) {
        int fl = 0;
        for (int j = 0; j < parents.size(); ++j) {
            if (items[parents[j]] == item_pairs[i].first) {
                fl = 1;
                break;
            }
        }
        if (fl) {
            int u = item_pairs[i].second;
            if (!used[u]) {
                dfs(u);
            }
        }
    }

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        std::cout << items[u] << '\n';
    }
}
