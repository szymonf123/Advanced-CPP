#include <iostream>

template<int N>
struct Silnia {
    enum {
        val = N * Silnia<N - 1>::val
    };
};

template<>
struct Silnia<0> {
    enum {
        val = 1
    };
};

int main(){
    std::cout << Silnia<5>::val << std::endl;
    std::cout << Silnia<3>::val << std::endl;
}