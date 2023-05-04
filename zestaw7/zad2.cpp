#include <iostream>

template<int N, int M> struct Pow {
    enum {
        val = N * Pow<N, M - 1>::val
    };
};

template<int N> struct Pow<N, 0> {
    enum {
        val = 1
    };
};

int main(){
    std::cout << Pow<2, 5>::val << std::endl;
    std::cout << Pow<-2, 9>::val << std::endl;
}