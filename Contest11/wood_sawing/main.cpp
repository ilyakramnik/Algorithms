#include <iostream>

int divide(int woods[], int n) {
    int cuts[n + 1][n + 2];
    int cost;
    for (int i = 0; i < n + 1; ++i) {
        cuts[i][i] = 0;
        cuts[i][i + 1] = 0;
    }
    for (int m = 2; m < n + 1; ++m) {
        for (int i = 0; i + m < n + 1; ++i) {
            cost = woods[i + m] - woods[i];
            cuts[i][i + m] = 10000000;
            for (int j = 1; j < m; ++j) {
                cuts[i][i + m] = std::min(cuts[i][i + m], cuts[i][i + j] + cuts[i + j][i + m]);
            }
            cuts[i][i + m] += cost;
        }
    }
    return cuts[0][n];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int l, n;
    std::cin >> l >> n;
    int woods[n + 2];
    woods[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        std::cin >> woods[i];
    }
    woods[++n] = l;
    std::cout << divide(woods, n);
}