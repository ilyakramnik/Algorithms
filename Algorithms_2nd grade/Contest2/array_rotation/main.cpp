#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, tmp, dist, dist_max = 0, fl = 0, is_eq;
    std::cin >> n;
    int arr[n], arr_new[n], arr_unique[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        arr_new[i] = arr[i];
    }
    for (int i = 1; i < n + 1;
         ++i) {  // all possible rotations. Start i with 1 because now it will show true HemingDist
        tmp = arr_new[n - 1];
        for (int j = n - 2; j >= 0; --j) {
            arr_new[j + 1] = arr_new[j];
        }
        arr_new[0] = tmp;
        /*for (int j=0; j<n; ++j){
            std::cout<<arr_new[j]<< ' ';
        }
        std::cout<<'\n';*/
        dist = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j] != arr_new[j]) {
                ++dist;
            }
        }
        if (dist > dist_max) {
            dist_max = dist;
        }
    }

    std::cout << dist_max << '\n';
    if (dist_max == 0) {
        for (int j = 0; j < n; ++j) {
            if (j != n - 1) {
                std::cout << arr[j] << ' ';
            } else {
                std::cout << arr[j];
            }
        }
        std::cout << "; "
                  << "0" << '\n';
    } else {
        for (int i = 1; i < n + 1; ++i) {
            tmp = arr_new[n - 1];
            for (int j = n - 2; j >= 0; --j) {
                arr_new[j + 1] = arr_new[j];
            }
            arr_new[0] = tmp;
            dist = 0;
            for (int j = 0; j < n; ++j) {
                if (arr[j] != arr_new[j]) {
                    ++dist;
                }
            }
            if (dist == dist_max) {
                is_eq = 0;
                if (fl) {
                    for (int j = 0; j < n; ++j) {
                        if (arr_unique[j] == arr_new[j]) {
                            ++is_eq;
                        }
                    }
                }

                if (is_eq != n) {
                    for (int j = 0; j < n; ++j) {
                        if (j != n - 1) {
                            std::cout << arr_new[j] << ' ';
                        } else {
                            std::cout << arr_new[j];
                        }
                    }
                    std::cout << "; " << i << '\n';
                }

                if (!fl) {
                    for (int j = 0; j < n; ++j) {
                        arr_unique[j] = arr_new[j];
                    }
                    fl = 1;
                }
            }
        }
    }
}
