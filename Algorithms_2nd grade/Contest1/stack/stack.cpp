#include <iostream>
#include <stdexcept>
#include <vector>

class Stack {
private:
    std::vector<int> stack_;

public:
    void push(int value) {
        stack_.push_back(value);
    }

    int pop() {
        if (!stack_.empty()) {
            int end = stack_[static_cast<int>(stack_.size()) - 1];
            stack_.pop_back();
            return end;
        } else {
            throw std::invalid_argument("error");
        }
    }

    int back() {
        if (!stack_.empty()) {
            return stack_[static_cast<int>(stack_.size()) - 1];
        } else {
            throw std::invalid_argument("error");
        }
    }

    int size() {
        return static_cast<int>(stack_.size());
    }

    void clear() {
        stack_.clear();
    }
};

int main() {
    /*std::string line;
    std::ifstream in("test.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            //cout<<line<<endl;
            Stack st;
            st.push(12);
        }
    }
    in.close();*/
    Stack st;
    std::cout<<st.size()<<std::endl;
    st.push(-531);
    std::cout<<st.pop()<<std::endl;
    //std::cout<<st.back()<<std::endl;
    st.push(960);
    st.push(187);
    return 0;
}
