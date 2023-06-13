// алгоритм bfs взят из презентации к лекции
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int dist[1501][1501];
std::pair<int, int> parent[1501][1501];

int k_dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int k_dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void bfs(int x, int y, int n) {
    bool used[1501][1501];
    std::queue<std::pair<int, int>> q;
    used[x][y] = true;
    dist[x][y] = 0;
    q.push({x, y});

    while (!q.empty()) {
        auto curr = q.front();
        q.pop();

        int curr_x = curr.first;
        int curr_y = curr.second;

        for (int i = 0; i < 8; ++i) {
            int next_x = curr_x + k_dx[i];
            int next_y = curr_y + k_dy[i];

            if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= n && !used[next_x][next_y]) {
                used[next_x][next_y] = true;
                dist[next_x][next_y] = dist[curr_x][curr_y] + 1;
                parent[next_x][next_y] = {curr_x, curr_y};
                q.push({next_x, next_y});
            }
        }
    }
}

int main() {
    int n, x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    bfs(x1, y1, n);
    std::cout << dist[x2][y2] << '\n';

    std::vector<std::pair<int, int>> path;
    int x = x2, y = y2;
    path.emplace_back(x, y);

    while (x != x1 || y != y1) {
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
        path.emplace_back(x, y);
    }

    for (int i = static_cast<int>(path.size()) - 1; i >= 0; --i) {
        std::cout << path[i].first << " " << path[i].second << '\n';
    }
}
