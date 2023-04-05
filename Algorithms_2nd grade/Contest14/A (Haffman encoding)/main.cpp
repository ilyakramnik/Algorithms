// идея взята с сайта https://habr.com/ru/company/otus/blog/497566/
#include <iostream>
#include <string>
#include <queue>
#include <map>

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    ~Node() {
        delete left;
        delete right;
    }
};

void deleteTree(Node *root) {
    delete root;
}

Node *getNode(char ch, int freq, Node *left, Node *right) {
    Node *node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}

struct Comp {
    bool operator()(Node *l, Node *r) {
        return l->freq > r->freq;
    }
};

void encode(Node *root, const std::string &str, std::map<char, std::string> &huffman_code) {
    if (root == nullptr) {
        return;
    }
    if (root->ch != '\0') {
        huffman_code[root->ch] = str;
    }
    encode(root->left, str + "0", huffman_code);
    encode(root->right, str + "1", huffman_code);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::string s, coded_str;
    int sum;
    std::cin >> s;

    std::map<char, int> freq;
    for (char ch : s) {
        freq[ch]++;
    }
    std::priority_queue<Node *, std::vector<Node *>, Comp> queue;

    for (auto pair : freq) {
        queue.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (queue.size() > 1) {
        Node *left = queue.top();
        queue.pop();
        Node *right = queue.top();
        queue.pop();
        sum = left->freq + right->freq;
        queue.push(getNode('\0', sum, left, right));
    }

    std::map<char, std::string> huffman_code;
    if (freq.size() == 1) {
        encode(queue.top(), "0", huffman_code);
    } else {
        encode(queue.top(), "", huffman_code);
    }

    for (char ch : s) {
        coded_str += huffman_code[ch];
    }
    std::cout << freq.size() << " " << coded_str.size() << '\n';
    for (const auto &pair : huffman_code) {
        std::cout << pair.first << ": " << pair.second << '\n';
    }
    std::cout << coded_str;

    deleteTree(queue.top());
}
