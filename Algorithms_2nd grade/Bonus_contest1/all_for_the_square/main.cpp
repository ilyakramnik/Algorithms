#include <iostream>
#include <vector>
#include <string>

struct NewArr {
private:
    std::vector<int> vec_;

public:
    NewArr(std::vector<int> arr, int size) {
        for (int i = 0; i < size; ++i) {
            this->vec_.push_back(arr[i]);
        }
    }

    void insert(int pos, int x) {
        this->vec_.emplace(vec_.begin() + pos - 1, x);
    }

    void erase(int pos) {
        this->vec_.erase(vec_.begin() + pos - 1);
    }

    void change(int pos, int x) {
        this->vec_[pos - 1] = x;
    }

    int at(int pos) {
        return this->vec_[pos - 1];
    }

    int compute(int left, int right, char symbol, int mod) {
        --left, --right;
        if (symbol == '+') {
            if (left == right) {
                return (mod + (this->vec_[left] % mod)) % mod;
            } else {
                int_fast64_t res = 0;
                for (int i = left; i <= right; ++i) {
                    res = res + (mod + (this->vec_[i] % mod)) % mod;
                }
                return static_cast<int>((mod + (res % mod)) % mod);
            }
        } else if (symbol == '^') {
            if (left == right) {
                return this->vec_[left];
            } else {
                int res = this->vec_[left];
                for (int i = left + 1; i <= right; ++i) {
                    res = res ^ this->vec_[i];
                }
                return res;
            }
        }
        return -1;
    }

    int size() const {
        return static_cast<int>(this->vec_.size());
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> vec;
    std::string command;
    char symbol;
    int mod, n, q, num;
    std::cin >> symbol;
    if (symbol == '+') {
        std::cin >> mod;
    }
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> num;
        vec.push_back(num);
    }
    std::cin >> q;
    NewArr vec1(vec, static_cast<int>(vec.size()));
    for (int i = 0; i < q; ++i) {
        std::cin >> command;
        if (command == "insert") {
            int x, pos;
            std::cin >> pos >> x;
            vec1.insert(pos, x);
        } else if (command == "erase") {
            int pos;
            std::cin >> pos;
            vec1.erase(pos);
        } else if (command == "change") {
            int x, pos;
            std::cin >> pos >> x;
            vec1.change(pos, x);
        } else if (command == "at") {
            int pos;
            std::cin >> pos;
            std::cout << vec1.at(pos) << '\n';
        } else if (command == "compute") {
            int left, right;
            std::cin >> left >> right;
            std::cout << vec1.compute(left, right, symbol, mod) << '\n';
        } else if (command == "size") {
            std::cout << vec1.size() << '\n';
        }
    }
}