// идея взята с сайта https://e-maxx.ru/algo/maximum_average_segment
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x, sum = 0, max_start = 0, max_end = 0, max_sum = 0, start = -1, max_num = -300001,
              max_ind;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        if (x > max_num) {
            max_num = x;
            max_ind = i;
        }
        arr[i] = x;
    }
    for (int i = 0; i < n; ++i) {
        if ((sum + arr[i]) > max_sum) {
            max_sum = sum + arr[i];
            max_end = i;
            max_start = start + 1;
        }
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            start = i;
        }
    }
    if (max_sum == 0) {
        max_start = max_ind;
        max_end = max_ind;
    }
    std::cout << max_start << " " << max_end;
    delete[] arr;
}