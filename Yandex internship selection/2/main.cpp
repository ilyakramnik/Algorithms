#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    int a[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    unordered_map<long long, int> s;
    s[0] = 1;
    long long cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += a[i] * (i % 2 == 0 ? -1 : 1);
        if (s.find(cur - x) != s.end()) {
            cout << "YES\n";
            return 0;
        }
        s[cur] = i+1;
    }
    cout << "NO\n";
    return 0;
}
