// идея взята с сайта https://brestprog.by/topics/mst/
#include <iostream>
#include <vector>
#include <queue>

void addEdge(std::vector<std::vector<std::pair<int, int>>> &graph, int u, int v, int w) {
    graph[u].push_back(std::make_pair(v, w));
    graph[v].push_back(std::make_pair(u, w));
}

std::vector<std::vector<std::pair<int, int>>> readGraph(int n, int m) {
    std::vector<std::vector<std::pair<int, int>>> graph(n);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        addEdge(graph, a - 1, b - 1, c);
    }

    return graph;
}

int findMinSpanningTreeWeight(int n, const std::vector<std::vector<std::pair<int, int>>> &graph) {
    std::vector<bool> visited(n, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;
    int min_spanning_tree_weight = 0;

    pq.push(std::make_pair(0, 0));
    while (!pq.empty()) {
        int vertex = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[vertex]) {
            continue;
        }

        visited[vertex] = true;
        min_spanning_tree_weight += weight;

        for (const std::pair<int, int> &edge : graph[vertex]) {
            int next_vertex = edge.first;
            int edge_weight = edge.second;

            if (!visited[next_vertex]) {
                pq.push(std::make_pair(edge_weight, next_vertex));
            }
        }
    }

    return min_spanning_tree_weight;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> graph = readGraph(n, m);

    int min_spanning_tree_weight = findMinSpanningTreeWeight(n, graph);
    std::cout << min_spanning_tree_weight;
}
