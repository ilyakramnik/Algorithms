#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

int maxFlow(const std::vector<std::vector<int>>& graph, int source, int target) {
    int n = graph.size();
    std::vector<int> residual(n * n, 0);  // Одномерный массив для матрицы пропускных способностей

    for (int u = 0; u < n; ++u) {
        for (int v : graph[u]) {
            residual[u * n + v] = 1;  // Индексация элементов массива: residual[u * n + v]
        }
    }

    int total_flow = 0;
    while (true) {
        std::vector<int> parent(n, -1);
        std::queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[target] == -1) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; ++v) {
                if (parent[v] == -1 && residual[u * n + v] > 0) {
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        if (parent[target] == -1) {
            break;
        }

        int min_capacity = 1;
        int v = target;
        while (v != source) {
            int u = parent[v];
            min_capacity = std::min(min_capacity, residual[u * n + v]);
            v = u;
        }

        v = target;
        while (v != source) {
            int u = parent[v];
            residual[u * n + v] -= min_capacity;
            residual[v * n + u] += min_capacity;
            v = u;
        }

        total_flow += min_capacity;
    }

    return total_flow;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::unordered_map<std::string, int> vertex_map;
    std::vector<std::vector<int>> graph(n);

    int vertex_id = 0;
    for (int i = 0; i < m; ++i) {
        std::string u, v;
        std::cin >> u >> v;
        if (vertex_map.find(u) == vertex_map.end()) {
            vertex_map[u] = vertex_id++;
        }
        if (vertex_map.find(v) == vertex_map.end()) {
            vertex_map[v] = vertex_id++;
        }
        int u_id = vertex_map[u];
        int v_id = vertex_map[v];
        graph[u_id].push_back(v_id);
        graph[v_id].push_back(u_id);
    }

    for (int i = 0; i < k; ++i) {
        std::string u, v;
        std::cin >> u >> v;
        int u_id = vertex_map[u];
        int v_id = vertex_map[v];
        int flow = maxFlow(graph, u_id, v_id);
        std::cout << flow << '\n';
    }
}
