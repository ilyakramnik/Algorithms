#include <iostream>

static int flag = 0, ans = -1;

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

    int max2() {
        if (right_->right_ != nullptr) {
            if (right_->right_->left_ == nullptr && right_->right_->right_ == nullptr) {
                if (right_->left_->left_ != nullptr && right_->left_->right_ != nullptr &&
                    flag == 0) {
                    flag = 1;
                    right_->left_->max2();
                } else {
                    if (right_->right_ != nullptr && flag == 1) {
                        right_->max2();
                    } else {
                        ans = val_;
                        return val_;
                    }
                }
            } else {
                right_->max2();
            }
        } else {
            if (left_->left_ == nullptr) {
                ans = val_;
                return val_;
            } else if (flag) {
                ans = val_;
                return val_;
            } else {
                flag = 1;
                left_->max2();
            }
        }
        return ans;
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
    std::cout << tree.max2();
}
