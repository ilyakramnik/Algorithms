#include <iostream>
#include <stack>
#include <list>
#include <functional>
#include <cassert>
#include <utility>
#include <set>

enum class Color : bool { RED, BLACK };

template <typename ValueType>
class Node {
public:
    Node(Node *parent, Node *left, Node *right, const ValueType &value, Color color = Color::RED)
        : parent(parent), left(left), right(right), color(color), value(value) {
    }

    Node *parent;
    Node *left;
    Node *right;
    Color color;

    ValueType value;
};

template <typename ValueType>
constexpr bool operator==(const ValueType &first, const ValueType &second) {
    return first == second;
}

template <typename ValueType>
class RBTree {
private:
    Node<ValueType> *begin_;

public:
    Node<ValueType> *root;

    class Iterator {
    private:
        Node<ValueType> *ptr_;

    public:
        Iterator() : ptr_(nullptr) {
        }

        explicit Iterator(Node<ValueType> *node) : ptr_(node) {
        }

        const ValueType &operator*() const {
            return ptr_->value;
        }

        const ValueType *operator->() const {
            return &ptr_->value;
        }

        Iterator &operator++() {
            assert(ptr_ != nullptr);
            if (ptr_->right == nullptr) {
                if (ptr_->parent != nullptr && ptr_->parent->left == ptr_) {
                    ptr_ = ptr_->parent;
                } else {
                    while (ptr_->parent != nullptr) {
                        if (ptr_->parent->left == ptr_) {
                            break;
                        }
                        ptr_ = ptr_->parent;
                    }
                    ptr_ = ptr_->parent;
                }
            } else {
                ptr_ = ptr_->right;
                while (ptr_->left != nullptr) {
                    ptr_ = ptr_->left;
                }
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator temporary(*this);
            ++(*this);
            return temporary;
        }

        Iterator &operator--() {
            if (ptr_->left == nullptr) {
                if (ptr_->parent != nullptr && ptr_->parent->right == ptr_) {
                    ptr_ = ptr_->parent;
                } else {
                    while (ptr_->parent != nullptr) {
                        if (ptr_->parent->right == ptr_) {
                            break;
                        }
                        ptr_ = ptr_->parent;
                    }
                    ptr_ = ptr_->parent;
                }
            } else {
                ptr_ = ptr_->left;
                while (ptr_->right != nullptr) {
                    ptr_ = ptr_->right;
                }
            }
            return *this;
        }

        Iterator operator--(int) {
            Iterator temporary(*this);
            --(*this);
            return temporary;
        }

        bool operator==(const Iterator &other) const {
            return ptr_ == other.ptr_;
        }

        bool operator!=(const Iterator &other) const {
            return ptr_ != other.ptr_;
        }
    };

private:
    size_t size_;

    Node<ValueType> *grandparent(Node<ValueType> *n) const {
        if (n != nullptr && n->parent != nullptr) {
            return n->parent->parent;
        } else {
            return nullptr;
        }
    }

    Node<ValueType> *uncle(Node<ValueType> *n) const {
        Node<ValueType> *g = grandparent(n);
        if (g == nullptr) {
            return nullptr;
        }
        if (n->parent == g->left) {
            return g->right;
        } else {
            return g->left;
        }
    }

    void rotateLeft(Node<ValueType> *n) {
        Node<ValueType> *pivot = n->right;

        pivot->parent = n->parent;
        if (n->parent != nullptr) {
            if (n->parent->left == n) {
                n->parent->left = pivot;
            } else {
                n->parent->right = pivot;
            }
        }

        n->right = pivot->left;
        if (pivot->left != nullptr) {
            pivot->left->parent = n;
        }

        n->parent = pivot;
        pivot->left = n;

        if (pivot->parent == nullptr) {
            root = pivot;
        }
    }

    void rotateRight(Node<ValueType> *n) {
        Node<ValueType> *pivot = n->left;

        pivot->parent = n->parent;
        if (n->parent != nullptr) {
            if (n->parent->left == n) {
                n->parent->left = pivot;
            } else {
                n->parent->right = pivot;
            }
        }

        n->left = pivot->right;
        if (pivot->right != nullptr) {
            pivot->right->parent = n;
        }

        n->parent = pivot;
        pivot->right = n;

        if (pivot->parent == nullptr) {
            root = pivot;
        }
    }

    // INSERT SECTION /////////////////////////////////////////
    void properInsert(Node<ValueType> *n) {
        if (n->parent == nullptr) {
            n->color = Color::BLACK;
        } else {
            insertCaseBlackP(n);
        }
    }

    void insertCaseBlackP(Node<ValueType> *n) {
        if (n->parent->color == Color::BLACK) {
            return;
        } else {
            insertCaseRedPRedU(n);
        }
    }

    void insertCaseRedPRedU(Node<ValueType> *n) {
        Node<ValueType> *u = uncle(n);
        Node<ValueType> *g = grandparent(n);

        if (u != nullptr && u->color == Color::RED) {
            n->parent->color = Color::BLACK;
            u->color = Color::BLACK;
            g->color = Color::RED;
            properInsert(g);
        } else {
            insertCaseBlackURightN(n);
        }
    }

    void insertCaseBlackURightN(Node<ValueType> *n) {
        Node<ValueType> *g = grandparent(n);

        if (n == n->parent->right && n->parent == g->left) {
            rotateLeft(n->parent);
            n = n->left;
        } else if (n == n->parent->left && n->parent == g->right) {
            rotateRight(n->parent);
            n = n->right;
        }
        insertCaseBlackULeftN(n);
    }

    void insertCaseBlackULeftN(Node<ValueType> *n) {
        Node<ValueType> *g = grandparent(n);

        n->parent->color = Color::BLACK;
        g->color = Color::RED;
        if ((n == n->parent->left) && (n->parent == g->left)) {
            rotateRight(g);
        } else {
            rotateLeft(g);
        }
    }

    // DELETION SECTION ///////////////////////////////////////
    void deleteCase11(Node<ValueType> *b) {
        Node<ValueType> *a = b->parent;
        Node<ValueType> *c = b->right;

        // have to place C between B and A, then rotate
        if (c != nullptr) {
            b->right = nullptr;
            c->parent = a;
            a->left = c;
            b->parent = c;
            c->left = b;
        }

        rotateRight(a);

        a->color = Color::BLACK;
    }

    void deleteCase12(Node<ValueType> *b) {
        b->parent->color = Color::BLACK;
        b->color = Color::RED;
    }

    void deleteCase211(Node<ValueType> *b) {
        Node<ValueType> *a = b->parent;
        Node<ValueType> *c = b->right;
        Node<ValueType> *d1 = c->left;
        Node<ValueType> *d2 = c->right;

        c->parent = a;
        c->left = b;
        c->right = nullptr;
        a->left = c;
        b->parent = c;
        b->right = d1;
        if (d1 != nullptr) {
            d1->right = d2;
            d1->parent = b;
        }
        if (d2 != nullptr) {
            d2->parent = d1;
        }

        rotateRight(a);

        d1->color = Color::RED;
    }

    void deleteCase212(Node<ValueType> *b) {
        Node<ValueType> *a = b->parent;
        Node<ValueType> *c = b->right;
        rotateRight(a);

        b->color = Color::BLACK;
        c->color = Color::RED;
    }

    void deleteCase221(Node<ValueType> *b) {
        Node<ValueType> *a = b->parent;
        Node<ValueType> *c = b->right;

        // have to place C between B and A, then rotate
        if (c != nullptr) {
            b->right = nullptr;
            c->parent = a;
            a->left = c;
            b->parent = c;
            c->left = b;
        }

        rotateRight(a);

        c->color = Color::BLACK;
    }

    void deleteCase222(Node<ValueType> *b) {
        b->color = Color::RED;
    }

    void balanceAfterDeletion(Node<ValueType> *brother) {
        // case 1
        if (brother->parent->color == Color::RED) {
            if (brother->left != nullptr || brother->right != nullptr) {
                deleteCase11(brother);  // case 1.1
            } else {
                deleteCase12(brother);  // case 1.2
            }
        }
        // case 2
        else {
            // case 2.1
            if (brother->color == Color::RED) {
                Node<ValueType> *nephew = brother->right;
                if (nephew->left != nullptr || nephew->right != nullptr) {
                    deleteCase211(brother);  // case 2.1.1
                } else {
                    deleteCase212(brother);  // case 2.1.2
                }
            }
            // case 2.2
            else {
                if (brother->left != nullptr || brother->right != nullptr) {
                    deleteCase221(brother);  // case 2.2.1
                } else {
                    deleteCase222(brother);  // case 2.2.2
                }
            }
        }
    }

    void properDelete(Node<ValueType> *condemned) {
        if (condemned->left == nullptr && condemned->right == nullptr &&
            condemned->color == Color::RED) {
            if (condemned->parent->right == condemned) {
                condemned->parent->right = nullptr;
            } else {
                condemned->parent->left = nullptr;
            }
            delete condemned;
        } else if (condemned->left != nullptr && condemned->right == nullptr &&
                   condemned->color == Color::BLACK) {
            condemned->left->color = Color::BLACK;
            condemned->left->parent = condemned->parent;
            if (condemned->parent->right == condemned) {
                condemned->parent->right = condemned->left;
            } else {
                condemned->parent->left = condemned->left;
            }
            delete condemned;
        } else {
            Node<ValueType> *brother = nullptr;
            if (condemned->parent->right == condemned) {
                brother = condemned->parent->left;
                condemned->parent->right = nullptr;
            } else {
                brother = condemned->parent->right;
                condemned->parent->left = nullptr;
            }
            delete condemned;
            balanceAfterDeletion(brother);
        }
    }

    // OTHER METHODS //////////////////////////////////////////
    void iterativeDisposal() {
        if (size_ == 0) {
            return;
        }
        Node<ValueType> *cur = root;
        std::stack<Node<ValueType> *> path;
        while (!path.empty() || cur != nullptr) {
            if (cur != nullptr) {
                path.push(cur);
                cur = cur->left;
            } else {
                cur = path.top();
                path.pop();
                Node<ValueType> *tmp = cur->right;
                delete cur;
                cur = tmp;
            }
        }
    }

    void deepCopy(Node<ValueType> *new_root, Node<ValueType> *old_root) {
        std::list<Node<ValueType> *> qother;
        qother.push_back(old_root);

        std::list<Node<ValueType> *> qthis;
        qthis.push_back(new_root);

        while (!qother.empty()) {
            auto &curthis = qthis.front();
            auto &curother = qother.front();
            if (curother->left != nullptr) {
                curthis->left = new Node<ValueType>(curthis, nullptr, nullptr,
                                                    curother->left->value, curother->left->color);
                qother.push_back(curother->left);
                qthis.push_back(curthis->left);
            }
            if (curother->right != nullptr) {
                curthis->right = new Node<ValueType>(
                    curthis, nullptr, nullptr, curother->right->value, curother->right->color);
                qother.push_back(curother->right);
                qthis.push_back(curthis->right);
            }

            qother.pop_front();
            qthis.pop_front();
        }
    }

public:
    RBTree() : root(nullptr), size_(0) {
    }

    RBTree(const RBTree &other)
        : size_(other.size_),
          root(new Node<ValueType>(nullptr, nullptr, nullptr, other.root->value,
                                   other.root->color)) {
        deepCopy(root, other.root);
    }

    RBTree(std::initializer_list<ValueType> list) : size_(0) {
        for (auto &el : list) {
            insert(el);
        }
    }

    ~RBTree() {
        iterativeDisposal();
    }

    RBTree<ValueType> &operator=(const RBTree<ValueType> &other) {
        if (this == &other) {
            return *this;
        }

        if (size_ != 0) {
            iterativeDisposal();
        }

        size_ = other.size_;
        root = new Node<ValueType>(nullptr, nullptr, nullptr, other.root->value, other.root->color);

        deepCopy(root, other.root);

        return *this;
    }

    void insert(const ValueType &val) {
        if (size_ == 0) {
            root = new Node<ValueType>(nullptr, nullptr, nullptr, val);
            begin_ = root;
            properInsert(root);
            size_++;
            return;
        }

        auto cmp = std::less<>();
        bool beg = true;

        Node<ValueType> *cur = root;
        while (cur != nullptr) {
            if (val == cur->value) {
                return;
            }

            if (cmp(val, cur->value)) {
                if (cur->left != nullptr) {
                    cur = cur->left;
                } else {
                    cur->left = new Node<ValueType>(cur, nullptr, nullptr, val);
                    properInsert(cur->left);
                    size_++;
                    break;
                }
            } else {
                beg = false;
                if (cur->right != nullptr) {
                    cur = cur->right;
                } else {
                    cur->right = new Node<ValueType>(cur, nullptr, nullptr, val);
                    properInsert(cur->right);
                    size_++;
                    break;
                }
            }
        }

        if (beg) {
            begin_ = cur->left;
        }
    }

    void erase(const ValueType &val) {
        Node<ValueType> *eluded = root;
        auto cmp = std::less<>();

        while (eluded != nullptr) {
            if (val == eluded->value) {
                break;
            } else if (cmp(val, eluded->value)) {
                eluded = eluded->left;
            } else {
                eluded = eluded->right;
            }
        }

        if (eluded == nullptr) {
            return;
        }

        if (eluded == begin_) {
            begin_ = begin_->parent;
        }

        Node<ValueType> *condemned = eluded;
        if (eluded->left != nullptr) {
            condemned = eluded->left;
            while (condemned->right != nullptr) {
                condemned = condemned->right;
            }
            std::swap(condemned->value, eluded->value);
        } else if (eluded->right != nullptr) {
            condemned = eluded->right;
            while (condemned->left != nullptr) {
                condemned = condemned->left;
            }
            std::swap(condemned->value, eluded->value);
        }

        properDelete(condemned);
        --size_;
    }

    Iterator lowerBound(const ValueType &val) const {
        if (size_ == 0) {
            return Iterator();
        }

        Node<ValueType> *left = root;
        Node<ValueType> *right = root;
        Node<ValueType> *res = root;

        auto cmp = std::less<>();

        while (left != nullptr) {
            if (val == left->value) {
                res = left;
                break;
            }

            if (cmp(val, left->value)) {
                if (left->left != nullptr) {
                    right = left;
                    left = left->left;
                } else {
                    res = left;
                    break;
                }
            } else {
                if (left->right != nullptr) {
                    left = left->right;
                } else {
                    res = right;
                    break;
                }
            }
        }

        return Iterator(res);
    }

    Iterator find(const ValueType &val) const {
        auto finder = lowerBound(val);
        if (val == *finder) {
            return finder;
        }
        return Iterator();
    }

    size_t size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

    Iterator begin() const {
        return Iterator(begin_);
    }

    Iterator end() const {
        return Iterator();
    }
};

template <typename T>
void printTree(const Node<T> *node, int level) {
    if (node) {
        printTree(node->right, level + 1);
        for (int i = 0; i < level; ++i) {
            std::cout << '\t';
        }
        if (node->parent) {
            std::cout << node->parent->value << ':';
        }
        std::cout << node->value << ':';
        if (node->color == Color::BLACK) {
            std::cout << "B\n";
        }
        if (node->color == Color::RED) {
            std::cout << "R\n";
        }
        printTree(node->left, level + 1);
    }
}

int main() {

    for (int i = 0; i < 1000; ++i) {
        RBTree<int> tree;
        std::set<int> s;

        for (int j = 0; j < 20; ++j) {
            int r = rand() % 100 + 1;

            tree.insert(r);
            printTree(tree.root, 0);
            std::cout << "_______________________________\n";
            std::cout << r << ' ';
            s.insert(r);

            if (tree.size() != s.size()) {
                std::cout << "SIZE\n";
                return 0;
            }

            RBTree<int>::Iterator it = tree.begin();
            std::set<int>::iterator its = s.begin();
            std::cout << "insert " << i << j << ": ";
            while (it != tree.end()) {
                if (*it != *its) {
                    std::cout << "ITERATOR\n";
                    return 0;
                }
                std::cout << *it << ' ';
                ++it, ++its;
            }
            std::cout << "\n";
        }

        for (int j = 0; j < 100; ++j) {
            int r = rand() % 100 + 1;
            if (j == 16) {
                int y = 0;
                ++y;
                --y;
            }
            printTree(tree.root, 0);
            std::cout << "_______________________________\n";
            std::cout << r << ' ';
            tree.erase(r);
            s.erase(r);
            std::cout << tree.size() << ' ' << s.size() << ' ';

            if (tree.size() != s.size()) {
                std::cout << "SIZE\n";
                return 0;
            }

            std::cout << "erase " << i << j << ": ";
            RBTree<int>::Iterator it = tree.begin();
            std::set<int>::iterator its = s.begin();
            while (it != tree.end()) {
                if (*it != *its) {
                    std::cout << "ERASE\n";
                    return 0;
                }
                std::cout << *it << ' ';
                ++it, ++its;
            }
            std::cout << "\n";
        }
    }

    return 0;
}