#include <iostream>
#include <algorithm>
#include <vector>

struct Edge {
    int startVertex;
    int endVertex;
    int weight;

    Edge() {
    }

    Edge(int start, int end, int w) : startVertex(start), endVertex(end), weight(w) {
    }

    bool operator==(const Edge &other) const {
        return (startVertex == other.startVertex && endVertex == other.endVertex &&
                weight == other.weight);
    }
};

int findSet(int e, std::vector<int> &parent) {
    if (parent[e] == e) {
        return e;
    }
    return parent[e] = findSet(parent[e], parent);
}

void unionSets(int a, int b, std::vector<int> &parent, std::vector<int> &rank) {
    if (rank[a] < rank[b]) {
        parent[a] = b;
    } else if (rank[a] > rank[b]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        rank[a]++;
    }
}

std::pair<int, std::vector<Edge>> kruskal(int num_vertices, int num_edges,
                                          std::vector<Edge> &edge_list, Edge excluded_edge) {
    std::sort(edge_list.begin(), edge_list.end(),
              [](const Edge &a, const Edge &b) { return a.weight < b.weight; });

    std::vector<int> parent(num_vertices + 1);
    std::vector<int> rank(num_vertices + 1, 0);
    for (int i = 1; i <= num_vertices; ++i) {
        parent[i] = i;
    }

    int total_weight = 0;
    std::vector<Edge> min_spanning_tree;
    for (int i = 0; i < num_edges; ++i) {
        Edge edge = edge_list[i];
        if (edge == excluded_edge) {
            continue;
        }
        int a = findSet(edge.startVertex, parent);
        int b = findSet(edge.endVertex, parent);
        if (a != b) {
            total_weight += edge.weight;
            min_spanning_tree.push_back(edge);
            unionSets(a, b, parent, rank);
        }
    }

    return {total_weight, min_spanning_tree};
}

std::vector<Edge> readEdges(int num_edges) {
    std::vector<Edge> edge_list(num_edges);
    for (int i = 0; i < num_edges; ++i) {
        std::cin >> edge_list[i].startVertex >> edge_list[i].endVertex >> edge_list[i].weight;
    }
    return edge_list;
}

std::vector<int> findMSTWeights(int num_vertices, int num_edges, std::vector<Edge> &edge_list) {
    std::vector<int> weights;

    auto first_iteration = kruskal(num_vertices, num_edges, edge_list, Edge(-1, -1, -1));
    weights.push_back(first_iteration.first);
    std::vector<Edge> min_spanning_tree = first_iteration.second;

    for (const Edge &edge : min_spanning_tree) {
        weights.push_back(kruskal(num_vertices, num_edges, edge_list, edge).first);
    }

    std::sort(weights.begin(), weights.end());

    return weights;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int num_vertices, num_edges;
    std::cin >> num_vertices >> num_edges;

    std::vector<Edge> edge_list = readEdges(num_edges);
    std::vector<int> weights = findMSTWeights(num_vertices, num_edges, edge_list);
    std::cout << weights[0] << ' ' << weights[1];
}
