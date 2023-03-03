#include <iostream>
#include <cmath>
#include <map>

void primes(int num, std::map<int, int> &dict, int flag) {
    if (num == 1) {
        dict[num] = 1;
        return;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        while (num % i == 0) {
            if (flag == 0) {
                ++dict[i];
            } else {
                --dict[i];
            }
            num /= i;
        }
    }
    if (num != 1) {
        if (flag == 0) {
            ++dict[num];
        } else {
            --dict[num];
        }
    }
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int a, b, max_prime_a = 1;
    std::cin >> a >> b;
    std::map<int, int> dict;
    primes(a, dict, 0);
    primes(b, dict, 1);

    auto x = dict.end();
    --x;
    while (x != dict.begin()) {
        if (((x->first <= b && x->second > 0) || x->first > b) ||
            ((x->first <= a && x->second < 0) || x->first > a)) {
            max_prime_a = x->first;
            break;
        }
        --x;
    }
    if (((x->first <= b && x->second > 0) || x->first > b) ||
        ((x->first <= a && x->second < 0) || x->first > a)) {
        max_prime_a = x->first;
    }

    std::cout << gcd(a, b) * max_prime_a;
}