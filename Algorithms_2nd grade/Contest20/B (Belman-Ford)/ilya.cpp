// код из лекции

#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <queue>

#define int int64_t

const int kInf = 1e12;

struct Edge {
    int a, b, cost;
};

signed main() {
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;

    std::cin >> n >> m;

    std::vector<Edge> edges;
    std::vector<std::vector<int>> dest(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges.push_back({u, v, w});
        dest[u].push_back(v);
    }

    std::vector<int> distances(n, kInf);
    int v = 0;
    distances[v] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (distances[edges[j].a] < kInf) {
                if (distances[edges[j].a] != kInf &&
                    distances[edges[j].b] > distances[edges[j].a] + edges[j].cost) {
                    distances[edges[j].b] = distances[edges[j].a] + edges[j].cost;
                }
            }
        }
    }

    std::vector<bool> visited(n, false);
    for (int i = 0; i < m; ++i) {
        if (distances[edges[i].a] != kInf &&
            distances[edges[i].b] > distances[edges[i].a] + edges[i].cost) {
            distances[edges[i].b] = -kInf;

            if (visited[edges[i].b]) {
                continue;
            }

            visited[edges[i].b] = true;
            std::queue<int> q;
            for (auto x : dest[edges[i].b]) {
                q.push(x);
            }

            while (!q.empty()) {
                int cur = q.front();
                q.pop();

                if (!visited[cur]) {
                    visited[cur] = true;
                    distances[cur] = -kInf;
                    for (auto x : dest[cur]) {
                        q.push(x);
                    }
                }
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        if (distances[i] == -kInf) {
            std::cout << "-inf\n";
        } else {
            std::cout << distances[i] << '\n';
        }
    }

    return 0;
}
