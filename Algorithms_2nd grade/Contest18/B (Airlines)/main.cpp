#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    // Инициализация матрицы расстояний
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    // Чтение рейсов и заполнение матрицы расстояний
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; // приводим номера городов к нумерации с нуля
        b--;
        dist[a][b] = 1;
        dist[b][a] = 1; // добавляем ребро в обратном направлении
    }

    // Алгоритм Флойда-Уоршелла
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Ищем минимальное количество рейсов между городами
    int min_flights = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) { // если нет пути между городами, пропускаем
                continue;
            }
            int flights = 0;
            for (int k = 0; k < n; k++) {
                if (dist[i][k] == 1 && dist[k][j] == 1) { // если есть прямой рейс между i и k и между k и j
                    flights++;
                }
            }
            min_flights = min(min_flights, flights);
        }
    }

    cout << min_flights << endl;

    return 0;
}
