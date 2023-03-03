#include <iostream>
#include <stack>

class Queue {
public:
    void push(int value) {
        if (stack1_.empty()) {
            stack1_.push({value, value});
        } else {
            stack1_.push({value, std::min(value, stack1_.top().min)});
        }
    }

    int pop() {
        if (stack2_.empty()) {
            while (!(stack1_.empty())) {
                if (stack2_.empty()) {
                    stack2_.push({stack1_.top().curr, stack1_.top().curr});
                } else {
                    stack2_.push(
                        {stack1_.top().curr, std::min(stack1_.top().curr, stack2_.top().min)});
                }
                stack1_.pop();
            }
        }
        int first_el = stack2_.top().curr;
        stack2_.pop();
        return first_el;
    }

    int min() {
        if (!stack1_.empty() && !stack2_.empty()) {
            return std::min(stack1_.top().min, stack2_.top().min);
        } else if (stack1_.empty()) {
            return stack2_.top().min;
        } else if (stack2_.empty()) {
            return stack1_.top().min;
        }
        return -1;
    }

private:
    struct Pairs {
        int curr;
        int min;
    };
    std::stack<Pairs> stack1_;
    std::stack<Pairs> stack2_;
};

int main() {
    Queue queue;
    queue.push(1);
    queue.push(5);
    queue.push(6);
    std::cout << queue.min() << std::endl;
    queue.pop();
    std::cout << queue.min() << std::endl;
    queue.pop();
    std::cout << queue.min() << std::endl;
    return 0;
}
