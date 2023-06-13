#include <iostream>
#include <vector>
#include <algorithm>

struct Board {
    int x1, y1, x2, y2;

    bool operator<(const Board& other) const {
        return std::min(x1, x2) < std::min(other.x1, other.x2);
    }
};

bool onSegment(int x1, int y1, int x2, int y2, int x, int y) {
    return std::min(x1, x2) <= x && x <= std::max(x1, x2) && std::min(y1, y2) <= y &&
           y <= std::max(y1, y2);
}

int orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    int val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);

    if (val == 0) {
        return 0;
    } else if (val > 0) {
        return 1;
    } else {
        return 2;
    }
}

bool doSegmentsIntersect(const Board& board1, const Board& board2) {
    int o1 = orientation(board1.x1, board1.y1, board1.x2, board1.y2, board2.x1, board2.y1);
    int o2 = orientation(board1.x1, board1.y1, board1.x2, board1.y2, board2.x2, board2.y2);
    int o3 = orientation(board2.x1, board2.y1, board2.x2, board2.y2, board1.x1, board1.y1);
    int o4 = orientation(board2.x1, board2.y1, board2.x2, board2.y2, board1.x2, board1.y2);

    if (o1 != o2 && o3 != o4) {
        return true;
    }

    if (o1 == 0 && onSegment(board1.x1, board1.y1, board1.x2, board1.y2, board2.x1, board2.y1)) {
        return true;
    }

    if (o2 == 0 && onSegment(board1.x1, board1.y1, board1.x2, board1.y2, board2.x2, board2.y2)) {
        return true;
    }

    if (o3 == 0 && onSegment(board2.x1, board2.y1, board2.x2, board2.y2, board1.x1, board1.y1)) {
        return true;
    }

    if (o4 == 0 && onSegment(board2.x1, board2.y1, board2.x2, board2.y2, board1.x2, board1.y2)) {
        return true;
    }
    return false;
}

bool canCross(const Board& board, const std::vector<Board>& used_boards) {
    for (const auto& used_board : used_boards) {
        if (doSegmentsIntersect(board, used_board)) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Board> boards(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> boards[i].x1 >> boards[i].y1 >> boards[i].x2 >> boards[i].y2;
    }
    std::sort(boards.begin(), boards.end());

    int max_cows = 0;
    std::vector<Board> used_boards;

    for (const auto& board : boards) {
        if (canCross(board, used_boards)) {
            ++max_cows;
            used_boards.push_back(board);
        }
    }
    std::cout << max_cows << std::endl;
}
