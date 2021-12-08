#include <iostream>
#include <compare>
#include <cassert>
#include <ranges>
#include <list>
#include <algorithm>
#include <vector>
#include <random>

class X {
private:
    int a;
public:
    X(int aa) : a(aa) {    }

    friend bool operator == (X l, X r) { return l.a == r.a; }
    friend bool operator!= (X l, X r) { return l.a != r.a; }
    friend bool operator>= (X l, X r) { return l.a >= r.a; }
    friend bool operator<= (X l, X r) { return l.a <= r.a; }
    friend bool operator< (X l, X r) { return l.a < r.a; }
    friend bool operator> (X l, X r) { return l.a > r.a; }


    friend bool operator>= (int l, X r) { return l >= r.a; }
    friend bool operator<= (int l, X r) { return l <= r.a; }


    auto operator<=>(const X&) const = default;
};


int main()
{
    std::cout << "Hello World!\n";
    X x1(1), x42{ 42 };
    std::cout << (x1 < x42 ? "x1 < 42" : "not x1 < 42") << std::endl;
    std::cout << (x1 > x42 ? "x1 > 42" : "not x1 > 42") << std::endl;
    std::cout << (x1 <= x42 ? "x1 <= 42" : "not x1 <= 42") << std::endl;
    std::cout << (x1 >= 42 ? "x1 >= 42" : "not x1 >= 42") << std::endl;
    std::cout << (x1 == x42 ? "x1 == 42" : "not x1 == 42") << std::endl;
    std::cout << (x1 != x42 ? "x1 != 42" : "not x1 != 42") << std::endl;
    std::cout << (100 < x42 ? "100 < 42" : "not 100 < 42") << std::endl;
    std::cout << (100 > x42 ? "100 > 42" : "not 100 > 42") << std::endl;
    std::cout << (42 == x42 ? "42 == 42" : "not 42 == 42") << std::endl;


    /*std::list<int> dt = { 1, 4, 2, 3 };
    std::ranges::sort(dt.begin(), dt.end());
    std::ranges::copy(dt.begin(), dt.end(),
        std::ostream_iterator<int>(std::cout, ","));*/

    std::vector<int> dt = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::ranges::shuffle(dt, std::mt19937(std::random_device()()));
    auto pos = std::ranges::find(dt.begin(),
        std::unreachable_sentinel,
        7);
    std::ranges::copy(dt.begin(), ++pos,
        std::ostream_iterator<int>(std::cout, ","));

    std::vector<int> dt1 = { 1, 4, 2, 3 };
    std::ranges::sort(dt1);
    auto pos1 = std::ranges::find(dt1.begin(), std::unreachable_sentinel, 4);
    std::ranges::copy(dt1.begin(), ++pos1,
        std::ostream_iterator<int>(std::cout, ","));
    std::ranges::copy(dt1.begin(), dt1.end(),
        std::ostream_iterator<int>(std::cout, ","));
    std::ranges::copy(dt1,
        std::ostream_iterator<int>(std::cout, ","));

    return 0;
}