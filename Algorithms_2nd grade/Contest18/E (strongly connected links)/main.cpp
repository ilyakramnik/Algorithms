// идея взята из презентации к лекции
#include <iostream>
#include <vector>
#include <algorithm>

void dfs1(int v, const std::vector<std::vector<int>>& g, std::vector<bool>& used,
          std::vector<int>& order) {
    used[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to]) {
            dfs1(to, g, used, order);
        }
    }
    order.push_back(v);
}

void dfs2(int v, int color, const std::vector<std::vector<int>>& gr, std::vector<int>& comp) {
    comp[v] = color;
    for (int i = 0; i < gr[v].size(); ++i) {
        int to = gr[v][i];
        if (comp[to] == 0) {
            dfs2(to, color, gr, comp);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> g(n), gr(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u - 1].push_back(v - 1);
        gr[v - 1].push_back(u - 1);
    }

    std::vector<bool> used(n, false);
    std::vector<int> order;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfs1(i, g, used, order);
        }
    }

    std::vector<int> comp(n, 0);
    int color = 1;
    for (int i = n - 1; i >= 0; --i) {
        int v = order[i];
        if (comp[v] == 0) {
            dfs2(v, color, gr, comp);
            ++color;
        }
    }

    std::cout << color - 1 << '\n';
    for (int i = 0; i < n; ++i) {
        std::cout << comp[i] << " ";
    }
}
