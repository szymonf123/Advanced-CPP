#include <iostream>

template <int N>
inline double pow(double x){
    return x * pow<N - 1>(x);
}

template <>
inline double pow<0>(double x){
    return 1.0;
}

int main(){
    std::cout << "2^7 = " << pow<7>(2) << std::endl;
    std::cout << "4.12^2 = " << pow<2>(4.12) << std::endl;
}