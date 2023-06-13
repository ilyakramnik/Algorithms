// идея взята из презентации к лекции
#include <iostream>
#include <vector>
#include <stack>

const int64_t kInf = 1e12;

struct Edge {
    int64_t a;
    int64_t b;
    int64_t cost;
};

std::vector<int64_t> getShortestDistances(int64_t n, int64_t m, const std::vector<Edge> &graph) {
    std::vector<int64_t> distances(n, kInf);
    distances[0] = 0;

    for (int64_t i = 1; i < n; ++i) {
        for (int64_t j = 0; j < m; ++j) {
            if (distances[graph[j].a] < kInf) {
                if (distances[graph[j].a] != kInf &&
                    distances[graph[j].b] > distances[graph[j].a] + graph[j].cost) {
                    distances[graph[j].b] = distances[graph[j].a] + graph[j].cost;
                }
            }
        }
    }
    return distances;
}

void markNegativeCycle(int64_t n, int64_t m, const std::vector<Edge> &graph,
                       std::vector<int64_t> &distances, std::vector<std::vector<int64_t>> d) {
    std::vector<bool> cycle(n, false);

    for (int64_t i = 0; i < m; ++i) {
        if (distances[graph[i].a] != kInf &&
            distances[graph[i].b] > distances[graph[i].a] + graph[i].cost) {
            distances[graph[i].b] = -kInf;
            if (cycle[graph[i].b]) {
                continue;
            }

            std::stack<int64_t> s;
            cycle[graph[i].b] = true;
            for (auto x : d[graph[i].b]) {
                s.push(x);
            }

            while (!s.empty()) {
                int64_t last = s.top();
                s.pop();

                if (!cycle[last]) {
                    cycle[last] = true;
                    distances[last] = -kInf;
                    for (auto x : d[last]) {
                        s.push(x);
                    }
                }
            }
        }
    }
}

void printDistances(const std::vector<int64_t> &distances) {
    for (int64_t i = 0; i < distances.size() - 1; ++i) {
        if (distances[i + 1] == -kInf) {
            std::cout << "-inf\n";
        } else {
            std::cout << distances[i + 1] << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int64_t n, m;
    std::cin >> n >> m;

    std::vector<Edge> graph;
    std::vector<std::vector<int64_t>> d(n);
    for (int64_t i = 0; i < m; ++i) {
        int64_t u, v, w;
        std::cin >> u >> v >> w;
        graph.push_back({u, v, w});
        d[u].push_back(v);
    }
    std::vector<int64_t> distances = getShortestDistances(n, m, graph);
    markNegativeCycle(n, m, graph, distances, d);
    printDistances(distances);
}
