#include <iostream>
#include <vector>
#include <string>

int Karatsuba(const std::string& first, const std::string& second){
    unsigned len = first.size() > second.size() ? first.size() : second.size();
    if (len <= 2){
        //return first * second;
    }
    std::string s1, s2, s3, s4;
    std::copy(first.begin(), first.begin() + len/2, std::inserter(s1, s1.begin()));
    std::copy(first.begin() + len/2, first.end(), std::inserter(s2, s2.begin()));
    std::copy(second.begin(), second.begin() + len/2, std::inserter(s3, s3.begin()));
    std::copy(second.begin() + len/2, second.end(), std::inserter(s4, s4.begin()));
    //std::vector<char> v = {}
}

int main() {
    std::string s1;
    std::string s2;
    std::cin >> s1 >> s2;
    Karatsuba(s1, s2);
    return 0;
}
