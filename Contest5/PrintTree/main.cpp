#include <iostream>

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
                left_->insert(value);
            } else if (val_ < value) {
                right_->insert(value);
            }
        }
    }

    void printTree() {
        if (left_ != nullptr && right_ != nullptr) {
            if (left_->left_ == nullptr && left_->right_ == nullptr && right_->left_ == nullptr &&
                right_->left_ == nullptr) {
                std::cout << val_ << '\n';
            }
            left_->printTree();
            right_->printTree();
        }
    }

private:
    int val_{};
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
    tree.printTree();
}
