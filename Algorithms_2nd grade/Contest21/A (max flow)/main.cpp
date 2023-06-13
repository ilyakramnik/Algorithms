// идея взята из презентации к лекции
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

void addEdge(std::vector<std::vector<int>>& graph, int source, int destination, int capacity) {
    graph[source][destination] = capacity;
}

bool bfs(std::vector<std::vector<int>>& residual_graph, std::vector<int>& parent) {
    int num_vertices = static_cast<int>(residual_graph.size());
    std::vector<bool> visited(num_vertices, false);
    std::queue<int> q;
    q.push(0);
    visited[0] = true;
    parent[0] = -1;

    while (!q.empty()) {
        int current_vertex = q.front();
        q.pop();

        for (int next_vertex = 0; next_vertex < num_vertices; next_vertex++) {
            int residual_capacity = residual_graph[current_vertex][next_vertex];
            if (!visited[next_vertex] && residual_capacity > 0) {
                q.push(next_vertex);
                parent[next_vertex] = current_vertex;
                visited[next_vertex] = true;
            }
        }
    }
    return visited[num_vertices - 1];
}

int findMaxFlow(std::vector<std::vector<int>>& graph) {
    int num_vertices = static_cast<int>(graph.size());
    std::vector<std::vector<int>> residual_graph(num_vertices, std::vector<int>(num_vertices, 0));

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            residual_graph[i][j] = graph[i][j];
        }
    }
    int max_flow = 0;
    std::vector<int> parent(num_vertices, -1);

    while (bfs(residual_graph, parent)) {
        int path_flow = INT_MAX;
        for (int v = num_vertices - 1; v != 0; v = parent[v]) {
            int u = parent[v];
            path_flow = std::min(path_flow, residual_graph[u][v]);
        }

        for (int v = num_vertices - 1; v != 0; v = parent[v]) {
            int u = parent[v];
            residual_graph[u][v] -= path_flow;
            residual_graph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int source, destination, capacity;
        std::cin >> source >> destination >> capacity;
        addEdge(graph, source - 1, destination - 1, capacity);
    }
    int max_flow = findMaxFlow(graph);

    std::cout << max_flow << std::endl;
}
