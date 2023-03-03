#include <iostream>
#include <cmath>
#include <iomanip>

double findRightBoard(double c, double right_board) {
    while (right_board * right_board + std::pow(right_board, 0.5) < c) {
        right_board = right_board * 2;
    }
    return right_board;
}

double binSearch(double c, double left, double right) {
    double mid;
    right = findRightBoard(c, right);
    while (right - left > 0.000000001) {  // Здесь можно использовать другое условие выхода
        mid = left + (right - left) / 2;
        if (mid * mid + std::pow(mid, 0.5) < c) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return (left + right) / 2;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    double c, left_board = 0.5, right_board = 0.5;
    std::cin >> c;
    std::cout << std::fixed << std::setprecision(9) << binSearch(c, left_board, right_board);
}