#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> graph, transposed_graph;
std::vector<int> node_labels, component_labels, component_sizes, order;
std::vector<bool> visited;

void addEdge(int u, int v) {
    graph[u].push_back(v);
    transposed_graph[v].push_back(u);
}

void dfsTopSort(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsTopSort(neighbor);
        }
    }
    order.push_back(node);
}

void dfsComponent(int node, int label) {
    component_labels[node] = label;
    ++component_sizes[label];
    for (int neighbor : transposed_graph[node]) {
        if (component_labels[neighbor] == -1) {
            dfsComponent(neighbor, label);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, h;
    std::cin >> n >> m >> h;

    graph.resize(n);
    transposed_graph.resize(n);
    node_labels.resize(n);
    for (int &label : node_labels) {
        std::cin >> label;
    }

    std::vector<std::pair<int, int>> edge_list;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        if ((node_labels[u] + 1) % h == node_labels[v]) {
            edge_list.emplace_back(u, v);
            addEdge(u, v);
        }
        if ((node_labels[v] + 1) % h == node_labels[u]) {
            edge_list.emplace_back(v, u);
            addEdge(v, u);
        }
    }

    visited.assign(n, false);
    for (int node = 0; node < n; ++node) {
        if (!visited[node]) {
            dfsTopSort(node);
        }
    }
    std::reverse(order.begin(), order.end());

    component_labels.assign(n, -1);
    for (int node : order) {
        if (component_labels[node] == -1) {
            component_sizes.push_back(0);
            dfsComponent(node, static_cast<int>(component_sizes.size()) - 1);
        }
    }

    std::vector<std::vector<int>> component_graph(component_sizes.size());
    for (int i = 0; i < edge_list.size(); i++) {
        int u = edge_list[i].first;
        int v = edge_list[i].second;
        if (component_labels[u] != component_labels[v]) {
            component_graph[component_labels[u]].push_back(component_labels[v]);
        }
    }

    int min_component_size = n + 1, min_component_index = -1;
    for (int i = 0; i < component_sizes.size(); ++i) {
        if (component_graph[i].empty() && component_sizes[i] < min_component_size) {
            min_component_size = component_sizes[i];
            min_component_index = i;
        }
    }

    std::cout << min_component_size << '\n';
    for (int i = 0; i < n; ++i) {
        if (component_labels[i] == min_component_index) {
            std::cout << i + 1 << " ";
        }
    }
}
