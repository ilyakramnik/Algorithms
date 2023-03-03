#include <iostream>
#include <iterator>
#include <initializer_list>
#include <cstring>

class Vector {
public:
    struct Iterator {
        using IteratorCategory = std::random_access_iterator_tag;
        using DifferenceType = std::ptrdiff_t;

        explicit Iterator(int* ptr) : m_ptr_(ptr){};

        int& operator*() const {
            return *m_ptr_;
        }

        int* operator->() {
            return m_ptr_;
        }

        Iterator& operator++() {
            ++m_ptr_;
            return *this;
        }

        Iterator operator++(int) {
            return Iterator(m_ptr_++);
        }

        Iterator& operator--() {
            --m_ptr_;
            return *this;
        }

        Iterator operator--(int) {
            return Iterator(m_ptr_--);
        }

        Iterator operator+(const DifferenceType& movement) {
            return Iterator(m_ptr_ + movement);
        }

        Iterator operator-(const DifferenceType& movement) {
            return Iterator(m_ptr_ - movement);
        }

        Iterator& operator+=(const DifferenceType& movement) {
            m_ptr_ += movement;
            return *this;
        }

        Iterator& operator-=(const DifferenceType& movement) {
            m_ptr_ -= movement;
            return *this;
        }

        int* base() const {
            return m_ptr_;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) {
            return a.base() == b.base();
        }

        friend bool operator!=(const Iterator& a, const Iterator& b) {
            return a.base() != b.base();
        }

        friend bool operator<(const Iterator& a, const Iterator& b) {
            return a.base() < b.base();
        }

        friend bool operator>(const Iterator& a, const Iterator& b) {
            return a.base() > b.base();
        }

        friend bool operator<=(const Iterator& a, const Iterator& b) {
            return a.base() <= b.base();
        }

        friend bool operator>=(const Iterator& a, const Iterator& b) {
            return a.base() > b.base();
        }

        friend bool operator-(const Iterator& a, const Iterator& b) {
            return a.base() - b.base();
        }

    private:
        int* m_ptr_;
    };

    Vector() {
        arr_ = new int[capacity_];
    }

    explicit Vector(size_t n_size) {
        size_ = n_size;
        capacity_ = size_ * 2;
        arr_ = new int[capacity_];
    }

    Vector(const int* vals, size_t size) {
        size_ = size;
        capacity_ = size_ * 2;
        arr_ = new int[capacity_];
        std::memcpy(arr_, vals, size_ * sizeof(int));
    }

    Vector(const Vector& vec) {
        size_ = vec.size_;
        capacity_ = size_ * 2;
        arr_ = new int[capacity_];
        for (int i = 0; i < static_cast<int>(size_); ++i) {
            arr_[i] = vec.arr_[i];
        }
    }

    Vector(std::initializer_list<int> vals) {
        capacity_ = vals.size() * 2;
        arr_ = new int[capacity_];
        for (auto i : vals) {
            pushBack(i);
        }
    }

    ~Vector() {
        delete[] arr_;
    }

    size_t getSize() const {
        return size_;
    }

    size_t getCapacity() const {
        return capacity_;
    }

    bool isEmpty() const {
        return size_ == 0;
    }

    void resize(size_t n_size) {
        if (n_size >= capacity_) {
            capacity_ = n_size * 2;
            int* buf = new int[capacity_];
            std::memcpy(buf, arr_, size_ * sizeof(int));
            delete[] arr_;
            arr_ = buf;
        }
        if (n_size > size_) {
            for (size_t i = size_; i < n_size; ++i) {
                arr_[i] = 0;
            }
        }
        size_ = n_size;
    }

    void pushBack(int value) {
        if (size_ == capacity_) {
            capacity_ *= 2;
            int* buf = new int[capacity_];
            std::memcpy(buf, arr_, size_ * sizeof(int));
            delete[] arr_;
            arr_ = buf;
        }
        arr_[size_++] = value;
    }

    void popBack() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        --size_;
    }

    void clear() {
        size_ = 0;
    }

    void insert(size_t pos, int value) {
        if (pos > size_) {
            throw std::runtime_error("Wrong Position!");
        }
        if (size_ == capacity_) {
            capacity_ *= 2;
            int* buf = new int[capacity_];
            std::memcpy(buf, arr_, size_ * sizeof(int));
            delete[] arr_;
            arr_ = buf;
        }
        for (int i = static_cast<int>(size_) - 1; i >= static_cast<int>(pos); --i) {
            arr_[i + 1] = arr_[i];
        }
        arr_[pos] = value;
        ++size_;
    }

    void erase(size_t pos) {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        if (pos >= size_) {
            throw std::runtime_error("Wrong Position!");
        }
        for (int i = static_cast<int>(pos); i < static_cast<int>(size_) - 1; ++i) {
            arr_[i] = arr_[i + 1];
        }
        --size_;
    }

    int at(size_t pos) {
        if (pos >= size_) {
            throw std::runtime_error("Wrong Position!");
        }
        return arr_[pos];
    }

    int front() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        return arr_[0];
    }

    int back() {
        if (size_ == 0) {
            throw std::runtime_error("Empty Array!");
        }
        return arr_[size_ - 1];
    }

    Iterator begin() {
        return Iterator(arr_);
    }

    Iterator end() {
        return Iterator(arr_ + size_);
    }

    int& operator[](size_t pos) const {
        if (pos >= size_) {
            throw std::runtime_error("Wrong Position!");
        }
        return arr_[pos];
    }

    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this;
        }

        if (size_ != other.size_) {
            delete[] arr_;
            arr_ = nullptr;
            size_ = 0;
            arr_ = new int[other.size_];
            size_ = other.size_;
        }

        std::copy(other.arr_, other.arr_ + other.size_, arr_);
        return *this;
    }

private:
    size_t size_ = 0;
    size_t capacity_ = 10;
    int* arr_{};
};

void merge(Vector::Iterator begin, Vector::Iterator middle, Vector::Iterator end, int len) {
    Vector final(len);
    int size_final = 0;
    Vector::Iterator iter_begin = begin, iter_middle = middle;
    while (iter_begin < middle && iter_middle < end) {
        final[size_final++] = std::min(*iter_begin, *iter_middle);
        if (*iter_begin <= *iter_middle) {
            ++iter_begin;
        } else {
            ++iter_middle;
        }

        if (iter_begin == middle) {
            for (auto i = iter_middle; i != end; ++i) {
                final[size_final++] = *i;
            }
        } else if (iter_middle == end) {
            for (auto i = iter_begin; i != middle; ++i) {
                final[size_final++] = *i;
            }
        }
    }

    for (int i = 0; i < size_final; ++i) {
        *begin = final[i];
        ++begin;
    }
}

void mergeSort(Vector::Iterator begin, Vector::Iterator end) {
    int len = 0;
    for (auto i = begin; i != end; ++i) {
        ++len;
    }
    if (len == 1) {
        return;
    }
    Vector::Iterator middle = begin + len / 2;
    mergeSort(begin, middle);
    mergeSort(middle, end);
    merge(begin, middle, end, len);
}

void insertionSort(Vector::Iterator begin, Vector::Iterator end) {
    for (auto i = begin + 1; i != end; ++i) {
        for (auto j = i; j != begin; --j) {
            if (*(j - 1) > *j) {
                std::swap(*j, *(j - 1));
            } else {
                break;
            }
        }
    }
}

int main() {
    Vector vector = {1, 2, 3, 4, 5};
    Vector vector1 = {8, 7, 6, 5, 4, 3, 2, 1, 2, 4, 6, 2, 5, 3, 9, 11, 15};
    vector.popBack();
    vector.erase(3);
    insertionSort(vector1.begin(), vector1.end());
    for (int i = 0; i < vector1.getSize(); ++i) {
        std::cout << vector1[i] << '\n';
    }
}
