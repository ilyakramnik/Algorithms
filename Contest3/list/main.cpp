#include <iostream>

class Node {
public:
    Node *next;
    int data{};
    Node *previous;
    Node() {
        next = previous = nullptr;
    };

    explicit Node(int val) {
        data = val;
        next = previous = nullptr;
    };
};

class List {
public:
    List() {
        head = tail = nullptr;
    }

    List(int *values, size_t size) {
        for (int i = 0; i < static_cast<int>(size); ++i) {
            if (values[i] < -2000000000 || values[i] > 2000000000) {
                throw std::runtime_error("Wrong Value!");
            }
        }
        for (int i = 0; i < static_cast<int>(size); ++i) {
            pushBack(values[i]);
        }
    }

    ~List() {
        Node *current = head;
        while (current != tail) {
            head = head->next;
            delete current;
            current = head;
        }
        delete current;
    };

    void pushBack(int value) {
        if (value < -2000000000 || value > 2000000000) {
            throw std::runtime_error("Wrong Value!");
        }
        Node *node = new Node(value);
        if (head == nullptr) {
            head = tail = node;
            head->previous = tail;
            tail->next = head;
        } else {
            tail->next = node;
            node->previous = tail;
            tail = node;
            head->previous = tail;
            tail->next = head;
        }
    }

    void pushFront(int value) {
        if (value < -2000000000 || value > 2000000000) {
            throw std::runtime_error("Wrong Value!");
        }
        Node *node = new Node(value);
        if (head == nullptr) {
            head = tail = node;
            head->previous = tail;
            tail->next = head;
        } else {
            node->next = head;
            node->next->previous = node;
            head = node;
            head->previous = tail;
            tail->next = head;
        }
    }

    void push(int value, size_t position) {
        if (value < -2000000000 || value > 2000000000) {
            throw std::runtime_error("Wrong Value!");
        }
        if (head == nullptr) {  //добавление в пустой массив
            throw std::runtime_error("Wrong Position!");
        }
        Node *node = new Node(value), *current = head;
        while (position > 0) {
            if (current->next == head) {  //выход за границу листа
                delete node;
                throw std::runtime_error("Wrong Position!");
            }
            current = current->next;
            --position;
        }
        if (current->next == head) {  //если добавляем в конец листа
            tail = node;
            tail->previous = current;
            current->next = tail;
            head->previous = tail;
            tail->next = head;
        } else {
            node->next = current->next;
            current->next = node;
            node->next->previous = node;
            node->previous = current;
        }
    }

    int pop() {
        if (head == nullptr) {
            throw std::runtime_error("Can not pop such element!");
        } else {
            Node *ptr = head;
            int res = ptr->data;
            if (ptr->next == head) {
                head = tail = nullptr;
            } else {
                head = ptr->next;
                if (head->next == ptr) {
                    head = tail;
                }
                head->previous = tail;
                tail->next = head;
            }
            delete ptr;
            return res;
        }
    }

    int pop(size_t position) {
        if (head == nullptr || head == tail) {  //удаление из списка длины 0 и 1
            throw std::runtime_error("Wrong Position!");
        }

        Node *ptr = head;

        if (ptr->next == tail) {  //если всего 2 элемента
            if (position != 0) {
                throw std::runtime_error("Wrong Position!");
            }
            ptr = ptr->next;
            int res = ptr->data;
            tail = head;
            head->previous = tail;
            tail->next = head;
            delete ptr;
            return res;
        }

        while (position > 0) {
            if (ptr->next == tail) {  //выход за границу листа
                throw std::runtime_error("Wrong Position!");
            }
            ptr = ptr->next;
            --position;
        }
        ptr = ptr->next;

        int res = ptr->data;

        if (ptr == tail) {  //если удаляем tail
            tail = tail->previous;
            tail->next = head;
            head->previous = tail;
            delete ptr;
            return res;
        }
        ptr->previous->next = ptr->next;
        ptr->next->previous = ptr->previous;
        delete ptr;
        return res;
    }

    Node *head{};
    Node *tail{};
};

int main() {
    int arr[] = {1, 200000000, 3, 4, 5, 6, 7, 8, 9, 10};
    List list(arr, 1);
}
