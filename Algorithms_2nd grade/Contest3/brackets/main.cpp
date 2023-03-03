#include <iostream>
#include <string>
#include <stack>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string s;
    std::stack<char> stack1;
    std::cin >> s;
    if (s.empty()) {
        std::cout << "YES";
    }
    for (char& i : s) {
        if (stack1.empty()) {
            stack1.push(i);
        } else {
            if (stack1.top() == '(' && i == ')' || stack1.top() == '[' && i == ']' ||
                stack1.top() == '{' && i == '}') {
                stack1.pop();
            } else {
                stack1.push(i);
            }
        }
    }
    if (stack1.empty()) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
