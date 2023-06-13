// идея взята из презентации к лекции
#include <iostream>
#include <vector>
#include <algorithm>

const int64_t kInf = 1e12;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int64_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int64_t>> graph(n, std::vector<int64_t>(n, kInf));

    for (int64_t i = 0; i < n; ++i) {
        graph[i][i] = 0;
    }

    for (int64_t i = 0; i < m; ++i) {
        int64_t u, v, w;
        std::cin >> u >> v >> w;
        graph[u][v] = w;
    }

    for (int64_t i = 0; i < n; ++i) {
        for (int64_t j = 0; j < n; ++j) {
            for (int64_t k = 0; k < n; ++k) {
                if (graph[j][i] < kInf && graph[i][k] < kInf) {
                    if (graph[j][k] > graph[j][i] + graph[i][k]) {
                        graph[j][k] = graph[j][i] + graph[i][k];
                    }
                }
            }
        }
    }

    for (int64_t i = 0; i < n; ++i) {
        for (int64_t j = 0; j < n; ++j) {
            if (i != j) {
                if (graph[i][j] == kInf) {
                    std::cout << i << " " << j << " -1\n";
                } else {
                    std::cout << i << " " << j << " " << graph[i][j] << "\n";
                }
            }
        }
    }
}
