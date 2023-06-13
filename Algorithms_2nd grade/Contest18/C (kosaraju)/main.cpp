#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> adj, radj;
std::vector<bool> visited;
std::vector<int> order, scc;
std::vector<std::string> names;
int n, m;

bool compare(const std::vector<std::string>& a, const std::vector<std::string>& b) {
    return a[0] < b[0];
}

void dfs1(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
    order.push_back(v);
}

void dfs2(int v, int color) {
    visited[v] = true;
    scc[v] = color;
    for (int u : radj[v]) {
        if (!visited[u]) {
            dfs2(u, color);
        }
    }
}

void kosaraju() {
    visited.assign(n, false);
    order.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    visited.assign(n, false);
    scc.assign(n, -1);
    int color = 0;
    for (int i = n - 1; i >= 0; --i) {
        int v = order[i];
        if (!visited[v]) {
            dfs2(v, color++);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int pos;
    std::cin >> n >> m;
    adj.resize(n);
    radj.resize(n);
    names.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pos;
        getline(std::cin.ignore(1), names[i]);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    kosaraju();

    std::vector<std::vector<std::string>> groups(*max_element(scc.begin(), scc.end()) + 1);
    for (int i = 0; i < n; ++i) {
        groups[scc[i]].push_back(names[i]);
    }

    for (auto& group : groups) {
        if (!group.empty()) {
            sort(group.begin(), group.end());
        }
    }
    std::sort(groups.begin(), groups.end(), compare);

    for (auto& group : groups) {
        if (!group.empty()) {
            for (auto& name : group) {
                std::cout << name << '\n';
            }
            std::cout << '\n';
        }
    }
}
