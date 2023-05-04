#include <iostream>
#include <cmath>

template<long N>
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

template <long N>
inline double Sin(double x){
    return Sin<N - 1>(x) + pow(-1, N + 1) * pow(x, 2 * N + 1) / Silnia<2 * N - 1>::val;
}

template <>
inline double Sin<0>(double x){
    return 0.0;
}

int main(){
    std::cout << "sin<2>(TT) = " << Sin<2>(M_PI) << std::endl;
    std::cout << "sin<5>(TT) = " << Sin<5>(M_PI) << std::endl;
    std::cout << "sin<5>(TT/2) = " << Sin<5>(M_PI / 2) << std::endl;
}