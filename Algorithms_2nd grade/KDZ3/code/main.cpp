// КДЗ-3, выполнил Крамник Илья Михайлович БПИ-213
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>
#include <limits>
#include <chrono>
#include <fstream>

const int INF = std::numeric_limits<int>::max();

// Функция для генерации полного графа с заданным числом вершин
std::vector<std::vector<int>> generateCompleteGraph(int numVertices) {
    std::vector<std::vector<int>> graph(numVertices, std::vector<int>(numVertices, 1));

    // Обнуляем диагональные элементы, чтобы избежать петель
    for (int i = 0; i < numVertices; ++i) {
        graph[i][i] = 0;
    }

    return graph;
}

// Функция для генерации связного графа с заданным числом вершин и коэффициентом плотности
std::vector<std::vector<int>> generateConnectedGraph(int numVertices, double density) {
    std::vector<std::vector<int>> graph(numVertices, std::vector<int>(numVertices, 0));

    // Генерация ребер
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            if (dist(gen) < density) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }

    // Проверка связности графа
    std::vector<int> visited(numVertices, 0);
    std::vector<int> stack;
    stack.push_back(0);
    visited[0] = 1;

    while (!stack.empty()) {
        int node = stack.back();
        stack.pop_back();

        for (int i = 0; i < numVertices; ++i) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                stack.push_back(i);
            }
        }
    }

    if (std::find(visited.begin(), visited.end(), 0) != visited.end()) {
        // Если граф не связный, повторяем генерацию
        return generateConnectedGraph(numVertices, density);
    }
    return graph;
}

// Функция для генерации разреженного графа (дерева) с заданным числом вершин
std::vector<std::vector<int>> generateSparseGraph(int numVertices) {
    std::vector<std::vector<int>> graph(numVertices, std::vector<int>(numVertices, 0));

    // Связываем вершины по порядку, начиная с 0
    for (int i = 1; i < numVertices; ++i) {
        int parent = i / 2;
        graph[parent][i] = 1;
        graph[i][parent] = 1;
    }

    return graph;
}

// Функция для поиска кратчайшего пути с помощью алгоритма Дейкстры
std::vector<int> dijkstra(std::vector<std::vector<int>> graph, int source) {
    int numVertices = graph.size();

    std::vector<int> distances(numVertices, INF);
    std::vector<bool> visited(numVertices, false);
    distances[source] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (int v = 0; v < numVertices; ++v) {
            if (graph[u][v] != 0 && !visited[v] && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                distances[v] = distances[u] + graph[u][v];
                pq.push(std::make_pair(distances[v], v));
            }
        }
    }
    return distances;
}


// Функция для поиска кратчайших путей между всеми парами вершин с помощью алгоритма Флойда-Уоршелла
std::vector<int> floydWarshall(std::vector<std::vector<int>> graph, int source) {
    int numVertices = graph.size();

    // Создание одномерного вектора расстояний и инициализация его значениями из графа
    std::vector<int> distances(graph[0]);

    // Обновление вектора расстояний с использованием алгоритма Флойда-Уоршелла
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                // Если вершина k является промежуточной для пути от i до j и путь короче текущего значения
                if (distances[i] != INF && graph[i][j] != INF && distances[i] + graph[i][j] < distances[j]) {
                    distances[j] = distances[i] + graph[i][j];
                }
            }
        }
    }
    return distances;
}

std::vector<int> bellmanFord(std::vector<std::vector<int>> graph, int source) {
    int numVertices = graph.size();

    std::vector<int> distances(numVertices, INF);
    distances[source] = 0;

    // Релаксация ребер (numVertices - 1) раз
    for (int i = 0; i < numVertices - 1; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (int v = 0; v < numVertices; ++v) {
                if (graph[u][v] != 0 && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                    distances[v] = distances[u] + graph[u][v];
                }
            }
        }
    }

    // Проверка наличия отрицательных циклов
    for (int u = 0; u < numVertices; ++u) {
        for (int v = 0; v < numVertices; ++v) {
            if (graph[u][v] != 0 && distances[u] != INF && distances[u] + graph[u][v] < distances[v]) {
                // Обнаружен отрицательный цикл
                // Можно выполнить дополнительные действия или прервать алгоритм
                // В данном случае, просто возвращаем пустой вектор
                return {};
            }
        }
    }
    return distances;
}

struct Node {
    int vertex;
    int cost;

    Node(int v, int c) : vertex(v), cost(c) {}
};

struct Compare {
    bool operator()(const Node &a, const Node &b) {
        return a.cost > b.cost;
    }
};

// Функция для поиска кратчайшего пути в графе с помощью алгоритма A*
std::vector<int> astar(std::vector<std::vector<int>> graph, int start) {
    int numVertices = graph.size();

    std::vector<int> h(numVertices, INF); // Эвристические оценки (расстояния) до целевой вершины
    std::vector<int> g(numVertices, INF); // Расстояния от стартовой вершины до текущей вершины
    std::vector<int> f(numVertices, INF); // Оценки общей стоимости (g + h) для каждой вершины
    std::vector<int> parent(numVertices, -1); // Родительские вершины для восстановления пути

    std::priority_queue<Node, std::vector<Node>, Compare> pq;
    pq.push(Node(start, 0));
    g[start] = 0;
    f[start] = h[start];

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int currentVertex = current.vertex;

        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (graph[currentVertex][neighbor] != INF) {
                int newCost = g[currentVertex] + graph[currentVertex][neighbor];
                if (newCost < g[neighbor]) {
                    g[neighbor] = newCost;
                    h[neighbor] = 1;
                    f[neighbor] = g[neighbor] + h[neighbor];
                    parent[neighbor] = currentVertex;
                    pq.push(Node(neighbor, f[neighbor]));
                }
            }
        }
    }

    // Восстановление пути
    std::vector<int> path;
    int current = start;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    std::reverse(path.begin(), path.end());

    return path;
}

int main() {
    std::vector<int>(*search_pointers[4])(std::vector<std::vector<int>>, int) = {
            // массив указателей на функции алгоритмов работы с графами
            dijkstra, floydWarshall, bellmanFord, astar
    };
    std::ofstream out1, out2, out3, out4;

    out1.open("dijkstra_ca.csv");
    out2.open("floydWarshall_ca.csv");
    out3.open("bellmanFord_ca.csv");
    out4.open("astar_ca.csv");
    out1.close();
    out2.close();
    out3.close();
    out4.close();
    out1.open("dijkstra_ca.csv", std::ios::app);
    out2.open("floydWarshall_ca.csv", std::ios::app);
    out3.open("bellmanFord_ca.csv", std::ios::app);
    out4.open("astar_ca.csv", std::ios::app);

    int verticesOrEdges = 0;
    for (int i = 10; i <= 1010; i += 200) {
        if (out1.is_open()) {
            if (verticesOrEdges == 0) {
                out1 << i << ';';
            } else {
                out1 << (i * (i - 1)) / 10 << ';';
            }
        }
        if (out2.is_open()) {
            if (verticesOrEdges == 0) {
                out2 << i << ';';
            } else {
                out2 << (i * (i - 1)) / 10 << ';';
            }
        }
        if (out3.is_open()) {
            if (verticesOrEdges == 0) {
                out3 << i << ';';
            } else {
                out3 << (i * (i - 1)) / 10 << ';';
            }
        }
        if (out4.is_open()) {
            if (verticesOrEdges == 0) {
                out4 << i << ';';
            } else {
                out4 << (i * (i - 1)) / 10 << ';';
            }
        }
    }
    out1 << '\n';
    out2 << '\n';
    out3 << '\n';
    out4 << '\n';

    int type = 3;
    if (type == 1) {
        for (int i = 3; i >= 0; --i) { // цикл по всем алгоритмам
            // Генерация полных графов с числом вершин от 10 до 1010 (шаг 50)
            for (int numVertices = 10; numVertices <= 1010; numVertices += 200) {
                std::vector<std::vector<int>> completeGraph = generateCompleteGraph(numVertices);
                uint64_t sum = 0;  // сумма всех записей времени для усреднения
                for (int j = 0; j < 2; ++j) { // 10 раз запускаем алгоритм, чтобы усреднить время
                    auto start = std::chrono::high_resolution_clock::now();  // начало замера времени
                    (*search_pointers[i])(completeGraph, 0);
                    auto elapsed =
                            std::chrono::high_resolution_clock::now() - start;  // завершаем замер времени
                    uint64_t nanoseconds =
                            std::chrono::duration_cast<std::chrono::nanoseconds>(
                                    elapsed).count();  // находим кол-во наносекунд
                    sum += nanoseconds;  // увеличиваем сумму на число работы алгоритма
                }
                std::cout << i << ' ' << sum / 2 << '\n';
                if (i == 0) {
                    if (out1.is_open()) {
                        out1 << sum / 2 << ';';
                    }
                } else if (i == 1) {
                    if (out2.is_open()) {
                        out2 << sum / 2 << ';';
                    }
                } else if (i == 2) {
                    if (out3.is_open()) {
                        out3 << sum / 2 << ';';
                    }
                } else if (i == 3) {
                    if (out4.is_open()) {
                        out4 << sum / 2 << ';';
                    }
                }
            }
            if (i == 0) {
                out1 << '\n';
            } else if (i == 1) {
                out2 << '\n';
            } else if (i == 2) {
                out3 << '\n';
            } else if (i == 3) {
                out4 << '\n';
            }
        }
    } else if (type == 2) {
        // Генерация связных графов с числом вершин от 10 до 1010 (шаг 50) и коэффициентом плотности приблизительно 0.4-0.5
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> densityDist(0.4, 0.5);
        for (int i = 3; i >= 0; --i) { // цикл по всем алгоритмам
            for (int numVertices = 10; numVertices <= 1010; numVertices += 200) {
                double density = densityDist(gen);
                std::vector<std::vector<int>> connectedGraph = generateConnectedGraph(numVertices, density);
                uint64_t sum = 0;  // сумма всех записей времени для усреднения
                for (int j = 0; j < 2; ++j) { // 10 раз запускаем алгоритм, чтобы усреднить время
                    auto start = std::chrono::high_resolution_clock::now();  // начало замера времени
                    (*search_pointers[i])(connectedGraph, 0);
                    auto elapsed =
                            std::chrono::high_resolution_clock::now() - start;  // завершаем замер времени
                    uint64_t nanoseconds =
                            std::chrono::duration_cast<std::chrono::nanoseconds>(
                                    elapsed).count();  // находим кол-во наносекунд
                    sum += nanoseconds;  // увеличиваем сумму на число работы алгоритма
                }
                std::cout << i << ' ' << sum / 2 << '\n';
                if (i == 0) {
                    if (out1.is_open()) {
                        out1 << sum / 2 << ';';
                    }
                } else if (i == 1) {
                    if (out2.is_open()) {
                        out2 << sum / 2 << ';';
                    }
                } else if (i == 2) {
                    if (out3.is_open()) {
                        out3 << sum / 2 << ';';
                    }
                } else if (i == 3) {
                    if (out4.is_open()) {
                        out4 << sum / 2 << ';';
                    }
                }
            }
            if (i == 0) {
                out1 << '\n';
            } else if (i == 1) {
                out2 << '\n';
            } else if (i == 2) {
                out3 << '\n';
            } else if (i == 3) {
                out4 << '\n';
            }
        }
    } else if (type == 3) {
        for (int i = 3; i >= 0; --i) { // цикл по всем алгоритмам
            for (int numVertices = 10; numVertices <= 1010; numVertices += 200) {
                std::vector<std::vector<int>> sparseGraph = generateSparseGraph(numVertices);
                uint64_t sum = 0;  // сумма всех записей времени для усреднения
                for (int j = 0; j < 2; ++j) { // 10 раз запускаем алгоритм, чтобы усреднить время
                    auto start = std::chrono::high_resolution_clock::now();  // начало замера времени
                    (*search_pointers[i])(sparseGraph, 0);
                    auto elapsed =
                            std::chrono::high_resolution_clock::now() - start;  // завершаем замер времени
                    uint64_t nanoseconds =
                            std::chrono::duration_cast<std::chrono::nanoseconds>(
                                    elapsed).count();  // находим кол-во наносекунд
                    sum += nanoseconds;  // увеличиваем сумму на число работы алгоритма
                }
                std::cout << i << ' ' << sum / 2 << '\n';
                if (i == 0) {
                    if (out1.is_open()) {
                        out1 << sum / 2 << ';';
                    }
                } else if (i == 1) {
                    if (out2.is_open()) {
                        out2 << sum / 2 << ';';
                    }
                } else if (i == 2) {
                    if (out3.is_open()) {
                        out3 << sum / 2 << ';';
                    }
                } else if (i == 3) {
                    if (out4.is_open()) {
                        out4 << sum / 2 << ';';
                    }
                }
            }
            if (i == 0) {
                out1 << '\n';
            } else if (i == 1) {
                out2 << '\n';
            } else if (i == 2) {
                out3 << '\n';
            } else if (i == 3) {
                out4 << '\n';
            }
        }
    }
}
