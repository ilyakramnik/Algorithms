#include <iostream>

static int max_len = 0;

class Tree {
public:
    Tree() {
        left_ = right_ = nullptr;
    }

    ~Tree() {
        delete left_;
        delete right_;
    };

    void insert(int value) {
        if (left_ == nullptr && right_ == nullptr) {
            val_ = value;
            left_ = new Tree;
            right_ = new Tree;
            if (len_ > max_len) {
                max_len = len_;
            }
            len_ = 1;
        } else {
            if (val_ > value) {
                left_->len_ = len_ + 1;
                left_->insert(value);
            } else if (val_ < value) {
                right_->len_ = len_ + 1;
                right_->insert(value);
            }
        }
    }

    size_t getHeight() {
        return max_len;
    }

private:
    int val_{}, len_ = 1;
    Tree *left_{};
    Tree *right_{};
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Tree tree;
    int num;
    std::cin >> num;
    while (num != 0) {
        tree.insert(num);
        std::cin >> num;
    }
    std::cout << tree.getHeight();
}
