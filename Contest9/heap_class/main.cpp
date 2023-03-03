#include <iostream>
#include <vector>

template <class ValueType>
class Heap {
public:
    Heap() = default;

    template <class Iterator>
    Heap(Iterator begin, Iterator end) {
        Iterator iterator = begin;
        while (iterator != end) {
            insert(*iterator);
            ++iterator;
        }
    }

    Heap(std::initializer_list<ValueType> vals) {
        for (auto i : vals) {
            insert(i);
        }
    }

    Heap(const Heap<ValueType> &new_heap) {
        heap_ = new_heap.heap_;
    }

    Heap &operator=(const Heap<ValueType> &new_heap) {
        heap_ = new_heap.heap_;
        return *this;
    }

    Heap(Heap<ValueType> &&new_heap) {
        heap_ = std::move(new_heap.heap_);
    }

    Heap &operator=(Heap<ValueType> &&new_heap) {
        heap_ = std::move(new_heap.heap_);
        return *this;
    }

    ~Heap() = default;

    size_t size() const {
        return heap_.size();
    }

    bool empty() const {
        if (heap_.empty()) {
            return true;
        }
        return false;
    }

    void insert(const ValueType &num) {
        heap_.push_back(num);
        int pos = heap_.size() - 1;
        while (pos > 0 && heap_[(pos - 1) / 2] < heap_[pos]) {
            std::swap(heap_[pos], heap_[(pos - 1) / 2]);
            pos = (pos - 1) / 2;
        }
    }

    ValueType extract() {
        ValueType max_el = heap_[0];
        std::swap(heap_[0], heap_[heap_.size() - 1]);
        heap_.pop_back();
        heapify(heap_, 0, heap_.size());
        return max_el;
    }

private:
    std::vector<ValueType> heap_;

    void heapify(std::vector<int> &heap, int root, int size) {
        int curr_max = root;
        int l = 2 * root + 1;
        int r = 2 * root + 2;
        if (l < size && heap[curr_max] < heap[l]) {
            curr_max = l;
        }
        if (r < size && heap[curr_max] < heap[r]) {
            curr_max = r;
        }
        if (curr_max != root) {
            std::swap(heap[root], heap[curr_max]);
            heapify(heap, curr_max, size);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Heap<int> heap;
    int n, action, num;
    std::cin>>n;
    for (int i=0; i<n; ++i){
        std::cin>>action;
        if (action == 0){
            std::cin>>num;
            heap.insert(num);
        }
        else if (action == 1){
            std::cout<<heap.extract()<<'\n';
        }
    }
}