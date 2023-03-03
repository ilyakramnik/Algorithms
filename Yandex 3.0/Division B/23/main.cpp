#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n+1);
    std::vector<int> ans;
    arr[1] = 0;
    for (int i=2; i<n+1; ++i){
        int div2 = 1000000, div3 = 10000000;
        if (i % 2 == 0){
            div2 = arr[i/2];
        }
        if (i % 3 == 0){
            div3 = arr[i/3];
        }
        arr[i] = std::min(std::min(arr[i-1], div2), div3) + 1;
    }
    std::cout << arr[n]<<'\n';
    int k = arr[n];
    for (int i = n; i>0; --i) {
        if (arr[i] == k) {
            ans.push_back(i);
            --k;
        }
    }
    for (int i=static_cast<int>(ans.size())-1; i>=0; --i){
        std::cout<<ans[i]<<' ';
    }
}