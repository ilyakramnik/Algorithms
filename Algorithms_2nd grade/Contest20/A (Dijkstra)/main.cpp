// псевдокод взят из презентации к лекции
#include <iostream>
#include <vector>

const int64_t kInf = 1000000000000000;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int64_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int64_t, int64_t>>> g(n);
    for (int64_t i = 0; i < m; ++i) {
        int64_t u, v, w;
        std::cin >> u >> v >> w;
        g[u].push_back(std::make_pair(v, w));
    }

    int64_t s = 0;

    std::vector<int64_t> d(n, kInf), p(n);
    d[s] = 0;
    std::vector<char> u(n);
    for (int64_t i = 0; i < n; ++i) {
        int64_t v = -1;
        for (int64_t j = 0; j < n; ++j) {
            if (!u[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        if (d[v] == kInf) {
            break;
        }
        u[v] = true;

        for (size_t j = 0; j < g[v].size(); ++j) {
            int64_t to = g[v][j].first, len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    for (int64_t i = 1; i < n; ++i) {
        std::cout << d[i] << std::endl;
    }
}
