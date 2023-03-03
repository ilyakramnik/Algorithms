#include <iostream>
#include <list>

using std::list;

list<int> merge(const list<int> &first, const list<int> &second) {
    list<int> list3;
    auto iter1 = first.begin(), iter2 = second.begin();
    while (iter1 != first.end() && iter2 != second.end()) {
        list3.push_back(std::min(*iter1, *iter2));
        if (*iter1 <= *iter2) {
            ++iter1;
        } else {
            ++iter2;
        }

        if (iter1 == first.end()) {
            for (auto i = iter2; i != second.end(); ++i) {
                list3.push_back(*i);
            }
        } else if (iter2 == second.end()) {
            for (auto i = iter1; i != first.end(); ++i) {
                list3.push_back(*i);
            }
        }
    }
    return list3;
}

int main() {
    int size1, size2, x;
    std::cin >> size1 >> size2;
    list<int> list1, list2, list_final;
    for (int i = 0; i < size1; ++i) {
        std::cin >> x;
        list1.push_back(x);
    }
    for (int i = 0; i < size2; ++i) {
        std::cin >> x;
        list2.push_back(x);
    }
    list_final = merge(list1, list2);
    for (auto i : list_final){
        std::cout<<i<<' ';
    }
}
