// код написан на основе идеи с сайта https://habr.com/ru/articles/587838/
#include <iostream>
#include <vector>

int64_t max_flow = 0, start_sum = 0, target_sum = 0;

struct Edge {
    int from;
    int to;
    int flow;

    Edge(int from = -1, int to = -1, int flow = 0);
};

Edge::Edge(int from, int to, int flow) {
    this->from = from;
    this->to = to;
    this->flow = flow;
}

int findBackEdge(const std::vector<std::vector<Edge>>& edges, int from, int to) {
    for (int child = 0; child < edges[to].size(); ++child) {
        if (edges[to][child].to == from) {
            return child;
        }
    }
    return -1;
}

int symbols(char atom) {
    if (atom == 'H') {
        return 1;
    } else if (atom == 'O') {
        return 2;
    } else if (atom == 'N') {
        return 3;
    } else if (atom == 'C') {
        return 4;
    }
    return 0;
}

void addEdge(std::vector<std::vector<Edge>>& edges, int from, int to, int flow = 1) {
    edges[from].push_back(Edge(from, to, flow));
}

void uncheckAll(std::vector<bool>& checked) {
    for (int i = 0; i < checked.size(); ++i) {
        checked[i] = false;
    }
}

int toVertNum(int i, int j, int m) {
    return i * m + j + 1;
}

void initGraph(std::vector<std::vector<Edge>>& edges, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char atom;
            std::cin >> atom;
            if ((i % 2 + j % 2) % 2 == 0) {
                addEdge(edges, 0, toVertNum(i, j, m), symbols(atom));
                start_sum += symbols(atom);
                if (i + 1 < n) {
                    addEdge(edges, toVertNum(i, j, m), toVertNum(i + 1, j, m));
                }
                if (j + 1 < m) {
                    addEdge(edges, toVertNum(i, j, m), toVertNum(i, j + 1, m));
                }
                if (i - 1 >= 0) {
                    addEdge(edges, toVertNum(i, j, m), toVertNum(i - 1, j, m));
                }
                if (j - 1 >= 0) {
                    addEdge(edges, toVertNum(i, j, m), toVertNum(i, j - 1, m));
                }
            } else {
                addEdge(edges, toVertNum(i, j, m), n * m + 1, symbols(atom));
                target_sum += symbols(atom);
            }
        }
    }
}

int tryPushFlow(std::vector<std::vector<Edge>>& edges, std::vector<bool>& checked, int current = 0,
                int capacity = 5) {
    checked[current] = true;
    if (current == edges.size() - 1) {
        max_flow += capacity;
        return capacity;
    }
    for (int e = 0; e < edges[current].size(); ++e) {
        Edge& current_edge = edges[current][e];

        if (checked[current_edge.to] || current_edge.flow == 0) {
            continue;
        }
        int min_capacity =
            tryPushFlow(edges, checked, current_edge.to, std::min(current_edge.flow, capacity));
        if (min_capacity > 0) {
            current_edge.flow -= min_capacity;
            int back_edge_num = findBackEdge(edges, current, current_edge.to);
            if (back_edge_num != -1) {
                edges[current_edge.to][back_edge_num].flow += min_capacity;
            } else {
                edges[current_edge.to].push_back(Edge(current_edge.to, current, min_capacity));
            }
            return min_capacity;
        }
    }
    return 0;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<bool> checked(n * m + 2, false);
    std::vector<std::vector<Edge>> edges(n * m + 2);
    initGraph(edges, n, m);

    while (tryPushFlow(edges, checked)) {
        uncheckAll(checked);
    }
    if (max_flow == start_sum && max_flow == target_sum && max_flow != 0) {
        std::cout << "Valid";
    } else {
        std::cout << "Invalid";
    }
}
