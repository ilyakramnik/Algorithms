// алгоритм BFS взят из лекции
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>

bool sortNames(const std::string &first, const std::string &second) {
    return first < second;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, pos, main_pos, link1, link2;
    std::string name;
    std::unordered_map<int, std::string> guests;
    std::unordered_map<int, std::vector<int>> links;
    std::vector<std::string> people;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> pos;
        std::getline(std::cin.ignore(1), name);
        guests[pos] = name;
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> link1 >> link2;
        links[link1].push_back(link2);
        links[link2].push_back(link1);
    }
    std::cin >> main_pos;
    std::cout << guests[main_pos] << '\n';

    std::queue<int> q, par, chd;
    par.push(main_pos);
    q.push(main_pos);           // Добавляем стартовую вершину
    std::vector<bool> used(n);  // Вектор признака посещенности вершин
    std::vector<int> p(n);      // Вектор предков
    used[main_pos] = true;  // Стартовую вершину считаем посещенной
    p[main_pos] = -1;       // У стартовой вершины нет предка
    while (!q.empty()) {
        int v = q.front();  // Извлекаем из головы очереди вершину
        q.pop();            // Удаляем извлеченную вершину
        par.pop();
        for (auto to : links[v]) {  // Просмотр всех смежных вершин
            if (!used[to]) {        // Если вершина не посещена,
                used[to] = true;    // посещаем ее
                q.push(to);         // и добавляем к концу очереди
                p[to] = v;          // Запоминаем предка
                chd.push(to);
            }
        }
        if (par.empty()) {
            while (!chd.empty()) {
                par.push(chd.front());
                people.push_back(guests[chd.front()]);
                chd.pop();
            }
            std::sort(people.begin(), people.end(), sortNames);
            for (const auto &x : people) {
                std::cout << x << '\n';
            }
            people.clear();
        }
    }
}
