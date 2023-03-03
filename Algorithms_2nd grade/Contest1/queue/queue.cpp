#include <deque>
#include <iostream>

class Deque {
public:
    void pushBack(int value) {
        queue_.push_back(value);
    }

    void pushMiddle(int value) {
        if (queue_.size() % 2 == 0) {
            queue_.emplace(queue_.begin() + (static_cast<int>(queue_.size()) / 2), value);
        } else {
            queue_.emplace(queue_.begin() + (static_cast<int>(queue_.size()) / 2) + 1, value);
        }
    }

    int popFront() {
        int first_element = queue_[0];
        queue_.erase(queue_.begin());
        return first_element;
    }

    int front() const {
        return queue_[0];
    }

    int back() const {
        return queue_[static_cast<int>(queue_.size()) - 1];
    }

    size_t size() const {
        return static_cast<int>(queue_.size());
    }

private:
    std::deque<int> queue_;
};

int main() {
    Deque road;
    road.pushBack(1);
    road.pushBack(2);
    road.pushMiddle(3);
    std::cout << road.popFront() << std::endl;
    road.pushBack(4);
    road.pushMiddle(5);
    std::cout << road.popFront() << std::endl;
    std::cout << road.popFront() << std::endl;
    std::cout << road.popFront() << std::endl;
    std::cout << road.popFront() << std::endl;
    return 0;
}
