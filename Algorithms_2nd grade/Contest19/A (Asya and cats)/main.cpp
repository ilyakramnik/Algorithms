#include <iostream>
#include <vector>

int findRoot(std::vector<int>& parent, int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = findRoot(parent, parent[x]);
}

void unite(std::vector<std::vector<int>>& graph, std::vector<int>& parent, int x, int y) {
    x = findRoot(parent, x);
    y = findRoot(parent, y);
    if (x == y) {
        return;
    }
    if (graph[x].size() < graph[y].size()) {
        std::swap(x, y);
    }
    parent[y] = x;
    for (auto u : graph[y]) {
        graph[x].push_back(u);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n);
    std::vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        graph[i].push_back(i);
    }

    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        std::cin >> x >> y;
        unite(graph, parent, x - 1, y - 1);
    }

    int root = findRoot(parent, 0);
    for (auto u : graph[root]) {
        std::cout << u + 1 << ' ';
    }
}
