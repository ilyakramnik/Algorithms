#include <iostream>
#include <algorithm>

static int max_len_avl = 0;
static int is_balanced_final = 1;

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

    void treeGo() {
        if (left_ != nullptr && right_ != nullptr) {
            left_->treeGo();
            if (len_ > max_len_avl) {
                max_len_avl = len_;
            }
            right_->treeGo();
        }
    }

    void isBalanced() {
        if (left_ != nullptr && right_ != nullptr) {
            left_->isBalanced();
            {
                int left_len, right_len;
                left_->treeGo();
                left_len = std::max(len_, max_len_avl);
                max_len_avl = 0;
                right_->treeGo();
                right_len = std::max(len_, max_len_avl);
                max_len_avl = 0;
                if (abs(left_len - right_len) > 1) {
                    is_balanced_final = 0;
                    return;
                }
            }
            right_->isBalanced();
        }
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
    tree.isBalanced();
    std::cout << ((is_balanced_final == 1) ? "YES" : "NO");
}
