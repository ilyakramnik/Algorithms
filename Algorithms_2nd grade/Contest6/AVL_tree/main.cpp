//идея взята с сайта https://habr.com/ru/post/150732/
#include <iostream>

struct Node {
    Node(int val) {
        left = right = nullptr;
        value = val;
        height = 1;
    }

    int height{};
    Node* left;
    Node* right;
    int value{};
};

class AVLTree {
public:
    AVLTree() {
        root_ = nullptr;
    }

    void insert(int value) {
        root_ = insert2(root_, value);
    }

    Node* insert2(Node* node, int value) {
        if (node == nullptr) {
            ++size_;
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert2(node->left, value);
        } else if (value > node->value) {
            node->right = insert2(node->right, value);
        } else {
            return node;
        }
        node = balanceTree(node);
        return node;
    }

    void erase(int value) {
        if (findNode(root_, value) != nullptr) {  //нашли выбранный элемент
            --size_;
            root_ = erase2(root_, value);
        }
    }

    Node* erase2(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->value) {
            node->left = erase2(node->left, value);
        } else if (value > node->value) {
            node->right = erase2(node->right, value);
        }

        else {
            Node* left_child = node->left;
            Node* right_child = node->right;
            if (left_child == nullptr && right_child == nullptr) {
                delete node;
                node = nullptr;
            } else if (left_child == nullptr) {
                node = right_child;
                delete node->right;
                node->right = nullptr;
            } else if (right_child == nullptr) {
                node = left_child;
                delete node->left;
                node->left = nullptr;
            } else {
                Node* left_max = findMaxNode(left_child);
                node->value = left_max->value;
                node->left = erase2(node->left, left_max->value);
            }
        }
        if (node == nullptr) {
            return node;
        }
        return balanceTree(node);
    }

    int* find(int value) {
        if (findNode(root_, value) == nullptr) {
            return nullptr;
        }
        return &(findNode(root_, value)->value);
    }

    Node* findNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->value) {
            return findNode(node->left, value);
        } else if (value > node->value) {
            return findNode(node->right, value);
        }
        return node;
    }

    Node* findMaxNode(Node* node) {
        if (node->right == nullptr) {
            return node;
        }
        return findMaxNode(node->right);
    }

    Node* balanceTree(Node* node) {
        changeHeight(node);
        if (balanceCheck(node) == 2) {
            if (balanceCheck(node->right) > 0) {
                node = leftRotation(node);
            } else {
                node->right = rightRotation(node->right);
                node = leftRotation(node);
            }
        } else if (balanceCheck(node) == -2) {
            if (balanceCheck(node->left) < 0) {
                node = rightRotation(node);
            } else {
                node->left = leftRotation(node->left);
                node = rightRotation(node);
            }
        }
        return node;
    }

    Node* leftRotation(Node* node) {
        Node* p = node->right;
        node->right = p->left;
        p->left = node;
        changeHeight(node);
        changeHeight(p);
        return p;
    }

    Node* rightRotation(Node* node) {
        Node* p = node->left;
        node->left = p->right;
        p->right = node;
        changeHeight(node);
        changeHeight(p);
        return p;
    }

    void changeHeight(Node* node) {
        int left_height = height(node->left);
        int right_height = height(node->right);
        if (left_height > right_height) {
            node->height = left_height + 1;
        } else {
            node->height = right_height + 1;
        }
    }

    int height(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int balanceCheck(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return height(node->right) - height(node->left);
    }

    int* lowerBound(int value) {
        Node* x = findNode(root_, value);
        if (x == nullptr) {
            if (findLowerBound(root_, value) == nullptr) {
                return nullptr;
            } else {
                return &(findLowerBound(root_, value)->value);
            }
        }
        return &(x->value);
    }

    Node* findLowerBound(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->value) {
            if (node->left == nullptr ||
                (node->left->value < value && node->left->right == nullptr)) {
                return node;
            }
            return findLowerBound(node->left, value);
        } else if (value > node->value) {
            return findLowerBound(node->right, value);
        }
        return node;
    }

    bool empty() {
        if (root_ == nullptr) {
            return true;
        }
        return false;
    }

    int getSize() {
        return size_;
    }

    int* traversal() {
        int* arr = new int[size_];
        return traversal2(root_, arr);
    }

    int* traversal2(Node* node, int* arr) {
        if (node != nullptr) {
            traversal2(node->left, arr);
            arr[arr_size_++] = node->value;
            traversal2(node->right, arr);
        }
        return arr;
    }

    Node* getRoot() {
        return root_;
    }

    int getHeight() {
        return root_->height;
    }

    void deleteTree(Node* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    ~AVLTree() {
        deleteTree(root_);
    };

private:
    int size_ = 0;
    int arr_size_ = 0;
    Node* root_;
};

/*int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    for (int i = 0; i < 1000; ++i) {
        AVLTree tree;

        for (int j = 0; j < 10000; ++j) {
            int r = (rand() % 1000) + 1;
            if (r == 43) {
                // std::cout << "ok1";
            }
            tree.insert(r);
        }

        for (int j = 0; j < 100000; ++j) {
            int r = (rand() % 1000) + 1;
            if (tree.getSize() == 39) {
                // std::cout << "ok2";
            }
            tree.erase(r);
        }
    }
}*/

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    AVLTree tree;
    int num;
    std::cin >> num;
    while (num != 0) {
        tree.insert(num);
        std::cin >> num;
    }
    int* x = tree.traversal();
    for (int i = 0; i < tree.getSize(); ++i) {
        std::cout << x[i];
    }
    std::cout << "ok";
}
