#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <set>

using namespace std;
int64_t kInf = 1e12;

struct Node {
    int number;
    int cost;
};

int sumDigits(int number) {
    int sum = 0;

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

set<vector<pair<int, int>>> createGraph(int X, int Y, int n) {
    set<vector<int>> graph;
    //graph.resize(n*n);
    queue<Node> q;
    q.push({X, 0});
    int count = 0;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        if (node.number == Y) {
            ++count;
        }

        if (count > 20){
            break;
        }

        string strNumber = to_string(node.number);
        int strLen = strNumber.length();

        for (int i = 0; i < strLen; i++) {
            for (int j = 1; j <= strLen - i; j++) {
                string subStr = strNumber.substr(i, j);
                int subNumber = stoi(subStr);

                if (subNumber != 0) {
                    int nextNumber1 = node.number + subNumber;
                    int cost1 = node.cost + sumDigits(subNumber);

                    int nextNumber2 = node.number - subNumber;
                    int cost2 = node.cost + sumDigits(subNumber);

                    if (nextNumber1 <= n) {
                        graph.insert({node.number, nextNumber1, cost1});
                        q.push({nextNumber1, cost1});
                    }

                    if (nextNumber2 > 0) {
                        graph.insert({node.number, nextNumber2, cost2});
                        q.push({nextNumber2, cost2});
                    }
                }
            }
        }
    }
    return graph;
}

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int start, int end) {
    int numVertices = graph.size();
    vector<int> distances(numVertices, numeric_limits<int>::max());
    vector<int> parent(numVertices, -1);
    vector<bool> visited(numVertices, false);

    distances[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == end)
            break;

        if (visited[u])
            continue;

        visited[u] = true;

        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int cost = neighbor.second;

            if (!visited[v] && distances[u] + cost < distances[v]) {
                distances[v] = distances[u] + cost;
                parent[v] = u;
                pq.push({distances[v], v});
            }
        }
    }

    vector<int> path;
    int current = end;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    return path;
}


int main() {
    int n, X, Y;
    cin >> n >> X >> Y;

    set<vector<pair<int, int>>> graph = createGraph(X, Y, n);

    vector<vector<pair<int, int>>> new_graph (10000);

    int c = 0;
    for (auto x : graph){
        new_graph[x[c++].first]
    }

    // Вывод графа
    /*for (const auto& edge : graph) {
        cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
    }*/

    vector<int> shortestPath = dijkstra(graph, X, Y);

    // Вывод кратчайшего пути
    for (int vertex : shortestPath) {
        cout << vertex << " ";
    }
}
