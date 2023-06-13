// идея взята из презентации к лекции
#include <iostream>
#include <vector>
#include <limits>

int64_t calculateDistance(int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

std::vector<int64_t> solveTSP(int64_t n, const std::vector<int64_t>& x,
                              const std::vector<int64_t>& y) {
    std::vector<int64_t> path;
    std::vector<bool> visited(n, false);
    int64_t min_distance = std::numeric_limits<int64_t>::max();
    int64_t starting_city = 0;

    for (int64_t i = 0; i < n; ++i) {
        for (int64_t j = 0; j < i; ++j) {
            int64_t distance = calculateDistance(x[i], y[i], x[j], y[j]);
            if (distance < min_distance) {
                min_distance = distance;
                starting_city = i;
            }
        }
    }

    path.push_back(starting_city);
    visited[starting_city] = true;

    int64_t path_size = 1;
    int64_t current_city = starting_city;

    while (path_size != n) {
        int64_t min_dist = std::numeric_limits<int64_t>::max();
        int64_t next_city = -1;

        for (int64_t i = 0; i < n; i++) {
            if (!visited[i]) {
                int64_t dist = calculateDistance(x[current_city], y[current_city], x[i], y[i]);
                if (dist < min_dist) {
                    min_dist = dist;
                    next_city = i;
                }
            }
        }

        path.emplace_back(next_city);
        visited[next_city] = true;
        current_city = next_city;
        ++path_size;
    }
    return path;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int64_t n;
    std::cin >> n;
    std::vector<int64_t> x(n);
    std::vector<int64_t> y(n);

    for (int64_t i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i];
    }
    std::vector<int64_t> path = solveTSP(n, x, y);

    for (int i = 0; i < n; ++i) {
        std::cout << path[i] + 1 << " ";
    }
}
